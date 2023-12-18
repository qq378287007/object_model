#include <iostream>
using namespace std;

class A1
{
public:
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
#if 0
	A1 a;
	cout << sizeof(a) << endl;
#endif

#if 0
	A2 a;
	cout << sizeof(a) << endl;
#endif

#if 0
	A3 a;
	cout << sizeof(a) << endl;
#endif

#if 1
	A4 a;
	cout << sizeof(a) << endl;
#endif

	cout << "Over!\n";
	return 0;
}
