#include <iostream>
#include <time.h>
using namespace std;

class X
{
public:
	int m_i;
	int *p_mi; // 整型指针，其他类型指针都可以，道理相同
	// X(const X& tmpx)
	//{
	//	//m_i = tmpx.m_i;
	//	cout << "X类的拷贝构造函数被调用" << endl;
	// }
	X(const X &tmpx)
	{
		p_mi = new int(100); // 为指针类型成员变量单独分配内存
		memcpy(p_mi, tmpx.p_mi, sizeof(int));
		m_i = tmpx.m_i;
		cout << "X类的拷贝构造函数被调用" << endl;
	}

	X()
	{
		m_i = 0;
		p_mi = new int(100);
		cout << "X类的构造函数被调用" << endl;
	}
	~X()
	{
		delete p_mi;
		cout << "X类的析构函数被调用" << endl;
	}
	// explicit X(int value) :m_i(value) //类型转换构造函数（带有一个形参的拷贝构造函数）
	X(int value) : m_i(value) // 类型转换构造函数（带有一个形参的拷贝构造函数）
	{
		p_mi = new int(100);
		cout << "X类的X(int)构造函数被调用" << endl;
	}
};

int main()
{

	//{
	//	cout << "----begin----" << endl;
	//	X x10(1000);
	//	cout << "--------" << endl;
	//	X x11 = 1000;
	//	cout << "--------" << endl;
	//	X x12 = X(1000);
	//	cout << "--------" << endl;
	//	X x13 = (X)1000;
	//	cout << "----end----" << endl;

	//}

	//{
	//	//编译器视角
	//	X x10;   //编译器视角是不调用构造函数的
	//	x10.X::X(1000);
	//}
	//{
	//	//编译器视角
	//	X _tmp0;          //编译器生成的临时对象
	//	_tmp0.X::X(1000); //带一个参数的构造函数被调用
	//	X x12;
	//	x12.X::X(_tmp0);  //拷贝构造函数被调用
	//	_tmp0.X::~X();    //调用析构
	//}

	{
		X x0;
		x0.m_i = 150;
		X x1(x0);
		cout << x1.m_i << endl;
	}

	cout << "Over!\n";
	return 0;
}