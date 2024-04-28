#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

class MYACLS
{
public:
	virtual void myvirfunc1()
	{
		cout << "虚函数MYACLS::myvirfunc1()执行了" << endl;
	}
	virtual void myvirfunc2()
	{
		cout << "虚函数MYACLS::myvirfunc2()执行了" << endl;
	}
};

int main()
{
	{
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc1);
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc2);
		cout << sizeof(MYACLS) << endl; // 8字节
		
		MYACLS *pmyobj = new MYACLS();
		pmyobj->myvirfunc1();
		pmyobj->myvirfunc2();
		delete pmyobj;
	}

	cout << "Over!\n";
	return 0;
}