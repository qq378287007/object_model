#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

__int64 mytest(int mv)
{
	__int64 icout = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		icout += 1;
		if (i == 10000 && mv == 999)
			printf("---\n");
	}
	return icout;
}

struct A
{
	A() { cout << "A::A()" << endl; }

	virtual void myvirfunc() {}
};

struct A1
{
	A1() { cout << "A1::A1()" << endl; }
};

struct B : A
// struct B : A,  A1
{
};

struct C : B
{
	C() { cout << "C::C()" << endl; }
};

int main()
{
	if (0)
	{
		__int64 mycount = 1;
		clock_t start = clock();
		for (int i = 1; i <= 1000; i++)
		{
			mycount += mytest(6); // 参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
								  // mycount += mytest(i); //参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
		}
		clock_t end = clock();
		cout << "用时(毫秒): " << end - start << endl;
		cout << "mycount = " << mycount << endl;
	}

	if (1)
	{
		C c;
	}

	cout << "Over!\n";
	return 0;
}
