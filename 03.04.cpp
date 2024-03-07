#include <stdio.h>
#include <iostream>
using namespace std;

// 父类1
class Base1
{
public:
	virtual void f()
	{
		cout << "base1::f()" << endl;
	}

	virtual void g()
	{
		cout << "base1::g()" << endl;
	}
};

// 父类2
class Base2
{
public:
	virtual void h()
	{
		cout << "base2::h()" << endl;
	}
	virtual void i()
	{
		cout << "base2::i()" << endl;
	}
};

// 子类
class Derived : public Base1, public Base2
{
public:
	virtual void f()
	{
		cout << "derived::f()" << endl; // 只覆盖base1的f
	}

	virtual void i()
	{
		cout << "derived::i()" << endl; // 只覆盖base2的i
	}

	// 如下三个是本类自己的虚函数
	virtual void mh()
	{
		cout << "derived::mh()" << endl;
	}
	virtual void mi()
	{
		cout << "derived::mi()" << endl;
	}
	virtual void mj()
	{
		cout << "derived::mj()" << endl;
	}
};

int main()
{
	cout << sizeof(Base1) << endl;	 // 8
	cout << sizeof(Base2) << endl;	 // 8
	cout << sizeof(Derived) << endl; // 16字节，两个虚函数表指针（2个vptr）

	Derived ins; // 定义一个子类对象

	Base1 &b1 = ins;
	Base2 &b2 = ins;
	Derived &d = ins;
	b1.f(); // derived::f()，父类引用，但引用的是子类，所以这里执行子类所覆盖的父类的虚函数
	b2.i(); // dervied::i()，父类引用，但引用的是子类，所以这里执行子类所覆盖的父类的虚函数
	d.f();	// derived::f()
	d.i();	// derived::i()
	d.mh(); // derived::mh()

	cout << "********************\n";

	long ***pderived1 = (long ***)(&ins);
	long **vptr1 = pderived1[0]; // 第一个虚函数表指针，根据继承顺序，和base1对应
	long **vptr2 = pderived1[1]; // 往后走8个字节, 第二个虚函数表指针

	typedef void (*Func)(void);
	// 第一个父类虚函数（子类重写则覆盖）+子类虚函数
	Func f1 = (Func)vptr1[0]; // 0x00f31550 {project100.exe!Derived::f(void)}
	f1();
	Func f2 = (Func)vptr1[1]; // 0x00f31596 {project100.exe!Base1::g(void)}
	f2();
	Func f3 = (Func)vptr1[2]; // 0x00f31578 {project100.exe!Derived::mh(void)}
	f3();
	Func f4 = (Func)vptr1[3]; // 0x00f31582 {project100.exe!Derived::mi(void)}
	f4();
	Func f5 = (Func)vptr1[4]; // 0x00f3157d {project100.exe!Derived::mj(void)}
	f5();
	Func f6 = (Func)vptr1[5]; // 0x0029aa64 {project100.exe!const Derived::`RTTI Complete Object Locator'{for `Base2'}}
	f6();
	Func f7 = (Func)vptr1[6];
	// f7(); //error

	// 第二个父类虚函数（子类重写则覆盖）
	Func f11 = (Func)vptr2[0]; // 0x00291587 {project100.exe!Base2::h(void)}
	f11();
	Func f22 = (Func)vptr2[1]; // 0x00291591 {project100.exe!Derived::i(void)}
	f22();
	Func f33 = (Func)vptr2[2]; // 非法
	// f33();					   // error

	cout << "Over!\n";
	return 0;
}
