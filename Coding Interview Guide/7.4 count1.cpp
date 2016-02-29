/*
7.4 整数的二进制中统计1的个数
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int count1(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 0x1;
		n >>= 1;
	}//while

	return count;
}

int count2(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1); /*每执行一次，都会抹掉最右端的1*/
		++count;
	}//while
	return count;
}

int count3(int n)
{
	int count = 0;
	while (n)
	{
		n -= (n & (~n + 1)); /*抹掉最右端的1*/
		++count;
	}//while
	return count;
}

int main()
{
	cout << count1(9) << endl;
	cout << count2(9) << endl;
	cout << count3(9) << endl;

	system("pause");
	return 0;
}