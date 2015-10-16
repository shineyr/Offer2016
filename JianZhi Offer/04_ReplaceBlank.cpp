#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

/*
 * 替换空格
 * 题目描述
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (length <= 0 || str == NULL)
			return;
		
		int blankCount = 0 , len = 0;

		//计算字符串中的空格个数,以及源串长度
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (' ' == str[i])
				++blankCount;
			++len;
		}//for

		//替换之后的字符串长度
		int newLen = len + 2 * blankCount;

		//超出了容量
		if (newLen > length)
			return;

		str[newLen] = '\0';

		for (int i = newLen - 1, j = len - 1; i >= 0 && j >= 0; --j)
		{
			if (str[j] != ' ')
			{
				str[i] = str[j];
				--i;
			}//if
			else{
				str[i] = '0';
				str[--i] = '2';
				str[--i] = '%';
				--i;
			}//else
		}//for

	}
};

int main()
{
	Solution s;

	char *str = new char[50];

	gets(str);

	s.replaceSpace(str, 50);

	cout << str << endl;

	system("pause");
	return 0;
}