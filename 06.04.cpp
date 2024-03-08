#include <cstdio>
#include <iostream>
using namespace std;

struct A
{
	int m_i;
	// A() { cout << "A::A()" << endl; }
	//~A() { cout << "A::~A()" << endl; }
};

void myfunc1()
{
	static A s_aobj1;
	static A s_aobj2;
	printf("&s_aobj1=%p\n", &s_aobj1);
	printf("&s_aobj2=%p\n", &s_aobj2);
}
const A &myfunc2()
{
	static A s_aobj1;
	printf("&s_aobj1=%p\n", &s_aobj1);
	return s_aobj1;
}

void myfunc()
{
	static A s_aobj[1000'0000]; // '是数字分隔符, C++14
	for (int i = 0; i < 1000'0000; i++)
		s_aobj[i].m_i = i;
	printf("s_aobj = %p\n", s_aobj);
}

int main()
{
	myfunc1();
	myfunc1();

	printf("&A=%p\n", &myfunc2());
	printf("&A=%p\n", &myfunc2());

	myfunc();
	myfunc();

	cout << "Over!\n";
	return 0;
}
