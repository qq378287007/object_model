#include <cstdio>
#include <iostream>
using namespace std;

struct FAC
{
	int m_fai;
	int m_faj;
};

struct MYACLS : FAC
{
	int m_i;
	int m_j;
	static int m_si; // 声明

	void myfunc()
	{
		m_i = 5;
		m_j = 6;
	}
};
int MYACLS::m_si = 0; // 定义

int main()
{
	cout << MYACLS::m_si << endl;

	MYACLS myobj;
	cout << myobj.m_si << endl;

	MYACLS *pmyobj = new MYACLS();
	cout << pmyobj->m_si << endl;

	MYACLS::m_si = 1;
	myobj.m_si = 2;
	pmyobj->m_si = 3;

	printf("&myobj.m_i = %p\n", &myobj.m_i);
	printf("&pmyobj->m_i = %p\n", &pmyobj->m_i);
	printf("&MYACLS::m_si = %p\n", &MYACLS::m_si);
	printf("&MYACLS::m_si = %p\n", &myobj.m_si);
	printf("&MYACLS::m_si = %p\n", &pmyobj->m_si);

	pmyobj->myfunc();
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i); // 8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j); // 12
	pmyobj->m_faj = 7;							// 给父类的成员变量赋值

	cout << "Over!\n";
	return 0;
}
