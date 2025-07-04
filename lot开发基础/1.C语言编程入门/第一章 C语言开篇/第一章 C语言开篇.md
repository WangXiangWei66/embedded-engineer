## 1.1 计算机组成

1946年2月14日，由美国军方定制的世界上第一台电子计算机“电子数字积分计算机”（ENIAC
Electronic Numerical And Calculator）在美国宾夕法尼亚大学问世。

计算机（俗称电脑）堪称是人类智慧的结晶，随着计算机的不断发展，各行各业的正常运转基本都
离不开计算机，计算机为人们的日常生活带来了快捷和方便。那么作为一个时时刻刻都在跟计算机打交
道的“程序猿”，对计算机又了解多少呢？下面让我们一起来学习计算机的组成及工作原理吧。

### 计算机由硬件系统和软件系统所组成。

硬件系统由**运算器、控制器、存储器、输入设备、输出设备**5大部件组成

* 运算器（Datapath）
  运算器的功能是对数据进行各种**算术运算和逻辑运算**，即对数据进行加工处理。
* 控制器（Control）
  是整个计算机的中枢神经，其功能是对程序规定的控制信息进行解释，根据其要求进行控制，调度
  程序、数据、地址，协调计算机各部分工作及内存与外设的访问等

```
运算器和控制器都集成在一颗称之为CPU的中央处理单元芯片上：
```

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/59c33d25e7c14248bcc254ae889d546f.png)

* 存储器（Memory）
  存储器是计算机系统中的记忆设备，用来存放**程序和数据**。计算机中全部信息，包括输入的原始数
  据、计算机程序、中间运行结果和最终运行结果都保存在存储器中。**存储器分为内存和外存**。

**内存：**

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/4eef497f4a0a459fa92add97be33d249.png)

**外存：**

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/eef972b8d2a24577befa6cb6374adf1e.png)

* 输入设备
  输入设备是计算机的重要组成部分，输入设备与输出设备合称为外部设备，简称外设，输入设备的
  作用是将程序、原始数据、文字、字符、控制命令或现场采集的数据等信息输入到计算机。常见的
  输入设备有键盘、鼠标、磁带机、磁盘机、光盘机等。

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/de50a1f9fc8a458b879f07360e7b6e12.png)
* 输出设备
  输出设备与输入设备同样是计算机的重要组成部分，它把计算机的中间结果或最后结果、机内的各
  种数据符号及文字或各种控制信号等信息输出出来。常用的输出设备有**显示器、打印机、磁带、光
  盘机等**

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/f8d239e48f6d4e9db770e212e2b0c038.png)

软件系统
软件系统可以分为：**系统软件和应用软件**

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/8394bc02e3ed49479272a9cd65676643.png)

## 1.2 计算机语言

1、软件(程序)是指令的集合

2、程序就是用计算机语言来编写或者开发的。

3、计算机语言总的来说分为**机器语言，汇编语言，高级语言**三大类，而这三种语言也恰恰是计算机语
言发展历史的三个阶段。

* 1946年2月14日，世界上第一台计算机ENAC诞生，使用的是最原始的穿孔卡片。这种卡片上使用
  的语言是只有专家才能理解的语言，与人类语言差别极大，这种语言就称为机器语言（使用**0和1**的二进制码）。机器语言是第一代计算机语言。这种语言本质上是计算机能识别的唯一语言，人类
  很难理解。以后的语言就是在这个的基础上简化而来。
* 计算机语言发展到第二代，出现了汇编语言。汇编语言用助记符代替了操作码，用地址符号或标号
  代替地址码。这样就用符号代替了机器语言的二进制码。汇编语言也称为符号语言。
* 当计算机语言发展到第三代时，就进入了“面向人类”的高级语言。高级语言是一种接近于人们使用
  习惯的程序设计语言。它允许用英文写计算程序，程序中的符号和算式也与日常用的数学式子差不
  多。
* 计算机语言发展到今天可以说几乎是形成了“百家争鸣”的局面。

## 1.3 C语言发展历史及特点

1、1972年，美国 AT&T 公司贝尔实验室（AT&T Bell Laboratory）的**丹尼斯·里奇**为了开发Unix操作
系统在B语言的基础上最终设计出了一种新的语言，他以 BCPL 的第二个字母作为这种语言的名字，即C

语言。

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/109b8c46b9d34f0c928db7028f8b97ac.png)

2、1970到80年代，C语⾔被⼴泛应⽤，从⼤型主机到⼩型微机，从中也衍⽣了C语⾔的很多不同版本。

