#include <cstdio>
#include <iostream>
using namespace std;

struct Grand // 爷爷类
{
	int m_grand;
};

struct A0_1 : Grand
{
};
struct A0_2 : Grand
{
};
struct C0 : A0_1, A0_2
{
};

struct A1 : virtual Grand // 注意这里用了virtual
{
	int m_a1;
	// 8
	// 4(m_a1)
};
struct A2 : virtual Grand // 注意这里用了virtual
{
	int m_a2;
	// 8
	// 4(m_a2)
};
struct C1 : A1, A2 // 这里不需要virtual
{
	int m_c1;
	// 8
	// 4(m_a1)
	// 8
	// 4, 4(m_a2, m_c1)
};

int main()
{
	{
		cout << sizeof(Grand) << endl;
		cout << sizeof(A0_1) << endl;
		cout << sizeof(A0_2) << endl;
		cout << sizeof(C0) << endl;
	}

	{

		C0 c0;
		c0.A0_1::m_grand = 5;
		c0.A0_2::m_grand = 8;
		// c0.m_grand = 12; //error，访问不明确
	}

	{
		A1 a1;
		A2 a2;

		C1 c1;
		c1.m_grand = 12; // ok
	}
	cout << "************\n";
	{
		cout << sizeof(Grand) << endl; // 4
		cout << sizeof(A1) << endl;	   // 16
		cout << sizeof(A2) << endl;	   // 16
		cout << sizeof(C1) << endl;	   // 40
	}
	cout << "************\n";

	printf("&C1::m_a1 = %d\n", &C1::m_a1);
	printf("&C1::m_a2 = %d\n", &C1::m_a2);
	printf("&C1::m_c1 = %d\n", &C1::m_c1);
	printf("&C1::m_grand = %d\n", &C1::m_grand);

	cout << "Over!\n";
	return 0;
}
