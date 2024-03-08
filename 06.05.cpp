#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	void *p = malloc(0);
	char *q = new char[0];

	strcpy_s((char *)p, 100, "This is a test1!");
	strcpy_s(q, 100, "This is a test2!");

	printf("p=%s\n", p);
	printf("q=%s\n", q);

	delete[] q;
	free(p);

	cout << "Over!\n";
	return 0;
}