为统⼀C语⾔版本，1983年ANSI 美国国家标准学会（ American National Standards Institute）成立
了⼀个委员会来制定C语⾔标准。1989年C语⾔标准被批准，这个版本的C语⾔标准通常被称为**ANSI
C**。⼜由于这个版本是 89 年完成制定的，因此也被称为 C89。后来 ANSI 把这个标准提交到 ISO，1990

年被 ISO 采纳为国际标准，称为 ISOC。⼜因为这个版本是1990年发布的，因此也被称为C90。

3、C语言发展时间轴

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/acaa726866db4bbd838a791692e2e110.png)

## 1.4 C语言的应用

1、C语⾔应⽤场景

* 系统软件开发
  操作系统：UNIX、Windows、Linux。

  驱动程序：比如主板驱动、显卡驱动、摄像头驱动。驱动一般是用C语言和汇编语言写的，C++在这方面稍弱。
  数据库：SQL Server、Oracle、MySQL、DB2。
* 应用软件开发

```
办公软件：WPS。
	图形图像多媒体：Photoshop、Mediaplayer。
	嵌入式软件开发：在嵌入式平台（比如：路由器、导航仪、机顶盒、手机、工控设备、汽车
	电子等）上进行的应用软件开发。
	游戏开发：2D、3D 游戏。CS 整个游戏的引擎全部是用纯C写的
```

2、C语言在所有编程语言中的江湖地位

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/daaef3e247184f9680ef00a222eb0b6e.png)

## 1.5 手把手教你搭建C语言开发环境

Jetbrains旗下产品之一，主要用来开发C/C++.

1. CLion的安装

- CLion下载

```
windows版本下载地址：https://www.jetbrains.com/clion/download/#section=windows
macOS版本下载地址：https://www.jetbrains.com/clion/download/#section=mac
Linux版本下载地址：https://www.jetbrains.com/clion/download/#section=linux
```

- 安装
  双击下载的安装包

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/8f1306ad56424979bb19ec3eccc1298f.png)
- 点击运行开始安装

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/59263231a7074909b54233ecaf98b444.png)
- 点击“Next”进入下一步

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/fb1bb5b0b2184adaa96e1b3a01cf9c07.png)
- 选择CLion的安装路径，注意：不要选择带中文的路径，点击“Next”进入下一步

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/f2a1954786a7499f83b38a5407b7d4fa.png)
- 勾选所有选项，然后点击“Next”进入下一步

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/c764ed61cb954f4fbd02d93bed7af821.png)
- 点击“Install”

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/649f212b0b0b42fa8f89ff2cac3559e0.png)
- 耐心等待

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/c60e16838ea9458a9158026f819905d7.png)
- 勾选“I want to manually reboot later”，点击"Finish"完成安装

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/9f6adc9690ca40448b13a6fc97e9f2dc.png)
- 安装完毕后，回到电脑桌面，运行程序

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/b7904c2f62d346aa9cfae07966273597.png)
- 选择“Do not import settings”然后点击“OK”

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/391e3f791397425fae3fbfabe91bd424.png)
- CLion是需要付费的，但是我们可以选择免费使用30天

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/4cb411a48adb4c7fa0cf2d76d5698dfc.png)
- 点击“Continue”

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/91b1774263f749cdbf25a060b48ee78c.png)

2. MinGW的安装

- CLion虽然已经安装完毕，但是还不具备程序编译和调试功能
- 下载MinGW：MinGW-w64 - for 32 and 64 bit Windows - Browse /Toolchains targetting
  Win64/Personal Builds/mingw-builds at SourceForge.net
- 大家也可以直接使用工具包中的“x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.zip”

  ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/1f1799bbd0884288a470249c443a0b83.png)

注意：千万不要点绿色按钮去下载！！！

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/c764f0016eaa4e19a54af44fb88a13b8.png)

往下拉，一直拉到下面的界面，然后点击”x86_64-posix-sjlj“就可以下载压缩包了。

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/233329401aaf41d4807bbf700080013a.png)

安装包下载完后，拷贝至C盘并且解压

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/98c97b9b3ab54640903a0a3045d1950c.png)

3. 配置CLion

打开CLion后鼠标点击"Customize"，然后点击”All settings“进入设置界面

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/70c74c90455b47a884e5a0debab5cf0b.png)

在设计界面搜索栏输入”toolchains“搜索工具链选项，然后点击”+“，并且选择”MinGW“

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/949e664c7d534b6fbe95b1f51acb21d2.png)

