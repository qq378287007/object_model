#include <iostream>
using namespace std;

class A
{
private:
	A() {}
	friend class B; // B可以调用A的私有构造函数
};
class B : virtual public A // 虚继承A
{
public:
	int m_b;
};
// 虚基类A的构造函数由孙子类C调用
// 但虚基类A的构造函数私有，只有友元类B能调用，孙子类C无法调用
// 无法创建C类，即B类无法被继承
class C : public B
{
public:
	int m_c;
};

class A2
{
private:
	virtual void virfunc()
	{
		myfunc();
	}
	void myfunc()
	{
		cout << "A::myfunc()" << endl;
	}
};

int main()
{

	{
		B myobjb;
		myobjb.m_b = 15;

		// C myobjc;
		// myobjc.m_c = 20;
	}

	{
		A2 aobj;
		(reinterpret_cast<void (*)()>(**(long ***)(&aobj)))();
		// 通过虚函数表指针调用虚函数
		// long*** pvptr = (long ***)&aobj;
		// long** vptr = *pvptr;
		// typedef void(*Func)();
		// Func f = (Func)*vptr;
		// f();
	}

	cout << "Over!\n";
	return 0;
}
