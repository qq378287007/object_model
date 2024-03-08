#include <cstring>
#include <iostream>
using namespace std;

class X0
{
public:
	int x;
	int y;
	int z;
	X0()
	{
		memset(this, 0, sizeof(X0));
		cout << "X0:X0()" << endl;
	}

	X0(const X0 &tm)
	{
		memcpy(this, &tm, sizeof(X0));
		cout << "X0:X0(const X0&)" << endl;
	}
};

class X
{
public:
	int x;
	int y;
	int z;
	/*X() : x(0), y(0), z(0)
	{
		cout << "X:X()" << endl;
	}*/
	X()
	{
		memset(this, 0, sizeof(X));
		cout << "X:X()" << endl;
	}

	/*X(const X &tm) : x(tm.x), y(tm.y), z(tm.z)
	{
		cout << "X:X(const X&)" << endl;
	}*/
	X(const X &tm)
	{
		memcpy(this, &tm, sizeof(X));
		cout << "X:X(const X&)" << endl;
	}

public:
	virtual ~X()
	{
		cout << "X:virtual ~X()" << endl;
	}
	virtual void virfunc()
	{
		cout << "virtual virfunc()" << endl;
	}
	void ptfunc()
	{
		cout << "ptfunc()" << endl;
	}
};

int main()
{
	{
		X0 x0;
		x0.x = 100;
		x0.y = 200;
		x0.z = 300;
		X0 x1(x0);
		cout << "x1.x=" << x1.x << ", x1.y=" << x1.y << ", x1.z=" << x1.z << endl;
	}

	{
		X x0;
		x0.x = 100;
		x0.y = 200;
		x0.z = 300;
		X x1(x0);
		cout << "x1.x=" << x1.x << ", x1.y=" << x1.y << ", x1.z=" << x1.z << endl;

		x0.virfunc();
	}

	{
		X *px0 = new X();
		px0->ptfunc(); // 可以正常调用普通该函数

		// px0->virfunc(); // 无法正常调用该虚函数
		// delete px0;		// 无法正常调用析构函数
	}

	{
		int i = 9;
		printf("&i = %p\n", &i); // 会发现每次i的地址输出出来都不一样

		printf("&X::ptfunc = %p\n", &X::ptfunc); // 正常函数地址可以这样输出
		printf("&X::virfunc = %p\n", &X::virfunc); // 正常函数地址可以这样输出

		X x0;
		long long ***pvptr = (long long ***)(&x0);
		long long **vptr = *pvptr;
		printf("vptr[1] = %p\n", vptr);

		x0.ptfunc();
		x0.virfunc(); // 虚函数是可以正常调用的
	}

	{
		X *pX0 = new X();
		pX0->ptfunc();
		// pX0->virfunc();//error

		X x1;
		X &x1y = x1;   // 引用
		x1y.virfunc(); //
	}

	cout << "Over!\n";
	return 0;
}
