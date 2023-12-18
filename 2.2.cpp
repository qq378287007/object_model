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
	myobject(){};		   // 构造函数
	virtual ~myobject(){}; // 析构函数

	float getvalue() const // 普通成员函数
	{
		return m_value;
	}
	static int s_getcount() // 静态成员函数
	{
		return ms_scount;
	}
	virtual void vfrandfunc(){}; // 虚函数

protected:
	float m_value;		  // 普通成员变量
	static int ms_scount; // 静态成员变量
};

int main()
{
#if 0
	A1 aobj; // sizeof(aobj)=4
	cout << sizeof(aobj) << endl;
#endif

#if 0
	A2 aobj; // sizeof(aobj)=1,不管几个静态成员变量，sizeof的大小不增加
	cout << sizeof(aobj) << endl;
#endif

#if 0
	A3 aobj; // sizeof(aobj)=1
	cout << sizeof(aobj) << endl;
#endif

#if 0
	A4 aobj; // sizeof(aobj)=8
	cout << sizeof(aobj) << endl;
#endif

#if 0
	int ilen2 = sizeof(char *); // 8
	int ilen3 = sizeof(int *);	// 8
	cout << ilen2 << endl;
	cout << ilen3 << endl;
#endif

#if 1
	myobject obj;
	int ilen = sizeof(obj);
	cout << ilen << endl;
#endif

	cout << "Over!\n";
	return 0;
}
