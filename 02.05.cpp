#include <iostream>
using namespace std;

class A1
{
public:
	int m_test;
};

class ASon
{
public:
	int m_testson;
};
class A20
{
public:
	int m_test;
	ASon asubobj;
};

class CTB
{
public:
	CTB(const CTB &)
	{
		cout << "CTB::CTB(const CTB &) " << endl;
	}
	CTB()
	{
	}
};
class A3
{
public:
	CTB m_ctb;
};
class CTBSon : public CTB
{
public:
};

class CTBSon2
{
public:
	virtual void mvirfunc() {}
};
class CTB3
{
public:
	virtual void mvirfunc() {}
};
class CTBSon3 : public CTB3
{
public:
};

class Grand // 爷爷类
{
public:
};
class A : virtual public Grand
{
public:
};
class A2 : virtual public Grand
{
public:
};
class C : public A, public A2
{
public:
};

struct TC
{
	int i;		   // 内置类型可以移动
	std::string s; // string类型定义了自己的移动操作
};

int main()
{

	{
		A1 mya1;
		mya1.m_test = 15;
		A1 mya2 = mya1; // 按值拷贝，不需要合成拷贝构造函数
	}

	A20 mya1;
	mya1.m_test = 15;
	mya1.asubobj.m_testson = 120;
	A20 mya2 = mya1; // 直接复制数据的实现手法，递归式地去复制类的成员变量

	A3 a3;

	CTBSon myctbson1;
	CTBSon myctbson2 = myctbson1;

	C cc;
	C cc2 = cc;

	TC a;
	a.i = 100;
	a.s = "I Love China!";
	const char *p = a.s.c_str();
	TC b = std::move(a); // 导致结构/类TC移动构造函数的执行,数据移动不是std::move所为，而是string的移动构造函数所为
	const char *q = b.s.c_str();

	cout << "Over!\n";
	return 0;
}