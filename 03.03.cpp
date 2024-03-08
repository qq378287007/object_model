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
	typedef void (*Func)(void);
	Derive derive;
	long long ***pvptrderive = (long long ***)(&derive);
	long long **vptrderive = *pvptrderive;
	Func f1 = (Func)vptrderive[0];
	f1();
	Func f2 = (Func)vptrderive[1];
	f2();
	Func f3 = (Func)vptrderive[2];
	f3();

	Derive derive2 = derive; // 拷贝构造
	long long ***pvptrderive2 = (long long ***)(&derive2);
	long long **vptrderive2 = *pvptrderive2;
	printf("&vptrderive = %p\n", vptrderive);
	printf("&vptrderive2 = %p\n", vptrderive2);

	Base base = derive; // 直接用子类对象给父类对象值
	long long ***pvptrbase = (long long ***)(&base);
	long long **vptrbase = *pvptrbase;
	Func fb1 = (Func)vptrbase[0];
	fb1();
	Func fb2 = (Func)vptrbase[1];
	fb2();
	Func fb3 = (Func)vptrbase[2];
	fb3();

	printf("&vptrbase = %p\n", vptrbase);

	printf("&f1 = %p\n", f1);
	printf("&fb1 = %p\n", fb1);

	printf("&f2 = %p\n", f2);
	printf("&fb2 = %p\n", fb2);

	cout << "Over!\n";
	return 0;
}
