#include <cstdio>
#include <iostream>
using namespace std;

template <class T>
T funadd(const T &a, const T &b)
{
	T addhe = a + b;
	return addhe;
}

template <class T>
struct ATPL
{
	enum ECURRSTATUS
	{
		E_CS_Busy,
		E_CS_Free,
	};

	T m_i, m_j;
	ATPL(T tmpi = 0, T tmpj = 0) : m_i(tmpi), m_j(tmpj) {}

	static int m_sti;
	static T m_sti2;

	void func1() const { cout << "ATPL::func1()" << endl; }
	void func2() const { cout << "ATPL::func2()" << endl; }

	virtual void virfunc1() { cout << "ATPL::virfunc1()" << endl; }
	virtual void virfunc2() { cout << "ATPL::virfunc2()" << endl; }
};

template <class T>
int ATPL<T>::m_sti = 10;

template <class T>
T ATPL<T>::m_sti2 = 10;

void myfunc()
{
	ATPL<int> myobj;
	myobj.m_sti2 = 18;
	cout << myobj.m_sti2 << endl;
}

int main()
{
	cout << funadd(12, 14) << endl;

	{
		ATPL<int>::ECURRSTATUS myenum = ATPL<int>::E_CS_Busy;
		ATPL<int>::ECURRSTATUS myenum2 = ATPL<int>::E_CS_Free;
		ATPL<double>::ECURRSTATUS myenum3 = ATPL<double>::E_CS_Free;
	}

	{
		ATPL<int>::m_sti = 18;
		cout << ATPL<int>::m_sti << endl;

		ATPL<float>::m_sti = 21;
		cout << ATPL<float>::m_sti << endl;

		ATPL<int>::m_sti2 = 132;
		cout << ATPL<int>::m_sti2 << endl;

		ATPL<float>::m_sti2 = 1050.5;
		cout << ATPL<float>::m_sti2 << endl;
	}

	ATPL<int> *pobj = nullptr;

	{
		const ATPL<int> &yobj = 0; // 因为构造函数允许缺省参数，这里有隐式类型转换
		yobj.func1();
	}

	cout << sizeof(ATPL<int>) << endl;

	cout << "Over!\n";
	return 0;
}
