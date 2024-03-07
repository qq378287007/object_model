#include <iostream>
#include <cstdio>
using namespace std;

struct Base1
{
	int m_bi; // 4
};
struct MYACLS1 : Base1
{
	int m_i;					// 4
	int m_j;					// 4
	virtual void myvirfunc() {} // 8
	// 4
	// 8
	// 4, 4
};

struct Base2
{
	virtual void mybvirfunc() {} // 8
	int m_bi;					 // 4
	// 8
	// 4
};
struct MYACLS2 : Base2
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
		cout << sizeof(MYACLS1) << endl;
		printf("&MYACLS1::m_bi = %d\n", &MYACLS1::m_bi);
		printf("&MYACLS1::m_i = %d\n", &MYACLS1::m_i);
		printf("&MYACLS1::m_j = %d\n", &MYACLS1::m_j);
	}

	{
		cout << sizeof(MYACLS2) << endl;
		printf("MYACLS2::m_bi = %d\n", &MYACLS2::m_bi);
		printf("MYACLS2::m_i = %d\n", &MYACLS2::m_i);
		printf("MYACLS2::m_j = %d\n", &MYACLS2::m_j);
	}

	cout << "Over!\n";
	return 0;
}
