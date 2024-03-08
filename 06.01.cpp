#include <cstdio>
#include <iostream>
using namespace std;

struct A
{
	A() { printf("A::A(), this = %p\n", this); }
	virtual ~A() {}

	virtual void myvirfunc2()
	{
		printf("A::myvirfunc2()\n");
	}
	virtual void myvirfunc()
	{
		myvirfunc2();
		printf("A::myvirfunc()\n");
	}
};
struct B : A
{
	B()
	{
		myvirfunc();
		printf("B::B(), this = %p\n", this);
	}
	virtual ~B() {}

	virtual void myvirfunc2()
	{
		printf("B::myvirfunc2()\n");
	}
	virtual void myvirfunc()
	{
		myvirfunc2();
		printf("B::myvirfunc()\n");
	}
};
struct C : B
{
	int m_c;
	C()
		: m_c(11)
	{
		myvirfunc(); // 调用一个虚函数
		printf("C::C(), this = %p\n", this);
	}
	virtual ~C()
	{
		myvirfunc();
	}

	virtual void myvirfunc2()
	{
		printf("C::myvirfunc2()\n");
	}
	virtual void myvirfunc()
	{
		myvirfunc2();
		printf("C::myvirfunc()\n");
	}
};

int main()
{
	// C c;

	C *mycobj = new C();
	// mycobj->myvirfunc();
	delete mycobj;

	cout << "Over!\n";
	return 0;
}
