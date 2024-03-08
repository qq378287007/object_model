#include <iostream>
using namespace std;

struct JI
{
	JI() { cout << "JI::JI()" << endl; }
	virtual ~JI() { cout << "JI::~JI()" << endl; }
};

struct A : JI
{
	int m_i, m_j;

	// private:
	//	A& operator=(const A& tmp);
	//	A(const A& tmptime);

	// public:
	//	A& operator=(const A& tmp) = delete;
	//	A(const A& tmptime) = delete;

	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }

	A &operator=(const A &tmp)
	{
		if (&tmp == this)
			return *this;

		// static_cast<JI&>(*this) = tmp; // 调用父类的拷贝赋值运算符
		// JI::operator=(tmp);// 调用父类的拷贝赋值运算符

		m_i = tmp.m_i;
		m_j = tmp.m_j;
		cout << "A::operator=(const A&)" << endl;
		return *this;
	}
	A(const A &tmp)
	//: JI(tmp) // 显式调用父类拷贝构造函数
	{
		// 编译器会插入代码，调用父类的构造函数或者拷贝构造函数？
		m_i = tmp.m_i;
		m_j = tmp.m_j;
		cout << "A::A(const A&)" << endl;
	}
};

struct ParC
{
	virtual ~ParC() { cout << "ParC::~ParC()" << endl; }
};
struct MemC
{
	ParC m_j;

	~MemC() { cout << "MemC::~MemC()" << endl; }
};

int main()
{
	{
		A aobj;
		aobj.m_i = 15;
		aobj.m_j = 20;

		A aobj2 = aobj; // 执行拷贝构造

		A aobj3;
		aobj3.m_i = 13;
		aobj3.m_j = 16;
		aobj2 = aobj3; // 执行拷贝复制运算符
	}

	{
		MemC mobj;
	}

	cout << "Over!\n";
	return 0;
}
