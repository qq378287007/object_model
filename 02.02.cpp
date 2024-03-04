#include <iostream>
using namespace std;

class A1
{
	int a = 100;
};
class A2
{
	static int a;
	static int b;
};
class A3
{
	static void sfunc(){};
	void myfunc(){};
};
class A4
{
	virtual void myfunc3(){};
	virtual void myfunc4(){};
};

class myobject
{
public:
	myobject(){};								  // 构造函数
	virtual ~myobject(){};						  // 析构函数
	float getvalue() const { return m_value; }	  // 普通成员函数
	static int s_getcount() { return ms_scount; } // 静态成员函数
	virtual void vfrandfunc(){};				  // 虚函数

protected:
	float m_value;		  // 普通成员变量
	static int ms_scount; // 静态成员变量
};

int main()
{
	cout << sizeof(A1) << endl; // 4
	cout << sizeof(A2) << endl; // 1
	cout << sizeof(A3) << endl; // 1
	cout << sizeof(A4) << endl; // 8

	cout << sizeof(char *) << endl; // 8
	cout << sizeof(int *) << endl;	// 8

	cout << sizeof(myobject) << endl; // 16

	cout << "Over!\n";
	return 0;
}
