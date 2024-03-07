#include <cstdio>
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		cout << "Base::f()" << endl;
	}
	virtual void g()
	{
		cout << "Base::g()" << endl;
	}
	virtual void h()
	{
		cout << "Base::h()" << endl;
	}
};
class Derive : public Base
{
public:
	void g()
	{
		cout << "Derive::g()" << endl;
	}
};

int main()
{
	cout << sizeof(Base) << endl;	// 8字节，虚函数表指针，x64平台
	cout << sizeof(Derive) << endl; // 8字节

	Derive *d = new Derive(); // 类指针
	// Base *d = new Derive();//等价

	long ***pvptr = (long ***)d; // 类指针转为虚函数表指针（三级指针）
	long **vptr = *pvptr;		 // 虚函数表指针取值得到虚函数表（二级指针）

	for (int i = 0; vptr[i] != nullptr; i++)
		printf("vptr[%d] = 0x:%p\n", i, vptr[i]); // 虚函数地址（一级指针）

	typedef void (*Func)(void); // 定义Func是函数指针类型
	Func f = (Func)vptr[0];		// 函数指针变量
	f();						// Base::f()
	Func g = (Func)vptr[1];
	g(); // Derive::g()   子类覆盖父类的虚函数
	Func h = (Func)vptr[2];
	h(); // Base::h()

	Func i = (Func)vptr[3];
	// i();					// 运行异常

	//---------------------------
	Base *dpar = new Base();
	long ***pvptrpar = (long ***)dpar;
	long **vptrpar = *pvptrpar;
	for (int i = 0; vptrpar[i] != nullptr; i++)
		printf("vptr_Base [%d] = 0x:%p\n", i, vptrpar[i]);

	Func fpar = (Func)vptrpar[0]; // project4.exe!Base::f(void)}
	Func gpar = (Func)vptrpar[1]; // project4.exe!Base::g(void)}
	Func hpar = (Func)vptrpar[2]; // project4.exe!Base::h(void)}
	Func ipar = (Func)vptrpar[3];
	fpar(); // base::f
	gpar(); // base::g
	hpar(); // base::h
	//ipar();       //运行异常

	cout << "Over!\n";
	return 0;
}
