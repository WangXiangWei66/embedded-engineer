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
        unsigned char cmd = 0x55;
        //发送0x55
        write(fd, &cmd, 1); //向串口文件中写入数据
        //接收超声波测距模块返回的数据
        unsigned char buf[2];
        read(fd, buf, 2);
        //解析数据计算距离
        unsigned short dis;
        dis = buf[0]<<8 | buf[1];

        dbgOut("dis: %d\n", dis);

        usleep(200000); //
    }

    return 0;
}
