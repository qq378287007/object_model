#include <iostream>
#include <cstdio>
using namespace std;

struct Base
{
	virtual void mybvirfunc() {}
	int m_bi;
	Base()
	{
		printf("Base::Base(), this:%p!\n", this);
	}
	// 8
	// 4(m_bi)
};

struct Base2
{
	virtual void mybvirfunc2() {}
	int m_b2i;
	// 8
	// 4(m_b2i)

	Base2()
	{
		printf("Base2::Base2(), this:%p!\n", this);
	}
};

struct MYACLS : Base, Base2
{
	int m_i;
	int m_j;
	// 8
	// 4(m_bi)
	// 8
	// 4, 4(m_b2i, m_i)
	// 4(m_j)

	virtual void myvirfunc() {}
	MYACLS()
	{
		printf("MYACLS::MYACLS(), this:%p!\n", this);
	}
};

int main()
{
	{
		cout << sizeof(MYACLS) << endl;
		printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
		printf("MYACLS::m_b2i = %d\n", &MYACLS::m_b2i);
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
	}
	cout << "***********************\n";
	{
		MYACLS myobj;
		myobj.m_i = 3;
		myobj.m_j = 6;
		myobj.m_bi = 9;
		myobj.m_b2i = 12;

		Base *pbase = &myobj; // Base类的首地址和MYACLS类的首地址相同, this不需要调整
		// Base2* pbase2 = (Base2*)(((char*)&myobj) + sizeof(Base));
		Base2 *pbase2 = &myobj; // this指针自动调整

		printf("&myobj = %p\n", &myobj);
		printf("pbase = %p\n", pbase);
		printf("pbase2 = %p\n", pbase2);
		printf("pbase2 = %p\n", ((char *)&myobj) + sizeof(Base));
		cout << "***********************\n";

		Base2 *pbase3 = new MYACLS(); // this指针自动调整
		// delete pbase3;//error
		MYACLS *psubobj = (MYACLS *)pbase3; // this指针自动调整
		printf("pbase3 = %p\n", pbase3);
		printf("psubobj = %p\n", psubobj);

		delete psubobj;
	}

	cout << "Over!\n";
	return 0;
}
