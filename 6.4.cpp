// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class A
{
public:
	//A()
	//{
	//	cout << "A::A()缺省构造函数执行了" << endl;
	//}
	//~A()
	//{
	//	cout << "A::~A()析构函数执行了" << endl;
	//}
	int m_i; 	
};

//void myfunc()
//{	
//	static A s_aobj1;
//	static A s_aobj2;
//	printf("s_aobj1的地址是%p\n", &s_aobj1);
//	printf("s_aobj2的地址是%p\n", &s_aobj2);
//}
//const A& myfunc()
//{
//	static A s_aobj1;	
//	printf("s_aobj1的地址是%p\n", &s_aobj1);	
//	return s_aobj1;
//}

void myfunc()
{
	//static A s_aobj[5];
	static A s_aobj[1000'0000]; //中间有'的数字是C++14新标准中支持的, '是数字分隔符
	for (int i = 0; i < 1000'0000; i++)
	{
		s_aobj[i].m_i = i; //这对于数组来说，一定算一件有用的事
	}
	printf("s_aobj数组的首地址是%p\n", s_aobj);
}


int main()
{
	//{
	//	myfunc();//调用一次
	//	myfunc(); //又调用一次
	//}

	myfunc();
	printf("开始进入while循环\n");
	while (1)
	{
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
