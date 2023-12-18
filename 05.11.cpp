#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

// int myfunc(int testv)
// inline int myfunc(int testv)
//{
//	//return testv * (5 + 4) * testv;
//	int tempvalue = testv * (5 + 4) * testv;
//	return tempvalue;
// }

inline int myfunc(int testv)
{
	if (testv > 10)
	{
		testv--;
		myfunc(testv);
	}
	return testv;
}

int rtnvalue()
{
	return 5;
}

int main()
{

	{
		// int i = myfunc(12);
		// int i = myfunc(12+15);
		/*int a = 80;
		int i = myfunc(a + 15);*/

		/*	int i = myfunc(rtnvalue() + 15);*/

		int i = myfunc(12);
		cout << i << endl;
	}

	cout << "Over!\n";
	return 0;
}
