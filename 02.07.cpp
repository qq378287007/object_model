#include <iostream>
#include <time.h>
using namespace std;

class CTempValue
{
public:
	int val1;
	int val2;

public:
	CTempValue(int v1 = 0, int v2 = 0) : val1(v1), val2(v2) // 构造函数
	{
		//	cout << "调用了CTempValue类的构造函数!" << endl;
		//	cout << "val1 = " << val1 << endl;
		//	cout << "val2 = " << val2 << endl;
	}
	CTempValue(const CTempValue &t) : val1(t.val1), val2(t.val2) // 拷贝构造函数
									  {
										  //	cout << "调用了CTempValue类的拷贝构造函数!" << endl;
									  };
	virtual ~CTempValue() // 析构函数
		{
			//	cout << "调用了CTempValue类的析构函数!" << endl;
		};
};
// CTempValue Double(CTempValue& ts) //第一个版本
//{
//	CTempValue tmpm; //这里会消耗我们一个构造和一个析构函数的调用
//	tmpm.val1 = ts.val1 * 2;
//	tmpm.val2 = ts.val2 * 2;
//	return tmpm;  //断点设置到这里，发现调用了拷贝构造函数和析构函数，这表示生成了临时对象
// }
CTempValue Double(CTempValue &ts) // 第二个版本
{
	return CTempValue(ts.val1 * 2, ts.val2 * 2); // 临时对象
}

// 编译器视角
// void Double(CTempValue& tmpobj, CTempValue& ts1) //编译器会插入一个tmpobj参数
//{
//	tmpobj.CTempValue::CTempValue(ts1.val1 * 2, ts1.val2 * 2);//编译器手工调用构造函数
//	return;
// }

int main()
{
	//{
	//	CTempValue ts1(10, 20);
	//	//Double(ts1);
	//	CTempValue ts2 = Double(ts1);

	//}

	//{
	//	CTempValue ts1;
	//	ts1.CTempValue::CTempValue(10, 20);
	//	CTempValue tmpobj;
	//	Double(tmpobj, ts1);

	//}

	CTempValue ts1(10, 20);
	clock_t start, end;
	start = clock(); // 程序开始到本行执行时所用的毫秒数
	cout << "start = " << start << endl;
	for (int i = 0; i < 1000000; i++)
	{
		Double(ts1);
	}
	end = clock();
	cout << "end = " << end << endl;
	cout << "end - start = " << end - start << endl;

	cout << "Over!\n";
	return 0;
}
