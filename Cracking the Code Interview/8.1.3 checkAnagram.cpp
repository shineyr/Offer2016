/*
 * 8.1.3 给定两个字符串，确定其中一个字符串的字符重新排列后，能否变为另一个字符串。
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	/*首先，明确题意，(1)考虑空格，(2)区分大小写*/

	//方法一：字符串排序，复杂度为O(nlogn) 
	bool checkAnagram(string str1, string str2)
	{
		//(1)首先，长度不等的字符串非变位词
		if (str1.empty() && str2.empty())
			return true;

		int len1 = str1.length(), len2 = str2.length();
		if (len1 != len2)
			return false;

		//(2)给字符串排序，然后比较，不等则非变位词
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		if (str1 != str2)
			return false;
		return true;
	}

	//方法二：判断字符数是否相同
	bool checkAnagram2(string str1, string str2)
	{
		//(1)首先，长度不等的字符串非变位词
		if (str1.empty() && str2.empty())
			return true;

		int len1 = str1.length(), len2 = str2.length();
		if (len1 != len2)
			return false;

		vector<int> letters(256, 0);
		for (int i = 0; i < len1; ++i)
		{
			++letters[str1[i]];
		}//for

		for (int j = 0; j < len2; ++j)
		{
			if (--letters[str2[j]] < 0)
				return false;
		}//for

		return true;
	}
};

int main()
{
	Solution s;
	cout << s.checkAnagram2("bac", "bac") << endl;

	system("pause");
	return 0;

}