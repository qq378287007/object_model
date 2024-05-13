#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

struct Base
{
	virtual ~Base() { cout << "Base::~Base()" << endl; }

	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }

	virtual Base *clone() const { return new Base(); }
};

struct Base2
{
	virtual ~Base2() { cout << "Base2::~Base2()" << endl; }

	virtual void hBase2() { cout << "Base2::hBase2()" << endl; }

	virtual Base2 *clone() const { return new Base2(); }
};

struct Derive : Base, Base2
{
	virtual ~Derive() { cout << "Derive::~Derive()" << endl; }

	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }

	void myselffunc() { cout << "Derive::myselffunc()" << endl; } // 只属于Derive的函数

	virtual Derive *clone() const { return new Derive(); }
};

struct Base0
{
	// 8(虚函数表指针)
	// 4(4)
	int m_basei;
	virtual ~Base0() {}
	virtual void f() {}
};

struct Derive0 : virtual Base0
{
	// 8(虚基类表指针)
	// 4(4，m_derivei)
	// 8(虚函数表指针)
	// 4(4，m_basei)
	virtual ~Derive0() {}
	int m_derivei;
};

int main()
{
	if (0)
	{
		Base2 *pb2 = new Derive();
		delete pb2; // 这里调用了Derive类的虚析构函数
	}

	if (0)
	{
		Derive *pd2 = new Derive();
		pd2->hBase2(); // 第二个基类的成员函数，this指针调整，指向Base2类子对象的首地址
		delete pd2;
	}

	if (0)
	{
		Base2 *pb1 = new Derive();
		Base2 *pb2 = pb1->clone(); // 执行Derive::clone()
		delete pb2;
		delete pb1;
	}

	if (0)
	{
		cout << sizeof(Base0) << endl;	 // 16
		cout << sizeof(Derive0) << endl; // 32

		Derive0 dobj;
		dobj.m_basei = 2;	// 13-16字节
		dobj.m_derivei = 5; // 5-8字节

		Derive0 *pdobj = new Derive0();
		pdobj->f();
		delete pdobj;
	}

	if (0)
	{
		Base0 *pbase = new Derive0();
		pbase->m_basei = 6;
		delete pbase;
	}

	if (1)
	{
		Derive0 *pderive = new Derive0();
		Base0 *pbase2 = (Base0 *)pderive;
		pbase2->m_basei = 7;
		delete pderive;
	}

	cout << "Over!\n";
	return 0;
}