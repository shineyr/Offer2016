/*
5.4 将整数字符串转成整数值

题目：给定一个字符串str，如果str符合日常书写的整数形式，并且属于32位整数的范围，
返回str所代表的整数值，否则返回0；
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isValid(string str)
{
	if (str.empty())
		return false;
	else if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
		return false;
	else if (str[0] == '-' && (str.length() == 1 || str[1] == '0'))
		return false;
	else if (str[0] == '0' && str.length() > 1)
		return false;
	else
	{
		/*从第二个字符开始检查*/
		for (auto c : str.substr(1))
		{
			if (c < '0' || c>'9')
				return false;
		}//for
		return true;
	}//else
		

}
/*字符串转换为整数值*/
int convert(const string &str)
{
	if (!isValid(str))
		return false;

	int ret = 0, cur = 0, minQ = INT_MIN / 10, minR = INT_MIN % 10;
	bool flag = str[0] == '-' ? false : true;
	for (auto c : str)
	{
		if (c == '-')
			continue;
		cur = '0' - c;
		/*会溢出的情况*/
		if (ret < minQ || (ret == minQ && cur < minR))
			return 0;
		else
			ret = ret * 10 + cur;
	}//for

	/*字符串为-2147483648*/
	if (flag && ret == INT_MIN)
		return 0;
	return flag ? -ret : ret;
} 

//int main()
//{
//	cout << convert("124") << endl;
//	cout << convert("023") << endl;
//	cout << convert("A13") << endl;
//	cout << convert("2147483648") << endl;
//	cout << convert("-2147483648") << endl;
//
//	system("pause");
//	return 0;
//}
