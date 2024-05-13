#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

inline int myfunc0(int testv)
{
	return testv * (5 + 4) * testv;
	// int tempvalue = testv * (5 + 4) * testv;
	// return tempvalue;
}

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
		int i0 = myfunc(12);
		int i1 = myfunc(12 + 15);
		int a = 80;
		int i2 = myfunc(a + 15);

		int i3 = myfunc(rtnvalue() + 15);

		int i4 = myfunc(12);
		cout << i4 << endl;
	}

	cout << "Over!\n";
	return 0;
}
