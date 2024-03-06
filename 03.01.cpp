#include <iostream>
using namespace std;

class A
{
public:
	int i;
	virtual void testfunc() {}
};

int main()
{
	A a;
	char *p1 = reinterpret_cast<char *>(&a);	 // 0x006ff730 类型转换，这属于硬转，a是对象首地址
	char *p2 = reinterpret_cast<char *>(&(a.i)); // 0x006ff734
	if (p1 == p2)
		cout << "Virtual function table pointer located at the end of object memory" << endl;
	else
		cout << "Virtual function table pointer located at the start of object memory" << endl; // 本条件会成立

	cout << "Over!\n";
	return 0;
}