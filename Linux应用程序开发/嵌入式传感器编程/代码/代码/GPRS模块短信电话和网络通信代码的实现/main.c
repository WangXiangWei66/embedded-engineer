#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define dbgOut(args...) \
do{ \
	char b__[1024]; \
	sprintf(b__,args); \
	fprintf(stdout,"[%s, %s, %d] %s", __FILE__, __FUNCTION__,__LINE__,b__); \
}while(0)

//通过宏定义 定义串口的文件名
#define COM2 "/dev/ttySAC5"

typedef unsigned char uchar;

/*
 * @brief 初始化串口
 * @param file 串口所对应的设备文件名
 * @param baudrate 串口的波特率
 * @return 成功返回串口所对应的文件描述符，失败返回-1
 * */
int init_serial(const char *file, int baudrate)
{
    int fd;

    fd = open(file, O_RDWR);
    if (fd == -1)
    {
        perror("open device error:");
        return -1;
    }

    struct termios myserial;
    //清空结构体
    memset(&myserial, 0, sizeof (myserial));
    //O_RDWR
    myserial.c_cflag |= (CLOCAL | CREAD);
    //设置控制模式状态，本地连接，接受使能
    //设置 数据位
    myserial.c_cflag &= ~CSIZE;   //清空数据位
    myserial.c_cflag &= ~CRTSCTS; //无硬件流控制
    myserial.c_cflag |= CS8;      //数据位:8

    myserial.c_cflag &= ~CSTOPB;//   //1位停止位
    myserial.c_cflag &= ~PARENB;  //不要校验

    switch (baudrate)
    {
        case 2400:
            cfsetospeed(&myserial, B2400);  //设置波特率
            cfsetispeed(&myserial, B2400);
            break;
        case 9600:
            cfsetospeed(&myserial, B9600);  //设置波特率
            cfsetispeed(&myserial, B9600);
            break;
        case 115200:
            cfsetospeed(&myserial, B115200);  //设置波特率
            cfsetispeed(&myserial, B115200);
            break;
        case 19200:
            cfsetospeed(&myserial, B19200);  //设置波特率
            cfsetispeed(&myserial, B19200);
            break;
    }

    /* 刷新输出队列,清除正接受的数据 */
    tcflush(fd, TCIFLUSH);

    /* 改变配置 */
    tcsetattr(fd, TCSANOW, &myserial);

    return fd;
}

#define MSG 1
#define TEL 2
#define TCP 3
#define UDP 4

//发送短信功能
void send_msg(int fd)
{
    dbgOut("send_msg.....\n");
    char cmds[3] = {"AT+CMGF=1\r\n", "AT+CSCS=\"GSM\"", "AT+CMGS=\"19118977767\""};

    //通过开发板的串口向GPRS模块发送AT指令
    int i;
    for (i = 0; i < 3; i++)
    {
        write(fd, cmds[i], strlen(cmds[i]));
        usleep(500000); //延时500ms
    }

    //通过GPRS模块向对应的手机号发送hello
    write(fd, "hello", 5);
    usleep(500000); //延时500ms

    //发送16进制的0x1A
    char cmd = 0x1A;
    write(fd, &cmd, 1);

}

//向指定的手机拨打电话
void telphone(int fd, const char *tel)
{
    dbgOut("telphone....\n");
    char cmd[64];
    //数组中的所有的字符设置为\0,因为我们希望将这个字符数组中的内容当作字符串来处理
    memset(cmd, 0, sizeof(cmd));

    sprintf(cmd, "ATD%s;\r\n", tel);

    write(fd, cmd, strlen(cmd));

    sleep(3);

    //自动挂断电话
    write(fd, "ATH\r\n", 5);
}

/*
 * @brief 通过串口操作GPRS模块进行网络通信
 * @param fd 操作的串口的文件描述符
 * @param type 网络传输协议：TCP UDP
 * @param ip 服务器的IP地址
 * @param port 服务器的端口号
 * */
void NetTrans(int fd, const char *type, const char *ip, const char *port)
{
    dbgOut("network Transport： %s\n", type);

    char cmds[2] = {"AT+CPIN?\r\n", "AT+CREG?\r\n"};

    //通过开发板的串口向GPRS模块发送AT指令
    int i;
    for (i = 0; i < 2; i++)
    {
        write(fd, cmds[i], strlen(cmds[i]));
        usleep(500000); //延时500ms
    }

    char cmd[100];
    memset(cmd, 0, sizeof(cmd));

    sprintf(cmd, "AT+QIOPEN=\"%s\", \"%s\", \"%s\"\r\n", type, ip, port);
    write(fd, cmd, strlen(cmd));

    usleep(500000); //延时500ms

    //向tcp服务器发送数据
    write(fd, "AT+QISEND\r\n", 11);
    write(fd, "hello", 5);
    //发送16进制的0x1A
    char cmd2 = 0x1A;
    write(fd, &cmd2, 1);

    //读取服务器响应的数据
    char buf[32];
    memset(buf, 0, sizeof(buf));
    int ret = read(fd, buf, sizeof(buf));
    dbgOut("read from server: %s\n", buf);

    //断开与TCP服务器的连接
    write(fd, "AT+QICLOSE\r\n", 12);
}

int main() {
    //对串口进行初始化
    int fd;
    fd = init_serial(COM2, 9600);
    if (-1 == fd)
    {
        dbgOut("open COM2 error !\n");
        return 0;
    }

    while (1)
    {
        //从键盘上输入数字 表示不同的功能
        //1: 发短信   2: 打电话  3：使用TCP通信  4：使用UDP通信
        int func;
        printf("plz input A numer: 1: 发短信   2: 打电话  3：使用TCP通信  4：使用UDP通信\n");

        scanf("%d", &func);
        switch (func)
        {
            case MSG:
                send_msg(fd);
                break;
            case TEL:
                telphone(fd, "19118977768");
                break;
            case TCP:
                NetTrans(fd, "TCP", "47.104.157.132", "8889");
                break;
            case UDP:
                NetTrans(fd, "UDP", "47.104.157.132", "9999");
                break;
            default:
                break;
        }
    }

    return 0;
}