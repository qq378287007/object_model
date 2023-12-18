#include <iostream>
#include <time.h>
using namespace std;

class A
{
public:
	int i;					   // 一个成员变量，4字节
	virtual void testfunc() {} // 虚函数
};

int main()
{
	A a;
	int ilen = sizeof(a); // 8：i占4字节, 虚函数表指针占4字节（皆在x86平台下）

	char *p1 = reinterpret_cast<char *>(&a);	 // 0x006ff730 类型转换，这属于硬转，a是对象首地址
	char *p2 = reinterpret_cast<char *>(&(a.i)); // 0x006ff734
	if (p1 == p2)								 // 说明a.i和a位置相同，则成员变量i在a对象内存的上面位置，那么虚函数表指针在下面位置
	{
		cout << "虚函数表指针位于对象内存的末尾" << endl;
	}
	else
	{
		cout << "虚函数表指针位于对象内存的开头" << endl; // 本条件会成立
	}

	cout << "Over!\n";
	return 0;
}