#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

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

uchar getCheck(uchar *data, int len)
{
    unsigned int sum = 0;
    int i;
    for (i = 0; i < len; i++)
        sum += data[i];

    return sum & 0xFF;
}

int main() {
    //初始化串口
    int fd;
    fd = init_serial(COM2, 9600);
    if (-1 == fd)
    {
        printf("init com2 error!\n");
        return 0;
    }

    while (1)
    {
        //通过串口向烟雾传感器发送一个命令
        uchar cmd[] = {0xFF, 0x01, 0x86, 0, 0, 0, 0, 0,0x79};
        write(fd, cmd, sizeof(cmd));

        //接收传感器回复的数据
        uchar buf[9]; //接收数据的数组
        int ret = read(fd, buf, sizeof(buf));

        printf("ret: %d\n", ret);
        if (ret ==0 )
        {
            usleep(500000);
            continue;
        }

        //判断传感器发送的数据包/数据帧是否正确
        //1、判断起始位和命令是否正确
        if (!(buf[0]==0xFF && buf[1]==0x86))
        {
            printf("Frame head error !\n");
            usleep(500000);
            continue;
        }
        //2、判断校验值是否正确
        uchar check;
        check = getCheck(buf+1, 7);
        if (check != buf[8]) //如果计算出来的校验值和接收到的校验值不等说明这个数据包时有问题的
        {
            printf("check error !\n");
            usleep(500000);
            continue;
        }

        //解析传感器回复的数据获取到可燃气体的浓度值
        unsigned short value;
        value = buf[2]<<8 | buf[3];
        printf("value: %d\n", value);

        //休眠一段时间
        usleep(200000); //200ms
    }


    return 0;
}
