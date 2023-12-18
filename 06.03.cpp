#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行了" << endl;
	}
	int m_i;
};

void myfunc()
{
	A obja; // obja定义在这里并不合适
	if (1 == 1)
	{
		// 这里会被编译器插入调用obja对象析构函数的代码，影响执行效率完全没必要
		return;
	}
	// A obja; //obja定义在这里才合适
	// 这里才会用到obja对象，所以obja对象定义在这里才会合适
	obja.m_i = 10;
	cout << "obja.m_i的值为" << obja.m_i << endl;
	return;
}

A g_aobj;

int main()
{
	/*{
		A obja;
	}*/
	//{
	//	A obja;
	//	int mytest = 1;
	//	if (mytest == 0)
	//	{
	//		return 0;
	//	}
	//	//myfunc();
	//}

	g_aobj.m_i = 6; // 没有问题

	cout << "Over!\n";
	return 0;
}
