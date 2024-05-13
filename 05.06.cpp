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
};

struct Base2
{
	virtual ~Base2() { cout << "Base2::~Base2()" << endl; }
	virtual void hBase2() { cout << "Base2::hBase2()" << endl; }
};

struct Derive : Base, Base2
{
	virtual ~Derive() { cout << "Derive::~Derive()" << endl; }

	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() { cout << "Derive::myselffunc()" << endl; } // 只属于Derive的函数
};

struct ParentClass // 父类
{
	ParentClass()
	{
		cout << "ParentClass::ParentClass()" << endl;
	}
	virtual ~ParentClass()
	{
		cout << "ParentClass::~ParentClass()" << endl;
	}
};
struct SonClass : ParentClass // 子类
{
	char *m_p = nullptr;
	SonClass()
	{
		cout << "SonClass::SonClass()" << endl;
		m_p = new char[100]; // 这里分配了内存
	}
	~SonClass()
	{
		cout << "SonClass::~SonClass()" << endl;
		delete m_p; // 这里要释放内存，否则会导致内存泄漏
	}
};

int main()
{
	if (0)
	{
		Derive *temp = new Derive();
		Base2 *pb2 = (Base2 *)((char *)(temp) + sizeof(Base));
	}

	if (0)
	{
		Base2 *pb2 = new Derive();
		delete pb2;
	}

	if (0)
	{
		Base *pbm = new Base();
		delete pbm;

		Base2 *pb222 = new Base2();
		delete pb222;

		Derive *p11212 = new Derive();
		p11212->g(); // Derive::g()
		p11212->i(); // Derive::i()，走虚函数表，查询虚函数表得到虚函数地址并调用虚函数
		delete p11212;

		Derive dddd;
		dddd.i(); // Derive::i()，不走虚函数表，直接调用虚函数
	}

	if (1)
	{
		SonClass sonobj;

		ParentClass *parobj = new SonClass(); // 创建SonClass对象
		delete parobj;						  // 删除SonClass对象
	}

	cout << "Over!\n";
	return 0;
}
