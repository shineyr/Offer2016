/*
5.3 去掉字符串中连续出现K个0的子串。
题目：
给定一个字符串str和一个整数k，如果str中正好有连续的k个0字符出现时，
把k个连续的'0'字符去除，返回处理后的字符串。
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string removeKZeros(string &str,int k)
{
	if (str.empty())
		return NULL;

	int beg = -1, count = 0, len = str.size();
	for (int i = 0; i<len; ++i)
	{
		if (str[i] != '0')
		{
			if (count == k)
			{
				str = beg == -1 ? str.substr(count + 1) : str.substr(0, beg) + str.substr(beg + count);
				return str;
			}//if
			else{
				beg = -1;
				count = 0;
			}//else
		}//if
		else{
			if (-1 == beg)
				beg = i;
			++count;
		}//else
	}//for

	/*判断是否连续k个0在整个字符串末尾*/
	if (count == k)
	{
		str = beg == -1 ? str.substr(count + 1) : str.substr(0, beg) + str.substr(beg + count);
	}//if

	return str;
}

int  main()
{
	string str = "A0000B000";
	cout << removeKZeros(str, 3) << endl;

	system("pause");
	return 0;

}