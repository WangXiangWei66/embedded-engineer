#include <iostream>
//<format>头文件是 C++20 引入的，
//主要用于格式化输出和解析字符串，它提供了std::format等函数
//使得字符串格式化操作更加方便和类型安全
#include <format>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  printf("%d + %d = %d\n", a, b, a + b);
  cout << a << "+" << b << "=" << a + b << endl;
  cout << format("{} + {} = {}", a, b, a + b) << endl;
}