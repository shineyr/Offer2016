/*
 * 面试题53 正则表达式匹配
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;

		return judge(str, pattern);
	}

	bool judge(char *str, char *pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		else if (*str != '\0' && *pattern == '\0')
			return false;
		else{
			if (*(pattern + 1) == '*')
			{
				if (*str == *pattern || (*pattern == '.' && *str != '\0'))
					return judge(str + 1, pattern + 2) || judge(str + 1, pattern) || judge(str, pattern + 2);
				else
					return judge(str, pattern + 2);
			}
			else if (*str == *pattern || (*pattern == '.' && *str != '\0'))
				return judge(str + 1, pattern + 1);
			return false;
		}//else
	}
};

int main()
{
	Solution s;
	cout << s.match("aaa", "a.a") << endl;
	cout << s.match("aaa", "ab*ac*a") << endl;
	system("pause");
	return 0;
}
