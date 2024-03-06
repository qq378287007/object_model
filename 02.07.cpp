#include <iostream>
#include <time.h>
using namespace std;

struct CTempValue
{
	int val1;
	int val2;
	CTempValue(int v1 = 0, int v2 = 0)
		: val1(v1), val2(v2)
	{
		cout << "CTempValue::CTempValue(int, int)" << endl;
		cout << "val1 = " << val1 << endl;
		cout << "val2 = " << val2 << endl;
	}
	CTempValue(const CTempValue &t)
		: val1(t.val1), val2(t.val2)
	{
		cout << "CTempValue::CTempValue(const CTempValue &)" << endl;
	}
	virtual ~CTempValue()
	{
		cout << "CTempValue::~CTempValue()" << endl;
	}
};

CTempValue Double1(const CTempValue &ts)
{
	CTempValue tmpm; // 构造+析构函数
	tmpm.val1 = ts.val1 * 2;
	tmpm.val2 = ts.val2 * 2;
	return tmpm; // 拷贝构造+析构
}

CTempValue Double2(const CTempValue &ts)
{
	return CTempValue(ts.val1 * 2, ts.val2 * 2); // 构造+析构
}

// 编译器视角
// CTempValue& tmpobj; //分配内存空间
// void Double2(CTempValue& tmpobj, const CTempValue& ts) //插入一个tmpobj引用参数
// {
//		tmpobj.CTempValue::CTempValue(ts.val1 * 2, ts.val2 * 2);//编译器手工调用构造函数
// }
// tmpobj.CTempValue::~CTempValue();//析构

struct CTempValue2
{
	int val1;
	int val2;
	CTempValue2(int v1 = 0, int v2 = 0)
		: val1(v1), val2(v2) {}
	CTempValue2(const CTempValue &t)
		: val1(t.val1), val2(t.val2) {}
	virtual ~CTempValue2() {}
};

CTempValue2 Double(const CTempValue2 &ts)
{
	CTempValue2 tmpm; // 构造+析构函数
	tmpm.val1 = ts.val1 * 2;
	tmpm.val2 = ts.val2 * 2;
	return tmpm; // 拷贝构造+析构
}

int main()
{
	if (0)
	{
		CTempValue ts1(10, 20);
		Double1(ts1);
		CTempValue ts2 = Double2(ts1);
	}

	CTempValue2 ts(10, 20);
	clock_t start = clock(); // 程序开始到本行执行时所用的毫秒数
	cout << "start = " << start << endl;
	for (int i = 0; i < 1000000; i++)
		Double(ts);
	clock_t end = clock();
	cout << "end = " << end << endl;
	cout << "end - start = " << end - start << endl;

	cout << "Over!\n";
	return 0;
}

//g++ -fno-elide-constructors 02.07.cpp -o 02.07 && 02.07