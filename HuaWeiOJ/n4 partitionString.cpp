/*
题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

输入例子:
abc
123456789

输出例子:
abc00000
12345678
90000000
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector<string> partitionStr(string str)
{
	if (str.empty())
		return vector<string>();
	int len = str.length();
	if (len % 8 != 0)
	{
		str += string(8 - len % 8, '0');
		len += 8 - len % 8;
	}//if

	vector<string> ret;
	for (int i = 0; i < len / 8; ++i)
	{
		ret.push_back(str.substr(8 * i, 8));
	}//for

	return ret;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	vector<string> ret1 = partitionStr(str1);
	for (auto iter = ret1.begin(); iter != ret1.end(); ++iter)
	{
		cout << *iter << endl;
	}//for

	vector<string> ret2 = partitionStr(str2);
	for (auto iter = ret2.begin(); iter != ret2.end(); ++iter)
	{
		cout << *iter << endl;
	}//for

	system("pause");
	return 0;
}