#include <iostream>
#include <time.h>
using namespace std;

struct X1
{
	int m_i;
	X1(const X1 &tmpx)
	{
		m_i = tmpx.m_i;
		cout << "X1::X1(const X1 &)" << endl;
	}

	X1()
	{
		m_i = 0;
		cout << "X1::X1()" << endl;
	}
	~X1()
	{
		cout << "X1::~X1()" << endl;
	}

	// explicit X(int value) :m_i(value)
	X1(int value) : m_i(value) // 类型转换构造函数（带有一个形参的拷贝构造函数）
	{
		cout << "X1::X1(int)" << endl;
	}
};

struct X2
{
	int m_i;
	X2(const X1 &tmpx)
	{
		m_i = tmpx.m_i;
		cout << "X2::X2(const X1 &)" << endl;
	}

	X2()
	{
		m_i = 0;
		cout << "X2::X2()" << endl;
	}
	~X2()
	{
		cout << "X2::~X2()" << endl;
	}

	explicit X2(int value) : m_i(value) // 类型转换构造函数（带有一个形参的拷贝构造函数）
	{
		cout << "X2::X2(int)" << endl;
	}
};

struct X
{
	int m_i;
	int *p_mi;
	X(const X &tmpx)
	{
		m_i = tmpx.m_i;
		p_mi = new int(100); // 为指针类型成员变量单独分配内存
		memcpy(p_mi, tmpx.p_mi, sizeof(int));
		cout << "X::X(const X &)" << endl;
	}

	X()
	{
		m_i = 0;
		p_mi = new int(100);
		cout << "X::X()" << endl;
	}
	~X()
	{
		delete p_mi;
		cout << "X::~X()" << endl;
	}
	explicit X(int value)
		: m_i(value) // 类型转换构造函数（带有一个形参的拷贝构造函数）
	{
		p_mi = new int(100);
		cout << "X::X(int)" << endl;
	}
};

int main()
{
	if (0)
	{
		cout << "----begin----" << endl;
		X1 x10(1000);
		cout << "--------" << endl;
		X1 x11 = 1000;
		cout << "--------" << endl;
		X1 x12 = X1(1000);
		cout << "--------" << endl;
		X1 x13 = (X1)1000;
		cout << "----end----" << endl;
	}

	if (0)
	{
		cout << "----begin----" << endl;
		X2 x10(1000);
		cout << "--------" << endl;
		// X2 x11 = 1000;//error
		// cout << "--------" << endl;
		X2 x12 = X2(1000);
		cout << "--------" << endl;
		X2 x13 = (X2)1000;
		cout << "----end----" << endl;
	}

	//{
	//	//编译器视角
	//	X x10;   //编译器视角是不调用构造函数的
	//	x10.X::X(1000);
	//}
	//{
	//	//编译器视角
	//	X _tmp0;          //编译器生成的临时对象
	//	_tmp0.X::X(1000); //带一个参数的构造函数被调用
	//	X x12;
	//	x12.X::X(_tmp0);  //拷贝构造函数被调用
	//	_tmp0.X::~X();    //调用析构
	//}

	{
		X x0;
		x0.m_i = 150;
		
		X x1(x0);
		cout << x1.m_i << endl;
	}

	cout << "Over!\n";
	return 0;
}

// g++ -fno-elide-constructors 02.08.cpp -o 02.08 && 02.08
