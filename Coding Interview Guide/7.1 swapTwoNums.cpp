/*
7.1 不用额外的变量交换两个整数的值
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*不用额外变量，用普通+-法实现*/
void swapTwoNums(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

/*使用位运算*/
void swapTwoNums2(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}