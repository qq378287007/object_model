#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

struct Base
{
	virtual ~Base() {}
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};

struct Derive : Base
{
	virtual ~Derive() {}
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} // 只属于Derive的函数
};

int main()
{
	if (0)
	{
		Base *pb = new Derive(); // 基类指针指向一个子类对象
		pb->g();

		Derive myderive;
		Base &yb = myderive; // 基类引用引用的是一个子类对象
		yb.g();

		cout << typeid(*pb).name() << endl;
		cout << typeid(yb).name() << endl;

		Derive *pderive = dynamic_cast<Derive *>(pb);
		if (pderive != nullptr)
		{
			cout << "pb指向的实际是一个Derive类型" << endl;
			pderive->myselffunc(); // 调用属于子类自己的函数
		}
		const std::type_info &tp = typeid(*pb);

		Base *pb2 = new Derive();
		const std::type_info &tp2 = typeid(*pb2);
		if (tp == tp2) // 条件成立
			cout << "很好，类型相同" << endl;
		delete pb2;

		delete pb;
	}

	if (0)
	{
		cout << typeid(int).name() << endl;
		cout << typeid(Base).name() << endl;
		cout << typeid(Derive).name() << endl;
		Derive *pa3 = new Derive();
		cout << typeid(pa3).name() << endl;
		delete pa3;
	}

	if (1)
	{
		Base *pb = new Derive();

		Derive myderive;
		Base &yb = myderive;

		cout << typeid(*pb).name() << endl; // class Derive
		cout << typeid(yb).name() << endl;	// class Derive

		Base *pb2 = new Derive();
		const std::type_info &tp2 = typeid(*pb2);
		cout << tp2.name() << endl;

		//---------------------------------------
		printf("tp2地址为 :%p\n", &tp2);

		long long *pvptr = (long long *)pb2;	   // 指向对象pb2的指针转成long *型,大家注意，目前pb2对象里只有虚函数表指针
		long long *vptr = (long long *)(*pvptr); // 指向虚函数表(虚函数表首地址)

		printf("虚函数表首地址为: %p\n", vptr);
		printf("虚函数表首地址之前一个地址为: %p\n", vptr - 1); // 注意，long long在当前这个环境是8字节，所以vptr-1,其实得到的地址是往回走了8个地址

		// 取得这个地址中的内容
		long long *prttiiinfo = (long long *)(*(vptr - 1));
		prttiiinfo += 3; // 跳过8*3个字节
		long long *ptypeinfoaddr = (long long *)(*prttiiinfo);
		const std::type_info *ptypeinfoaddrreal = (const std::type_info *)ptypeinfoaddr;
		printf("ptypeinfoaddrreal地址为 :%p\n", ptypeinfoaddrreal);
		//cout << ptypeinfoaddrreal->name() << endl; // 结果class Derive
		cout << typeid(int).name() << endl; // 输出int
	}

	cout << "Over!\n";
	return 0;
}
