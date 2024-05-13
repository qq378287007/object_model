#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

// 将一个成员函数的地址转换成普通地址
template <typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type *>(static_cast<void *>(&src));
}
struct TDF
{
	void myf(int val) { cout << "myf()成员函数执行了" << endl; }
};

struct A
{
	virtual ~A() {}

	void myfunc1(int tempvalue1)
	{
		cout << "tempvalue1 = " << tempvalue1 << endl;
	}
	void myfunc2(int tempvalue2)
	{
		cout << "tempvalue2 = " << tempvalue2 << endl;
	}

	static void mysfunc(int tempvalue)
	{
		cout << "A::mysfunc()静态成员函数执行了，tempvalue = " << tempvalue << endl;
	}

	virtual void myvirfuncPrev(int tempvalue)
	{
		cout << "A::myvirfuncPrev()虚成员函数执行了，tempvalue = " << tempvalue << endl;
	}
	virtual void myvirfunc(int tempvalue)
	{
		cout << "A::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl;
	}
};

struct B : A
{
	virtual ~B() {}

	virtual void myvirfunc(int tempvalue)
	{
		cout << "B::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl;
	}
};

int main()
{
	if (0)
	{
		printf("TDF::myf的地址是%p\n", &TDF::myf);
		typedef void (*Func)();
		Func fun1 = pointer_cast<Func>(&TDF::myf);
		void *func2 = pointer_cast<void *>(&TDF::myf);
		fun1(); // 把成员函数当普通函数调用
	}

	if (0)
	{
		void (A::*pmypoint)(int tempvalue) = &A::myfunc1; // 定义一个成员函数指针并给初值
		pmypoint = &A::myfunc2;							  // 给成员函数指针赋值

		// 通过成员函数指针来调用成员函数
		A mya;
		(mya.*pmypoint)(15); // 要使用成员函数指针来调用成员函数，必须要对象介入

		A *pmya = new A();
		(pmya->*pmypoint)(20); // 用对象指针介入来使用成员函数指针 来调用成员函数
	}

	if (0)
	{
		void (*pmyspoint)(int tempvalue) = &A::mysfunc; // 一个普通的函数指针，而不是成员函数指针
		pmyspoint(80);									// 从编译器角度看也是这个代码，不需要有个所谓的this指针
	}

	if (1)
	{
		void (A::*pmyvirfunc)(int tempvalue) = &A::myvirfunc;

		A *pvaobj = new A;
		pvaobj->myvirfunc(190);		// 通过虚函数表
		(pvaobj->*pmyvirfunc)(190); // 通过虚函数表
		printf("%p\n", &A::myvirfunc);

		pmyvirfunc = &A::myfunc2;
		(pvaobj->*pmyvirfunc)(33);
	}

	if (1)
	{
		B *pmyb = new B();
		void (B::*pmyvirfunc)(int tempvalue) = &A::myvirfunc; // 成员函数指针
		// void (B:: * pmyvirfunc)(int tempvalue) = &B::myvirfunc;
		(pmyb->*pmyvirfunc)(190);

		printf("%p\n", &A::myvirfunc);
		printf("%p\n", &B::myvirfunc);
	}

	cout << "Over!\n";
	return 0;
}
