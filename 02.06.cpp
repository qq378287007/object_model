#include <iostream>
using namespace std;

class X
{
public:
	int m_i;
	X(const X &tmpx)
	{
		m_i = tmpx.m_i;
		cout << "X::X(const X &)" << endl;
	}
	X()
	{
		m_i = 0;
		cout << "X::X()" << endl;
	}
	~X()
	{
		cout << "X::~X()" << endl;
	}

public:
	void functest()
	{
		cout << "X::functest()" << endl;
	}
};

void func1(X tmpx)
{
}

X func2()
{
	X x0;
	return x0;
}

int main()
{
	{
		X x0; // X::X()
		x0.m_i = 15;

		X x1 = x0; // X::X(const X &)
		X x2(x0);  // X::X(const X &)
		X x3 = x0; // X::X(const X &)

		// X::~X()
		// X::~X()
		// X::~X()
		// X::~X()

		//	//步骤一：定义一个对象，为对象分配内存，但这里编译器内部并没有调用构造函数。
		//  //如果以编译器的眼光看X x3_2，则不会调用构造函数。
		//	//除非编译器主动增加这种x3_2.X::X();这种代码行到现有的代码中
		//	X x3_2;
		//	//步骤二：直接调用对象的拷贝构造函数去了
		//	x3_2.X::X(x0);
	}
	cout << "*****************" << endl;
	{
		X x0;
		func1(x0);
		// 程序员视角（现代编译器视角）
		// X tmpx = x0;//编译器在func1函数空间内构造了tmpx对象，函数返回前析构掉。

		//	老编译器视角
		//	X tmpobj;  //编译器产生出来一个临时对象
		//	tmpobj.X::X(x0); //调用拷贝构造函数
		//	func(tmpobj); //用临时对象调用func
		//	tmpobj.X::~X(); //func()被调用完成后，析构函数被调用
		//	void func1(X &tmpx){} //函数参数也变成了引用
	}
	cout << "*****************" << endl;
	{
		X my = func2();

		// 编译器视角
		// X my;	//分配对象内存空间
		// void func2(X & my) // 传递引用参数
		//{
		//	X x0; // 调用构造函数，编译器内部有诸如x0.X::X()这种代码
		//	my.X::X(x0); // 调用拷贝构造函数
		//}
	}
	cout << "*****************" << endl;
	{
		func2().functest();

		// 编译器视角
		// X my;	//分配对象内存空间，未调用构造函数
		// void func2(X & my) // 传递引用参数
		//{
		//	X x0; // 调用构造函数，编译器内部有诸如x0.X::X()这种代码
		//	my.X::X(x0); // 调用拷贝构造函数
		//}
		// my.functest();
		// my.X::~X();// 函数执行完后，调用析构函数
	}
	cout << "*****************" << endl;
	{
		X (*pf)
		(); // 定义函数指针
		pf = func2;
		pf().functest();

		// 编译器视角
		// void (*pf)(X &);
		// pf = func2;

		// X my;
		// pf(my); // 传递引用，内部调用拷贝构造函数
		// my.functest();
		// my.X::~X();
	}

	cout << "Over!\n";
	return 0;
}
