#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};
// class Derive : public Base {
// public:
//	virtual void i() { cout << "Derive::i()" << endl; }
//	virtual void g() { cout << "Derive::g()" << endl; }
//	void myselffunc() {} //只属于Derive的函数
// };
class Derive : public Base
{
public:
};

class BCXu
{
public:
	virtual void pvfunc() = 0;
};

int main()
{
	//{
	//	Derive myderive;
	//	Derive* pmyderive = &myderive;
	//	//注意下列虚函数的调用顺序
	//	pmyderive->f();
	//	pmyderive->g();
	//	pmyderive->h();
	//	pmyderive->i();
	//	cout << "断点设置在这里" << endl;
	//}

	//{
	//	Base* pb = new Derive();  //基类指针指向一个子类对象
	//	pb->g();

	//	Derive myderive;
	//	Base& yb = myderive;      //基类引用引用的是 一个子类对象
	//	yb.g();
	//}
	{
		Derive a1;
		Derive a2;
		Derive *pa3 = new Derive();

		Base b1;

		cout << sizeof(Derive) << endl;
		cout << "断点设置在这里" << endl;
	}

	{
		cout << sizeof(Base) << endl;
	}

	cout << "Over!\n";
	return 0;
}
