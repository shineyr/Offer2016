/*
 * 8.1.8 假定有一个方法isSubstring 可检查一个单词是否为其它字符串的子串。
 * 给定两个字符串s1和s2，请编写代码检查s2是否由s1旋转而成，要求只能调用一次isSubstring
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Solution
{
public:
	bool isRotation(string s1, string s2)
	{
		//检查两个字符串是否等长且不为空
		if (s1.empty() || s2.empty() || s1.length() != s2.length())
			return false;
		return isSubstring(s1 + s1, s2);		
	}

	bool isSubstring(string str, string sub)
	{

	}
};