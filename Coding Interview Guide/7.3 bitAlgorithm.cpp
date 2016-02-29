/*
7.3 只用位运算不用算术运算实现整数的加减乘除运算
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int add(int a, int b)
{
	int sum = a;
	while (b)
	{
		sum = a ^ b;
		b = (a&b) << 1;
		a = sum;
	}//while
	return sum;
}

/*求相反数*/
int negNum(int a)
{
	return add(~a, 1);
}

/*减法*/
int minusFun(int a, int b)
{
	return add(a, negNum(b));
}

int multi(int a, int b)
{
	int res = 0;
	while (b != 0)
	{
		if ((b & 1) != 0)
		{
			res = add(res, a);
		}//if
		a <<= 1;
		b >>= 1;
	}//while
	return res;
}

/*判断是否为负*/
bool isNeg(int n)
{
	return n < 0;
}

/*除法辅助函数*/
int divFun(int a, int b)
{
	int x = isNeg(a) ? negNum(a) : a;
	int y = isNeg(b) ? negNum(b) : b;

	int res = 0;
	for (int i = 31; i>-1; i = minusFun(i, 1))
	{
		if ((x >> i) >= y)
		{
			res |= (1 << i);
			x = minusFun(x, y << i);
		}//if
	}//for

	return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

/*完整除法*/
int divide(int a, int b)
{
	if (0 == b)
	{
		cout << "divisor is 0" << endl;
		throw(runtime_error("divisor is 0!"));
	}

	if (a == INT_MIN && b == INT_MIN)
		return 1;
	else if (b == INT_MIN)
		return 0;
	else
	{
		if (a == INT_MIN)
		{
			int res = divFun(add(a, 1), b);
			return add(res, divFun(minusFun(a, multi(res, b)), b));
		}//if
		else
			return divFun(a, b);
	}//else
}

int main()
{
	cout << add(1, 2) << endl;
	cout << minusFun(1, 2) << endl;
	cout << multi(1, 2) << endl;
	cout << divide(INT_MIN, INT_MAX) << endl;

	system("pause");
	return 0;
}