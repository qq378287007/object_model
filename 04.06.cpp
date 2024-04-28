#include <iostream>
#include <cstdio>
using namespace std;

struct MYACLS
{
	int m_i;					// 4
	int m_j;					// 4
	virtual void myvirfunc() {} // 8

	// 8
	// 4, 4
};

struct Base0
{
	int m_bi;					 // 4
	virtual void mybvirfunc() {} // 8
};
struct MYACLS0 : Base0
{
	int m_i;					// 4
	int m_j;					// 4
	virtual void myvirfunc() {} // 8

	// 8
	// 4,4
	// 4
};

struct Base1
{
	int m_bi; // 4
};
struct MYACLS1 : Base1
{
	int m_i;					// 4
	int m_j;					// 4
	virtual void myvirfunc() {} // 8

	// 8
	// 4,4
	// 4
};

int main()
{
	{
		cout << sizeof(MYACLS) << endl;
		printf("&MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("&MYACLS::m_j = %d\n", &MYACLS::m_j);
	}
	{
		cout << sizeof(MYACLS0) << endl;
		printf("&MYACLS0::m_bi = %d\n", &MYACLS0::m_bi);
		printf("&MYACLS0::m_i = %d\n", &MYACLS0::m_i);
		printf("&MYACLS0::m_j = %d\n", &MYACLS0::m_j);
	}
	{
		cout << sizeof(MYACLS1) << endl;
		printf("&MYACLS1::m_bi = %d\n", &MYACLS1::m_bi); // 0,站在父类角度去计算，父类无虚函数
		printf("&MYACLS1::m_i = %d\n", &MYACLS1::m_i);
		printf("&MYACLS1::m_j = %d\n", &MYACLS1::m_j);
	}

	cout << "Over!\n";
	return 0;
}
