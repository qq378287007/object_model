#include <cstdio>
#include <iostream>
using namespace std;

struct A
{
	int m_i;
	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }

	A(const A &tmp)
	{
		m_i = tmp.m_i;
		cout << "A::A(const A&)" << endl;
	}
	A &operator=(const A &tmp)
	{
		m_i = tmp.m_i;
		cout << "A::operaotor=(const A&)" << endl;
		// printf("&tmp=%p\n", &tmp);
		return *this;
	}
};
A operator+(const A &obj1, const A &obj2)
{
	// cout << "A operaotor+(const A&, const A &)" << endl;

	A tmp; // 一次构造函数
	tmp.m_i = obj1.m_i + obj2.m_i;

	printf("&tmp=%p\n", &tmp);
	return tmp; // 一次拷贝构造函数+一次析构函数(编译器优化后可能无临时对象)
}

int main()
{
	if (0)
	{
		A myobj1;
		printf("&myobj1=%p\n", &myobj1);

		A myobj2;
		printf("&myobj2=%p\n", &myobj2);

		A resultobj1 = myobj1 + myobj2; // 编译器优化后直接将tmp的地址用作resultobj1的地址，节省一次复制构造+一次析构
		cout << "------------------------\n";
		printf("&resultobj1=%p\n", &resultobj1);
	}

	if (0)
	{
		A myobj1;
		printf("&myobj1=%p\n", &myobj1);

		A myobj2;
		printf("&myobj2=%p\n", &myobj2);

		A resultobj2;

		resultobj2 = myobj1 + myobj2; // 一次构造函数+一次拷贝赋值运算符+一次析构
		cout << "------------------------\n";
		printf("&resultobj2=%p\n", &resultobj2);
	}
	if (0)
	{
		A myobj1;
		A myobj2;
		myobj1 + myobj2;
	}

	if (0)
	{
		A myobj1;
		myobj1.m_i = 1;

		A myobj2;
		myobj2.m_i = 2;

		printf("(myobj1 + myobj2).m_i = %d\n", (myobj1 + myobj2).m_i); // 临时对象(operator+，一次构造+一次析构，且析构在printf后执行)
	}
	if (0)
	{
		A myobj1;
		myobj1.m_i = 1;

		A myobj2;
		myobj2.m_i = 2;

		if ((myobj1 + myobj1).m_i > 3 || (myobj1 + myobj2).m_i > 5) // 两个临时对象
			cout << "Condition established" << endl;
		else
			cout << "Condition not established" << endl;
	}
	if (1)
	{
		A myobj1;
		myobj1.m_i = 1;

		A myobj2;
		myobj2.m_i = 2;

		if ((myobj1 + myobj1).m_i > 1 || (myobj1 + myobj2).m_i > 5) // 一个临时对象
			cout << "Condition established" << endl;
	}

	if (0)
	{
		const char *p = (string("123") + string("456")).c_str(); // error，临时对象被摧毁了
		printf("p = %s\n", p);

		string aaa = string("123") + string("456");
		const char *q = aaa.c_str(); // ok
		printf("q = %s\n", q);
	}

	if (0)
	{
		const string &aaa2 = string("123") + string("456");
		printf("aaa2 = %s\n", aaa2.c_str());
	}

	cout << "Over!\n";
	return 0;
}