在”Environment“栏填入刚刚解压的MinGW64的路径，然后CLion会自动帮你填上所有你该
填的东西，点击OK，等调试的小虫子变绿就可以了。

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/02479e57d26c41c4a5308b2860180ded.png)

当然，也会出现无法检测成功的情况，这时候就需要手动填写啦。

Make填入路径：

```C:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\mingw32-make.exe
C:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\mingw32-make.exe
```

C Compiler填入路径：

```
C:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe
注意：gcc.exe就是用来编译C语言程序的编译器
```

C++ Compiler填入路径：

```
C:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe

注意：g++.exe是用来编译C++程序的编译器
```

Debugger一般会自己填入，如果没有可以手动填：

```
C:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gdb.exe

注意：gdb.exe是用来调试C/C++程序的调试工具
```

然后点击OK，等一段时间就可以了。

4. 使用CLion创建C语言项目
   点击”New Project“

   ![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/800edee06aa14624a3a4971f5e51c3e1.png)

选择”C Executable“，然后在”Location“选项中点击右侧的文件夹图标选择项目需要创建的路
径，然后给项目命名，在这里我给项目命名为”test“，最后点击”Create“

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/de4192fbbb304bceb4ea888157423234.png)

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/66337df2aab241568e5ba9caae548bd4.png)

## 1.6 第一个C语言程序

```
 #include <stdio.h>

int main(){

 printf("hello world\n");

 return 0;

 }
```

下面我们一起来看看这个简单的C语言程序包含了哪些内容？

1. 程序的第1⾏#include 是预处理器指令，告诉 C 编译器在实际编译之前要包含stdio.h这个头⽂件。
2. 第2⾏int main()是主函数，程序从这⾥开始执⾏，最后也从这里结束。main函数是C程序的入
   口和出口。
3. 第3行是调用C语言中的printf函数，其功能是将“hello world”显示在屏幕上。
4. 第5行return 0表示主函数返回0，结束主函数的执行（主函数执行完毕则代表程序运行结束
   啦）。

## 1.7 程序的编译及运行

1、**计算机只识别二进制0和1**：计算机都是大规模集成电路机，是采用大规模和超大规模的集成电路作
为逻辑元件的。电路的状态只有通和断两种情况，也叫**高电平**和**低电平**，计算机用1和0描述这两种状态

2、用c语言编写的代码是不能够直接运行的，需要转换成计算机所识别的二进制代码，这个转换过程我
们称之为”编译器“
3、编译器是一个可执行程序：你还记得配置CLion时选择的”gcc.exe“文件吗？

4、使用CLion编译和运行C程序
点击CLion菜单栏中”Build“，然后在弹出的选项中点击”Build test“编译程序

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/8ac38ee08a5641f099cc09428b5984d8.png)

点击CLion菜单栏中的”Run“，然后再弹出的选项中点击“Run test”运行程序

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/2db32f1872f3411c91abdc79ef240b5a.png)

程序运行结果

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/58551/1751630020068/1b14cf83862946528c0d75480bc222e3.png)

5、注意：为了避免有些同学从入门到放弃，关于C程序编译的详细步骤和原理我们放到后面做专题进行
讲解。学习是一件循序渐进的事情，等到大家经过一段时间的学习对C语言比较熟悉后我们再讲解这些
深奥的知识点时，大家才能够更好的可理解和掌握，这样才能够真正的融会贯通。

## 1.8 C程序的注释

1. C语言中有两种注释方式，分别为：

- 单行注释

以 // 开始、以换行符结束的单行注释

```
//这是单行注释
```

- 多行注释

以 /* 开始、以 */ 结束的块注释

```
/*
	这是第一行注释
	这是第二行注释
*/
```

2. 注释的使用注意事项
   多行注释尽量写在被注释的语句之上，例如:
   ```
   /*
   这是第一行注释
   这是第二行注释
   */
   printf("我是一条被注释的可执行语句^_^")
   ```

```
单行注释可以写在被注释的语句之上，也可以写在被注释的语句之后，例如:
```

```
//单行注释在上面
printf("我是一条被注释的可执行语句^_^"); //单行注释在后面
```

但是！但是！但是！如果你以后是在银行的操作系统上进行C语言程序开发，请一定一定一定
要将单行注释写在被注释的语句之上！因为银行使用的是AIX操作系统（类Unix操作系
统），该操作系统上的C语言编译器不支持将注释写在后面这种语法！
