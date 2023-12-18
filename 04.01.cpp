#include <iostream>
#include <time.h>
using namespace std;
//
// string myvar;  //定义全局量，字符串型
//
////定义一个类
// class A
//{
// public:
//	/*int myfunc()
//	{
//		return myvar;
//	}*/
//	int myfunc();
// private:
//	int myvar; //同全局量同名的成员变量
// };
//
// int A::myfunc()
//{
//	return myvar;
//	//return ::myvar;
// }
//
// int  myfunc()
//{
//	return myvar;
// }

typedef string mytype;
class A
{
	typedef int mytype;

public:
	void myfunc(mytype tmpvalue);
	// void myfunc(mytype tmpvalue) //这个mytype是string类型
	//{
	//	m_value = tmpvalue;
	// }

private:
	// typedef int mytype;
	mytype m_value; // 这个mytype是int类型
};

void A::myfunc(mytype tmpvalue) // 这个mytype又变成了int类型，但若在类中定义myfunc，那么参数中出现的mytype是string类型
{
	m_value = tmpvalue;
}

void myfunc(mytype tmpvalue) // 这个mytype就是string类型
{
	string mvalue = tmpvalue;
}

int main()
{

	cout << "Over!\n";
	return 0;
}
