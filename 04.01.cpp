#include <iostream>
using namespace std;

int myvar = 5; // 全局量
int myfunc()
{
	// return ::myvar;
	return myvar;
}
class A0
{
public:
	int myfunc()
	{
		// return ::myvar;
		return myvar;
	}

private:
	int myvar{3};
};

typedef string mytype;
class A
{
	typedef int mytype;

public:
	void myfunc(mytype tmpvalue) // int
	{
		m_value = tmpvalue;
	}

private:
	mytype m_value; // int
};

void myfunc(mytype tmpvalue) // string类型
{
	mytype mvalue = tmpvalue;
}

int main()
{
	cout << myfunc() << endl;
	A0 a0;
	cout << a0.myfunc() << endl;

	A a;
	a.myfunc(4);
	myfunc("dd");

	cout << "Over!\n";
	return 0;
}
