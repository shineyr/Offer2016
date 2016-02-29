/*
7.2 不用任何比较判断找出两个数中较大的数
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*功能：如果n=1返回0，如果n=0返回1*/
int flip(int n)
{
	return n ^ 1;
}

/*返回整数n的符号,正数和0返回1，负数返回0*/
int sign(int n)
{
	return flip((n >> 31) & 1);
}

/*方法一，局限性：a-b的值不可溢出*/
int getMax1(int a, int b)
{
	int c = a - b;
	int scA = sign(c);
	int scB = flip(scA);
	return a*scA + b*scB;
}

/*方法二：解决溢出*/
int getMax2(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int difSab = sa^sb;

	int sameSab = flip(difSab);

	int returnA = difSab * sa + sameSab *sc;
	int returnB = flip(returnA);

	return returnA * a + returnB * b;
}
//
//int main()
//{
//	cout << getMax1(1, 2) << endl;
//	cout << getMax2(1, 2) << endl;
//
//	system("pause");
//	return 0;
//}