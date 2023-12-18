#include <iostream>
#include <time.h>
using namespace std;

class X
{
public:
	int x;
	int y;
	int z;
	/*X() :x(0), y(0), z(0)
	{
		cout << "X类的构造函数被执行" << endl;
	}*/
	X()
	{
		memset(this, 0, sizeof(X));
		cout << "X类的构造函数被执行" << endl;
	}

	/*X(const X& tm) :x(tm.x), y(tm.y), z(tm.z)
	{
		cout << "X类的拷贝构造函数被执行" << endl;
	}*/
	X(const X &tm)
	{
		memcpy(this, &tm, sizeof(X));
		cout << "X类的拷贝构造函数被执行" << endl;
	}

public:
	virtual ~X()
	{
		cout << "X类的析构函数被执行" << endl;
	}
	virtual void virfunc()
	{
		cout << "虚函数virfunc()执行了" << endl;
	}
	void ptfunc()
	{
		cout << "普通函数ptfunc()执行了" << endl;
	}
};

int main()
{
	//{
	//	X x0; //调用构造函数
	//	x0.x = 100;
	//	x0.y = 200;
	//	x0.z = 300;
	//	x0.virfunc();
	//	X x1(x0); //调用拷贝构造函数
	//	cout << "x1.x=" << x1.x << " x1.y=" << x1.y << " x1.z=" << x1.z << endl;

	//}

	//{
	//	X* px0 = new X();
	//	px0->ptfunc();  //可以正常调用普通该函数
	//	px0->virfunc(); //无法正常调用该虚函数
	//	delete px0;     //无法正常调用析构函数
	//}

	//{
	//	int i = 9;
	//	printf("i的地址 = %p\n", &i); //会发现每次i的地址输出出来都不一样

	//	X x0;
	//	printf("ptfunc的地址 = %p\n", &X::ptfunc); //正常函数地址可以这样输出

	//	/*long* pvptr = (long*)(&x0);
	//	long* vptr = (long*)(*pvptr);
	//	printf("vptr[1] = %p\n",  vptr[1]); */

	//	x0.ptfunc();
	//	x0.virfunc(); //虚函数是可以正常调用的
	//	cout << "断点设置在这里" << endl;
	//}

	{
		/*	X* pX0 = new X();
			pX0->ptfunc();
			pX0->virfunc();*/

		X x1;
		X &x1y = x1;   // 引用
		x1y.virfunc(); // 也报异常，因为虚函数表指针被清零导致无法找到虚函数表，从而也无法执行虚函数

		cout << "断点设置在这里" << endl;
	}

	cout << "Over!\n";
	return 0;
}
