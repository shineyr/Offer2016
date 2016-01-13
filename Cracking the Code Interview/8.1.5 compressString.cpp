/*
 * 面试题8.1.5 利用字符串重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
 * 比如，aabbcccccaaa会变成a2b1c5a3，若“压缩”后的字符串没有变短，则返回原先的字符串；
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution{
public:
	string compressString(string str)
	{
		if (str.empty())
			return str;

		string s;
		//求字符串长度
		int len = str.length();
		//记录当前首字符
		char cur = str[0];
		int count = 1;
		for (int i = 1; i < len; ++i)
		{
			if (str[i] != cur)
			{
				s += cur;
				s = s + intToString(count);

				cur = str[i];
				count = 1;
			}//if
			else 
				++count;
		}//for
		//链接末尾字符
		s += cur;
		s = s + intToString(count);

		if (s.length() > len)
			return str;
		return s;
	}

	string intToString(int count)
	{
		string ret = "";
		while (count)
		{
			char c = count % 10 + '0';
			ret += c;
			count /= 10;
		}//while
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	Solution s;
	string str = s.compressString("aabcccccaaa");
	cout << str << endl;

	system("pause");
	return 0;
}