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

//发送的命令数组
char cmdArry[5][5] = {{0xA1, 0x00, 0xA0, 0xA2, 0xA3},
                      {0xA3, 0x00, 0xA2, 0xA4, 0xA5},
                      {0xAA, 0x00, 0xA9, 0xAB, 0xA8},
                      {0xAB, 0x00, 0xAA, 0xAC, 0xAD},
                      {0xAC, 0x00, 0xAB, 0xAD, 0xAA}};

enum FUNC
{
    GETAD = 1,
    GETWEIGHT,
    Calibration,
    RevmovePeel,
    CanclePeel
};

//指针数组存储提示消息
char *msgArry[5] = {NULL,
                    "get AD",
                    "get weight",
                    "calibration",
                    "remove peel",
                    "cancel remove peel"};

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

//获取AD值
void getAD(int fd)
{
    char cmd[] = {0xA1, 0x00, 0xA0, 0xA2, 0xA3};
    //发送命令
    write(fd, cmd, sizeof(cmd));
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    dbgOut("AD value: %d\n", value);
}

//获取实际重量
void getWeight(int fd)
{
    char cmd[] = {0xA3, 0x00, 0xA2, 0xA4, 0xA5};
    //发送命令
    write(fd, cmd, sizeof(cmd));
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (cmd[0]!=0xA1)
    {
        if (buf[3])
            value *= -1;
    }

    dbgOut("weight: %d\n", value);
}

//零点校准
void calibration(int fd)
{
    char cmd[] = {0xAA, 0x00, 0xA9, 0xAB, 0xA8};
    //发送命令
    write(fd, cmd, sizeof(cmd));
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (buf[3])
        value *= -1;
    dbgOut("calibration value: %d\n", value);
}

//去皮
void remove_peel(int fd)
{
    char cmd[] = {0xAB, 0x00, 0xAA, 0xAC, 0xAD};
    //发送命令
    write(fd, cmd, sizeof(cmd));
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (buf[3])
        value *= -1;
    dbgOut("remove_peel value: %d\n", value);
}

//取消去皮
void CancleRemovePeel(int fd)
{
    char cmd[] = {0xAC, 0x00, 0xAB, 0xAD, 0xAA};
    //发送命令
    write(fd, cmd, sizeof(cmd));
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (buf[3])
        value *= -1;
    dbgOut("CancleRemovePeel value: %d\n", value);
}

void handleFunc(int fd, char *cmd)
{
   // char cmd[] = {0xAC, 0x00, 0xAB, 0xAD, 0xAA};
    //发送命令
    write(fd, cmd, 5);
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (cmd[0]!=0xA1)
    {
        if (buf[3])
            value *= -1;
    }
    dbgOut("value: %d\n", value);
}

void handleFunc1(int fd, int func)
{
    /*
    switch (func)
    {
        case GETAD:
            dbgOut("get AD \n");
            break;
        case GETWEIGHT:
            dbgOut("get Weight\n");
            break;
    }
     */

    dbgOut("%s\n", msgArry[func]);
    // char cmd[] = {0xAC, 0x00, 0xAB, 0xAD, 0xAA};
    //发送命令
    write(fd, cmdArry[func-1], 5);
    //接收电子秤的返回数据
    char buf[10];
    int ret;
    ret = read(fd, buf, 10);
    if (ret != 10)
    {
        dbgOut("data too short: %d\n", ret);
        return ;
    }
    if (!(buf[0]==0xAA && buf[9]==0xFF))
    {
        dbgOut("frame header of tail error !\n");
        return ;
    }
    int value;

    value =  buf[4]<<16 | buf[5]<<8 | buf[6];
    if (func!= GETAD)
    {
        if (buf[3])
            value *= -1;
    }
    dbgOut("value: %d\n", value);
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
        //捕获键盘上所输入的数字（用不同的数字代表需要执行不同的操作）
        // 1：获取AD值   2: 获取实际重量   3：校准  4：去皮  5：取消去皮
        int func;
        scanf("%d", &func);

        /*
        //发送对应的命令
        switch (func)
        {
            case 1:
                //getAD(fd);
                handleFunc(fd, cmdArry[0]);
                break;
            case 2:
                handleFunc(fd, cmdArry[1]);
                break;
            case 3:
                break;
        }
        //解析电子秤返回的数据
        */
        if (func >= 0 && func <= 5)
        {
            handleFunc(fd, cmdArry[func-1]);

            handleFunc1(fd, func);
        }
    }

    return 0;
}