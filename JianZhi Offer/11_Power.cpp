/*
 * 题目：数值的整数次方
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//标记返回值为0时，是否为正确输入的返回
	bool validReturn = true;
	double Power(double base, int exponent) {
		validReturn = true;
		if (equal(base, 0.0) && exponent < 0)
		{
			validReturn = false;
			return 0.0;
		}

		unsigned int absExponent = (unsigned int)exponent;
		if (exponent < 0)
			absExponent = (unsigned int)-exponent;

		double ret = PowerWithUnsignedNum(base, absExponent);

		if (exponent < 0)
			return 1.0 / ret;
		return ret;
	}
	

	double PowerWithUnsignedNum(double base, int exponent)
	{
		if (exponent == 0)
			return 1;
		else if (exponent == 1)
			return base;
		else
		{
			vector<double> ret(exponent + 1, 0);
			ret[0] = 1;
			ret[1] = base;

			for (int i = 2; i <= exponent; ++i)
			{
				//求base的exponent/2的值，用右移代替除法，提高效率
				double tmp = ret[exponent >> 1];
				tmp *= tmp;
				//用与运算代替求余
				if (i & 0x1 == 1)
					tmp *= base;
				ret[i] = tmp;
			}
			return ret[exponent];
		}//else
	}

	bool equal(double d1 , double d2)
	{
		if ((d1 - d2) > -0.0000001 && (d1 - d2 < 0.0000001))
			return true;
		return false;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.Power(0, 2) << endl;
//	cout << s.validReturn << endl;
//	system("pause");
//	return 0;
//}