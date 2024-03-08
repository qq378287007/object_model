#include <iostream>
using namespace std;

struct A
{
	int m_i;
	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }
};

void myfunc()
{
	// A obja; // 这里定义不合适
	if (1 == 1)
	{
		// 这里会被编译器插入调用obja对象析构函数的代码，影响执行效率完全没必要
		return;
	}

	A obja; // 这里定义合适
	obja.m_i = 10;
	cout << "obja.m_i = " << obja.m_i << endl;
	return;
}

A g_aobj;

int main()
{

	{
		A obja;
		int mytest = 1;
		if (mytest == 0)
			return 0;
		myfunc();
	}

	g_aobj.m_i = 6; //

	cout << "Over!\n";
	return 0;
}
