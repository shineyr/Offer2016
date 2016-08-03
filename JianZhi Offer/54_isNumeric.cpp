/*
面试题54： 表示数值的字符串

题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isExponential(string &str, int &idx)
{
	if (idx > str.size() || !(str[idx] == 'e' || str[idx] == 'E'))
	{
		return false;
	}

	++idx;
	if (str[idx] == '+' || str[idx] == '-')
		++idx;
	if (idx >= str.size())
		return false;
	/*找到下一个非数字的字符*/
	while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
		++idx;
	return idx == str.size();

}
bool isNumeric(string str)
{
	if (str.empty())
		return false;

	int idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
		++idx;

	if (idx == str.size())
		return false;

	bool ret = true;
	/*找到第一个非数字的字符*/
	while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
		++idx;

	if (idx < str.size())
	{
		if (str[idx] == '.')
		{
			++idx;
			/*找到下一个非数字的字符*/
			while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
				++idx;
			if (idx == str.size())
				return true;
			else if (str[idx] == 'e' || str[idx] == 'E')
				return isExponential(str, idx);
			else
				return false;
		}
		else if (str[idx] == 'e' || str[idx] == 'E')
			return isExponential(str, idx);
		else
			return false;
	}
	else {
		if (idx == str.size())
			return true;
		return false;
	}
}

int main()
{
	cout << isNumeric("+100") << endl;
	cout << isNumeric("5e2") << endl;
	cout << isNumeric("-123") << endl;
	cout << isNumeric("1a3.14") << endl;

	system("pause");
	return 0;
}