/*
5.1 判断两个字符串是否互为变形词
题目：给定两个字符串str1和str2，如果str1和str2中出现的字符种类一样，且每种字符出现的次数一样，
那么str1和str2互为变形词。请实现函数判断两个字符串是否互为变形词。
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*方法一：排序*/
bool isDeformation(string str1, string str2)
{
	int len1 = str1.length(), len2 = str2.length();

	if (len1 != len2)
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

/*方法二，哈希，所有字符对应ASCII码 0~255*/
bool isDeformation2(string str1, string str2)
{
	if (str1.size() != str2.size())
		return false;

	vector<int> v(256, 0);
	for (auto &c : str1)
	{
		++v[c];
	}//for

	for (auto &c : str2)
	{
		--v[c];
		if (v[c] < 0)
			return false;
	}//for
	return true;
}

int main()
{
	string s1 = "124", s2 = "241";
	cout << isDeformation(s1, s2) << endl;
	cout << isDeformation2(s1, s2) << endl;

	system("pause");
	return 0;
}

