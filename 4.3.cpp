// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

#define GET(A,m) (int)(&((A*)0)->m)  //A代表类名，m代表成员名，这里用了一个0，违反常规的写法，但能输出出一个类成员偏移地址来



#pragma pack (1) //1字节对齐方式
class MYACLS
{
public:
	int m_i;
	static int m_si; //这是声明不是定义
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;

public:
	char m_c; //1字节
	int m_n;  //4字节

private:
	int m_pria;
	int m_prib;

public:
	void printMemPoint() //因为要打印私有的成员变量偏移值，只能用成员函数打印
	{
		cout << "打印成员变量偏移值---------------" << endl;
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);//类名不要省略，必须要有，打印的才是偏移值，否则打印的就是对象的该成员变量的物理地址了
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
		printf("MYACLS::m_k = %d\n", &MYACLS::m_k);
		printf("MYACLS::m_c = %d\n", &MYACLS::m_c);
		printf("MYACLS::m_n = %d\n", &MYACLS::m_n);

		printf("MYACLS::m_pria = %d\n", &MYACLS::m_pria);
		printf("MYACLS::m_prib = %d\n", &MYACLS::m_prib);
		cout << "------------------------" << endl;		
		cout << "MYACLS::m_prib = " << GET(MYACLS, m_prib) << endl; //利用GET宏定义来打印m_prib成员变量的偏移值
	}

public:
	virtual void mfv() {}
};
#pragma pack() //取消指定的1字节对齐，恢复缺省对齐（原来是多少就恢复成多少）
int MYACLS::m_sj = 0; //这才是定义


int main()
{
	/*{
		MYACLS myobj;
		cout << sizeof(myobj) << endl;

		myobj.m_k = 8;
		myobj.m_i = 2;
		myobj.m_j = 5;
		cout << "断点设置在这里" << endl;
	}*/

	{

		MYACLS myobj;
		myobj.m_i = myobj.m_j = myobj.m_k = 0;
		cout << sizeof(myobj) << endl;
		printf("myobj.m_i = %p\n", &myobj.m_i);
		printf("myobj.m_j = %p\n", &myobj.m_j);
		printf("myobj.m_k = %p\n", &myobj.m_k);
		printf("myobj.m_c = %p\n", &myobj.m_c);
		printf("myobj.m_n = %p\n", &myobj.m_n);


		MYACLS* pmyobj = new MYACLS();
		printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
		printf("pmyobj->m_j = %p\n", &pmyobj->m_j);
		printf("pmyobj->m_k = %p\n", &pmyobj->m_k);
		printf("pmyobj->m_c = %p\n", &pmyobj->m_c);
		printf("pmyobj->m_n = %p\n", &pmyobj->m_n);

		pmyobj->printMemPoint();

		int MYACLS::*mypoint = &MYACLS::m_n;
		printf("pmyobj->m_n偏移地址 = %d\n", mypoint);

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