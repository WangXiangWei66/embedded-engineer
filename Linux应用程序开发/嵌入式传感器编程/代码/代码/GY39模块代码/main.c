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
        //发送命令给GY39模块
        char cmd[3] = {0xA5, 0x52, 0xF7};
        write(fd, cmd, 3);

        //接收GY39模块回复的数据
        char buf[15];
        int ret;
        ret = read(fd, buf, 15);
        if (ret != 15)
        {
            dbgOut("frame too short: %d\n", ret);
            continue;
        }

        //判断数据报是否准确
        //判断帧头是否准确
        if (!(buf[0]==0x5A && buf[1] == 0x5A))
        {
            dbgOut("Frame header error !\n");
            continue;
        }
        //判断数据类型是否准确
        if (buf[2] != 0x45)
        {
            dbgOut("data type error !\n");
            continue;
        }
        //判断校验是否准确：首先将接收到的数据按照校验算法求得一个校验值， 那求得的校验值和接收到的校验值进行比较
        int sum = 0;
        char check = 0;
        int i;
        for (i = 0; i < 14; i++)
        {
            sum += buf[i];
        }
        check = sum & 0xFF; //求sum的低八位
        if (check != buf[14])
        {
            dbgOut("check error !\n");
            continue;
        }
        //解析GY39模块回复的数据 获取温度 湿度 气压 海拔
        float temp, atmos, hum;
        short haiba;

        temp = (buf[4]<<8 | buf[5]) / 100.0;

        atmos = (buf[6]<<24 | buf[7]<<16 | buf[8]<<8 | buf[9]) / 100.0;

        hum = (buf[10]<<8 | buf[11]) / 100.0;

        haiba = (buf[12]<<8 | buf[13]);

        dbgOut("temp: %.2f, atmos: %.2f, hum: %.2f, haiba: %d\n", temp, atmos, hum, haiba);
        
        //延时
        usleep(200000);
    }
    return 0;
}