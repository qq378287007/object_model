#include <stdio.h>
#include <iostream>
using namespace std;

// A代表类名，m代表成员名，类成员偏移地址
#define GET(A, m) (long long)(&((A *)nullptr)->m)

#pragma pack(1) // 1字节对齐
class MYACLS
{
public:
	int m_i;
	static int m_si; // 声明
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;

public:
	char m_c; // 1字节
	int m_n;  // 4字节

private:
	int m_pria;
	int m_prib;

public:
	void printMemPoint() // 因为要打印私有的成员变量偏移值，只能用成员函数打印
	{
		cout << "Print member variable offset values---------------" << endl;
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i); // 类名不省略，打印偏移值，否则打印成员变量的物理地址
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
		printf("MYACLS::m_k = %d\n", &MYACLS::m_k);
		printf("MYACLS::m_c = %d\n", &MYACLS::m_c);
		printf("MYACLS::m_n = %d\n", &MYACLS::m_n);

		printf("MYACLS::m_pria = %d\n", &MYACLS::m_pria);
		printf("MYACLS::m_prib = %d\n", &MYACLS::m_prib);
		cout << "------------------------" << endl;
		cout << "MYACLS::m_prib = " << GET(MYACLS, m_prib) << endl;
	}

public:
	virtual void mfv() {}
};
#pragma pack()		  // 恢复缺省对齐
int MYACLS::m_sj = 0; // 定义

int main()
{
	{
		cout << sizeof(MYACLS) << endl; // 4*6+1+8

		MYACLS myobj;
		myobj.m_k = 8;
		myobj.m_i = 2;
		myobj.m_j = 5;

		printf("&myobj = %p\n", &myobj);
		printf("&myobj.m_i = %p\n", &myobj.m_i);
		printf("&myobj.m_j = %p\n", &myobj.m_j);
		printf("&myobj.m_k = %p\n", &myobj.m_k);
		printf("&myobj.m_c = %p\n", &myobj.m_c);
		printf("&myobj.m_n = %p\n", &myobj.m_n);
	}

	{
		MYACLS *pmyobj = new MYACLS();
		printf("pmyobj = %p\n", pmyobj);
		printf("&pmyobj->m_i = %p\n", &pmyobj->m_i);
		printf("&pmyobj->m_j = %p\n", &pmyobj->m_j);
		printf("&pmyobj->m_k = %p\n", &pmyobj->m_k);
		printf("&pmyobj->m_c = %p\n", &pmyobj->m_c);
		printf("&pmyobj->m_n = %p\n", &pmyobj->m_n);
		pmyobj->printMemPoint();
	}

	int MYACLS::*mypoint = &MYACLS::m_n;
	printf("pmyobj->m_n offset address = %d\n", mypoint);

	cout << "Over!\n";
	return 0;
}
