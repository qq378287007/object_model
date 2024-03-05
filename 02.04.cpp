#include <iostream>
using namespace std;

class MATX
{
public:
	MATX()
	{
		cout << "goodHAHAHA" << endl;
	}
};

class M0TX
{
public:
	M0TX()
	{
		cout << "Ogood!" << endl;
	}
};

class MBTX
{
public:
	int m_i;
	int m_j;

	void funct()
	{
		cout << "Iamverygood" << endl;
	}

public:
	MATX ma; // 类类型成员变量
	M0TX m0; // 定义顺序，决定调用构造函数的顺序
};

class MBTXPARENT2
{
public:
	MBTXPARENT2()
	{
		cout << "MBTXPARENT2()" << endl;
	}
};

class MBTX2 : public MBTXPARENT2
{
public:
	int m_i;
	int m_j;

	void funct()
	{
		cout << "Iamverygood" << endl;
	}
};

class MBTX3
{
public:
	int m_i;
	int m_j;

	void funct()
	{
		cout << "Iamverygood" << endl;
	}
	virtual void mvirfunc() // 虚函数
	{
		cout << "mvirfunc" << endl;
	}
};

class MBTXPARENT4
{
public:
	MBTXPARENT4()
	{
		cout << "MBTXPARENT4()" << endl;
	}
};
class MBTX4 : public MBTXPARENT4
{
public:
	int m_i;
	int m_j;

	MBTX4() // 缺省构造函数
	{
		m_i = 15;
		// 编译器会在内部插入代码
		// 调用父类的构造函数
		// 虚函数表指针赋值
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
	MBTX myb;
	C cc; // 生成C类对象
	Time mytime;

	cout << "Over!\n";
	return 0;
}
