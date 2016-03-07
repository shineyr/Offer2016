/*
5.6 替换字符串中连续出现的指定字符串

题目：给定三个字符串str,from,to，已知from字符串无重复字符，把str中所有from的子串全部替换成to字符串，
对连续出现from的部分，要求只替换成一个to子串，返回最终的结果字符串。
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string replace(string str, string from, string to)
{
	if (str.empty() || from.empty() || to.empty())
		return str;

	int len = str.size();


}