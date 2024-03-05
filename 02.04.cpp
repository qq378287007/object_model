#include <iostream>
using namespace std;

class M0TX
{
public:
	M0TX()
	{
		cout << "Ogood!" << endl;
	}
};

class MATX
{
public:
	MATX()
	{
		cout << "goodHAHAHA" << endl;
	}
};

class MBTXPARENT
{
public:
	MBTXPARENT()
	{
		cout << "MBTXPARENT()" << endl;
	}
};

// class MBTX
//{
// public:
//	int m_i;
//	int m_j;
//
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
//
// public:
//	//MATX ma;  //类类型成员变量
//	//M0TX m0; //注意定义顺序，先定义的ma，再定义的m0
//
//
//	M0TX m0; //调换成员变量定义顺序
//	MATX ma;  //类类型成员变量
// };
// class MBTX:public MBTXPARENT
//{
// public:
//	int m_i;
//	int m_j;
//
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
// };

// class MBTX
//{
// public:
//	int m_i;
//	int m_j;
//
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
//	virtual void mvirfunc() //虚函数
//	{
//		cout << "mvirfunc" << endl;
//	}
// };
class MBTX : public MBTXPARENT
{
public:
	int m_i;
	int m_j;

	MBTX() // 缺省构造函数
	{
		m_i = 15;
	}

	void funct()
	{
		cout << "Iamverygood" << endl;
	}
	virtual void mvirfunc() // 虚函数
	{
		cout << "mvirfunc" << endl;
	}
};

class Grand // 爷爷类
{
public:
};
class A : virtual public Grand // 注意virtual
{
public:
};
class A2 : virtual public Grand // 注意virtual
{
public:
};
class C : public A, public A2 // 这里不需要virtual
{
public:
	C()
	{
		cout << "C::C()" << endl;
	}
};

class Time
{
public:
	Time()
	{
		cout << "Time::Time()" << endl;
	}
	int Second{10};
};

int main()
{
	//{
	//	MBTX myb;
	//}

	//{
	//	C cc; //生成C类对象
	//}
	Time mytime;

	cout << "Over!\n";
	return 0;
}
