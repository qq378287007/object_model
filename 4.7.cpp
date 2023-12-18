// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;


class Base
{
public:
	virtual  void mybvirfunc() {}
	int m_bi;

public:
	Base()
	{
		printf("Base::Base()构造函数的this指针是：%p!\n", this);
	}
};

class Base2
{
public:
	virtual  void mybvirfunc2() {}
	int m_b2i;
public:
	Base2()
	{
		printf("Base2::Base2()构造函数的this指针是：%p!\n", this);
	}

};


//class MYACLS :public Base
class MYACLS :public Base, public Base2
{
public:
	int m_i;
	int m_j;

	virtual void myvirfunc()
	{
	}
	MYACLS() //构造函数
	{
		int abc = 1; //方便加断点
		printf("MYACLS::MYACLS()构造函数的this指针是：%p!\n", this);
	}
	~MYACLS()//析构函数
	{
		int def = 0; //方便加断点
	}
};

int main()
{
	
	/*{
		MYACLS aaa;
	}*/

	//{
	//	cout << sizeof(MYACLS) << endl;
	//	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
	//	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

	//}
	//{
	//	MYACLS myobj;
	//	myobj.m_i = 3;
	//	myobj.m_j = 6;
	//	cout << "方便加断点" << endl;
	//}

	{
		cout << sizeof(MYACLS) << endl;
		printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
		printf("MYACLS::m_b2i = %d\n", &MYACLS::m_b2i);
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
	}

	{
		MYACLS myobj;
		myobj.m_i = 3;
		myobj.m_j = 6;		
		myobj.m_bi = 9;
		myobj.m_b2i = 12;

		Base2* pbase2 = &myobj; //注意结果，myobj地址为0x009ffb0c，而pbase2给值后是0x009ffb14，因为this指针调整是要往后跳8字节的，所以这里myobj地址值+8字节后给了pbase2
		//Base2* pbase3 = (Base2*)(((char*)& myobj) + sizeof(Base));

		Base* pbase = &myobj;   //pbase的地址就是myobj对象的首地址，因为this不需要调整，Base类的首地址和MYACLS类的首地址相同

		Base2* pbase3 = new MYACLS();  //父类指针new子类对象，返回的地址是：0x01054bc8，实际这里分配是24字节
		MYACLS* psubobj = (MYACLS*)pbase3;  //得到的地址是0x01054bc0 比pbase3指向的地址少了8字节
		//delete pbase3; //报异常 ，据此，可以认为pbase3里返回的地址不是分配的首地址，是this指针调整后的地址，而new分配的真正的内存首地址应该是psubobj指向的那个地址
		delete psubobj;//成功，验证了psubobj里才是真正的首地址的说法


		MYACLS* pmyobj = new MYACLS();
		pmyobj->m_i = 3;
		pmyobj->m_j = 6;
		pmyobj->m_bi = 9;
		pmyobj->m_b2i = 12;


		cout << "方便加断点" << endl;
	}

	

 	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
