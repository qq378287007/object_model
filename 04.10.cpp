#include <cstdio>
#include <iostream>
using namespace std;

class Grand // 爷爷类
{
public:
	int m_grand; // 4
};

class A1 : virtual public Grand // 注意这里用了virtual
{
public:
	int m_a1;
	// 8(vbptr)
	// 4(m_a1)+4(m_grand)
};
class A2 : virtual public Grand // 注意这里用了virtual
{
public:
	int m_a2;
	// 8(vbptr)
	// 4(m_a2)+4(m_grand)
};
class C1 : public A1, public A2 // 这里不需要virtual
{
public:
	int m_c1;
	// 8(vbptr A1)
	// 4(m_a1)+4
	// 8(vbptr A2)
	// 4(m_a2)+4(m_c1)
	// 4(m_grand)+4
};

int main()
{
	{
		cout << sizeof(Grand) << endl;
		cout << sizeof(A1) << endl;
		cout << sizeof(A2) << endl;
		cout << sizeof(C1) << endl;

		printf("&C1::m_a1=%d\n", &C1::m_a1);
		printf("&C1::m_a2=%d\n", &C1::m_a2);
		printf("&C1::m_c1=%d\n", &C1::m_c1);
		printf("&C1::m_grand=%d\n", &C1::m_grand);
	}

	{
		C1 c1obj;
		c1obj.m_grand = 2;
		c1obj.m_a1 = 5;
		c1obj.m_a2 = 6;
		c1obj.m_c1 = 8;

		A2 &pa2 = c1obj;
		pa2.m_grand = 8;
		pa2.m_a2 = 9;
		printf("m_grand=%d\n", c1obj.m_grand);
		printf("m_a2=%d\n", c1obj.m_a2);

		A2 *pa3 = &c1obj;
		pa3->m_grand = 80;
		pa3->m_a2 = 90;
		printf("m_grand=%d\n", c1obj.m_grand);
		printf("m_a2=%d\n", c1obj.m_a2);
	}

	{
		A1 a1obj;
		a1obj.m_grand = 2;
	}
	{
		C1 c2obj;
	}

	cout << "Over!\n";
	return 0;
}
