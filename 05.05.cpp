#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

struct Base
{
	virtual ~Base() {}
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};

struct Derive :  Base
{
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() { cout << "Derive::myselffunc()" << endl; } // 只属于Derive的函数
};

struct BCXu
{
	virtual void pvfunc() = 0;
};

int main()
{
	{
		Derive myderive;
		Derive* pmyderive = &myderive;
		//注意下列虚函数的调用顺序
		pmyderive->f();
		pmyderive->g();
		pmyderive->h();
		pmyderive->i();
		pmyderive->myselffunc();
	}

	{
		Base *pb = new Derive(); // 基类指针指向一个子类对象
		pb->g();
		delete pb;

		Derive myderive;
		Base &yb = myderive; // 基类引用引用的是一个子类对象
		yb.g();
	}
	{
		Base b1;
		Derive a1;
		Derive a2;
		Derive *pa3 = new Derive();
		delete pa3;
	}
	{
		cout << sizeof(Base) << endl;
		cout << sizeof(Derive) << endl;
		cout << sizeof(BCXu) << endl;
	}

	cout << "Over!\n";
	return 0;
}
