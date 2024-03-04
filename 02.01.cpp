#include <iostream>
using namespace std;

struct A1
{
};

class A2
{
public:
	void func(){};
	void func1(){};
	void func2(){};
};

class A3
{
public:
	void func(){};
	void func1(){};
	void func2(){};

	char ab;
};

class A4
{
public:
	void func(){};
	void func1(){};
	void func2(){};

	int ab;
};

int main()
{
	A1 a;
	cout << sizeof(a) << endl;

	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	cout << sizeof(A4) << endl;

	cout << "Over!\n";
	return 0;
}
