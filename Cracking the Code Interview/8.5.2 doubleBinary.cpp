/*
* 面试题8.5.2 将0~1之间的实数用32位二进制表示。
* 给定一个介于0和1之间的实数如（0.72）类型为double，打印它的二进制表示。
* 如果该数字无法精确的用32位以内的二进制表示，打印ERROR。
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Solution{
public:
	//乘2与1比较
	string doubleBinary(double num)
	{
		if (num >= 1 || num <= 0)
			return "ERROR";

		string ret = ".";
		while (num)
		{
			if (ret.length() > 32)
				return "ERROR";
			num *= 2;
			if (num >= 1)
			{
				ret += '1';
				num -= 1;
			}
			else{
				ret += '0';
			}//else
		}//while
		return ret;
	}

	//乘2与1比较
	string doubleBinary2(double num)
	{
		if (num >= 1 || num <= 0)
			return "ERROR";

		string ret = ".";
		double tmp = 0.5;
		while (num)
		{
			if (ret.length() > 32)
				return "ERROR";
			if (num >= tmp)
			{
				ret += '1';
				num -= tmp;
			}
			else{
				ret += '0';
			}//else
			tmp /= 2;
		}//while
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.doubleBinary(0.75) << endl;

	system("pause");
	return 0;
}