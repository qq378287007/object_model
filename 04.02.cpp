#include <cstdio>
#include <iostream>
using namespace std;

int *ptest = new int(120);
int g1;
int g2;

int g3 = 12;
int g4 = 32;
int g5;
int g6 = 0;
static int g7;
static int g8 = 0;
static int g9 = 10;
void mygfunc()
{
	return;
}
// 定义一个类
class MYACLS
{
public:
	int m_i;
	static int m_si; // 声明
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;
};
int MYACLS::m_sj = 12; // 定义

int main()
{
	{
		int e_mytest = 9; // 程序运行时临时放在栈中
	}

	{
		printf("&ptest=%p\n", &ptest);
		printf("&g1=%p\n", &g1);
		printf("&g2=%p\n", &g2);
		printf("&g3=%p\n", &g3);
		printf("&g4=%p\n", &g4);
		printf("&g5=%p\n", &g5);
		printf("&g6=%p\n", &g6);
		printf("&g7=%p\n", &g7);
		printf("&g8=%p\n", &g8);
		printf("&g9=%p\n", &g9);
		printf("&MYACLS::m_sj=%p\n", &(MYACLS::m_sj));
		printf("&mygfunc()=%p\n", mygfunc);
		printf("&main()=%p\n", main);

		int i = 7;
		printf("&i=%p\n", &i);
	}

	cout << "Over!\n";
	return 0;
}
