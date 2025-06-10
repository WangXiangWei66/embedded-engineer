#include <iostream>
using namespace std;
int main()
{
  /*
  编译的时候会给出很多 waning，因为
   * 1. 使用未初始化的变量
   * 2. 将过大的数字保存为 int，很可能会出问题
   * 所以编译器对我们发出了警告
   * 但我们的目的就是为了测试验证，所以可以忽略警告
  */
  // 输出的内容不可预期，可能是0，也可能是乱七八糟的数字
  int underfined;
  cout << "underfined:" << underfined << endl;
  int normal = 5;
  cout << "normal :" << normal << endl;
  int negative = -10;
  cout << "negative :" << negative << endl;
  //过大的数字，int装不下
  int tooBig = 12345678901;
  cout << "tooBig" << tooBig << endl;

  int intMax = 2147483647;
  cout << "intMax :" << intMax << endl;
  int intMaxPlus = 2147483648;
  cout << "intMax + 1:" << intMaxPlus << endl;

  int a = 1, b, c = 2, d, e = 3;
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
}