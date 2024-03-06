#include <iostream>
#include <stdio.h>
using namespace std;

struct A1
{
	int &m_yy;
	A1(int &tmpvalue) : m_yy(tmpvalue)
	{
		// m_yy = tmpvalue;
		m_yy = 160;
	}
};

struct A2
{
	const int &m_yy;
	A2(const int &tmpvalue) : m_yy(tmpvalue)
	{
	}
};

struct Base3
{
	int ba;
	int bb;
	Base3(int tmpa, int tmpb)
		: ba(tmpa), bb(tmpb)
	{
	}
};
struct A3 : Base3
{
	int m_x;
	int m_y;
	int &m_yy;
	const int m_myc;

	A3(int &tmpvalue)
		: m_yy(tmpvalue), m_myc(tmpvalue), Base3(tmpvalue, tmpvalue)
	{
		m_x = 0;
		m_y = 0;
		m_yy = 163; // 就等于修改外界的abc变量值
	}
};

struct CSub
{
	CSub(int tmpvalue) {}
};
struct A4
{
	CSub cmysub;
	A4(int tmpvalue) : cmysub(tmpvalue)
	{
	}
};

struct X
{
	int m_i;
	X(int value = 0) : m_i(value)
	{
		printf("this = %p", this);
		cout << "X::X(int)" << endl;
	}
	X(const X &tmpv)
	{
		printf("this = %p", this);
		cout << "X::X(const X &)" << endl;
	}
	X &operator=(const X &tmpTime)
	{
		printf("this = %p", this);
		cout << "X::X &operator=(const X &)" << endl;
		return *this; // 返回一个该对象的引用
	}
	~X()
	{
		printf("this = %p", this);
		cout << "X::~X()" << endl;
	}
};

struct XA
{
	X xobj;
	int m_test;
	XA(int tmpvalue)
	{
		xobj = 1000;
		m_test = 500;
	}
};

struct XA2
{
	X xobj;
	int m_test;
	int m_test2; // 定义在后面，则后得到值
	// XA(int tmpvalue)
	// XA(int tmpvalue) : xobj(1000)
	XA2(int tmpvalue)
		: xobj(1000), m_test2(500), m_test(m_test2)
	{
		// xobj = 1000;
		m_test = 500;
	}
};
int main()
{
	int abc = 1;
	A1 a1(abc);
	cout << abc << endl;

	A2 a2(22);

	int abc3 = 1;
	A3 a3(abc3);
	cout << abc3 << endl;

	A4 a4(3);

	{
		XA myaobj(1000);
	}

	cout << "Over!\n";
	return 0;
}