#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

__int64 mytest(int mv)
{
	int i = 0;
	__int64 icout = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		icout += 1;
		if (i == 10000 && mv == 999)
		{
			printf("---\n");
		}
	}
	return icout;
}

class A
{
public:
	A()
	{
		cout << "A::A()" << endl;
	}

public:
	virtual void myvirfunc() {}
};

class A1
{
public:
	A1()
	{
		cout << "A1::A1()" << endl;
	}
};

class B : public A
// class B :public A, public A1
{
public:
};

class C : public B
{
public:
	C()
	{
		cout << "C::C()" << endl;
	}
};

int main()
{
	//{
	//	clock_t start, end;  //记得包含头文件#include <ctime>
	//	__int64 mycount = 1;
	//	start = clock();
	//	for (int i = 1; i <= 1000; i++)
	//	{
	//		mycount += mytest(6);			 //参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
	//		//mycount += mytest(i); //参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
	//	}
	//	end = clock();
	//	cout << "用时(毫秒):" << end - start << endl;
	//	cout << "mycount = " << mycount << endl;
	//}

	{
		C c;
	}

	cout << "Over!\n";
	return 0;
}