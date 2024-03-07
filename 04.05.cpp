#include <cstdio>
#include <iostream>
using namespace std;

struct FAC // 父类
{
	int m_fai;
	int m_faj;
};
struct MYACLS : FAC // 子类
{
	int m_i;
	int m_j;
};

struct Base
{
	int m_i1;
	char m_c1;
	char m_c2;
	char m_c3;
};

struct Base1
{
	int m_i1;
	char m_c1;
};
struct Base2 : Base1
{
	char m_c2;
};
struct Base3 : Base2
{
	char m_c3;
};

int main()
{
	{
		printf("&MYACLS::m_i = %d\n", &FAC::m_fai);
		printf("&MYACLS::m_i = %d\n", &FAC::m_faj);
		printf("&MYACLS::m_i = %d\n", &MYACLS::m_fai);
		printf("&MYACLS::m_i = %d\n", &MYACLS::m_faj);
		printf("&MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("&MYACLS::m_j = %d\n", &MYACLS::m_j);

		FAC facobj;
		MYACLS myaclobj;
	}

	{
		cout << sizeof(Base) << endl;

		printf("&Base::m_i1 = %d\n", &Base::m_i1);
		printf("&Base::m_c1 = %d\n", &Base::m_c1);
		printf("&Base::m_c2 = %d\n", &Base::m_c2);
		printf("&Base::m_c3 = %d\n", &Base::m_c3);
	}

	{
		cout << sizeof(Base1) << endl; // 8
		cout << sizeof(Base2) << endl; // 12
		cout << sizeof(Base3) << endl; // 12
	}

	{
		printf("&Base3::m_i1 = %d\n", &Base3::m_i1);
		printf("&Base3::m_c1 = %d\n", &Base3::m_c1);
		printf("&Base3::m_c2 = %d\n", &Base3::m_c2);
		printf("&Base3::m_c3 = %d\n", &Base3::m_c3);
	}
	
	cout << "Over!\n";
	return 0;
}
