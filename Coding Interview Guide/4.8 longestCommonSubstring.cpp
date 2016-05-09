/*
4.8 最长公共子串
给定两个字符串str1和str2，返回两个字符串的最长公共子串。

举例：str1=“1AB2345CD”，str2="12345EF"，返回“2345”
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*计算动态规划矩阵*/
vector<vector<int>> getDp(string A, string B)
{
	// write your code here
	if (A.empty() || B.empty())
	{
		return vector<vector<int>>();
	}//if

	int aLen = A.size(), bLen = B.size();
	/*动态规划，时间复杂度O(mn) 空间复杂度O(mn）
	dp[i][j]表示必须把A[i]和B[j]作为公共子串的最后一个字符时的子串最大长度*/
	vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
	dp[0][0] = A[0] == B[0] ? 1 : 0;

	for (int i = 1; i<aLen; ++i)
	{
		dp[i][0] = A[i] == B[0] ? 1 : 0;
	}//for

	for (int j = 1; j<bLen; ++j)
	{
		dp[0][j] = A[0] == B[j] ? 1 : 0;
	}//for


	for (int i = 1; i<aLen; ++i)
	{
		for (int j = 1; j<bLen; ++j)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}//if
			else {
				dp[i][j] = 0;
			}//if
		}//for
	}//for
	/*此时最长公共子串的长度即为矩阵dp中的最大值*/
	return dp;
}

/*方法一：经典动态规划 时间复杂度O(m*n) 空间复杂度O(m*n)*/
string longestCommonSubstring(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*得到最长公共子串长度的动态规划长度矩阵*/
	vector<vector<int>> dp = getDp(str1, str2);

	int m = str1.length(), n = str2.length(), maxLen = 0, end = 0;
	/*找到最长公共子串的长度，和其在str1中的结束位置*/
	for(int i = 0 ; i < m ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (dp[i][j] > maxLen)
			{
				maxLen = dp[i][j];
				end = i;
			}//if
		}//for
	}//for

	return str1.substr(end - maxLen + 1, maxLen);
}


/*方法二：优化算法 空间复杂度O(1)*/
string longestCommonSubstring2(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*斜线开始的行和列*/
	int row = 0, col = str2.length() - 1;
	/*公共子串最大长度，和str1中的结束位置*/
	int maxLen = 0, end = 0;
	while (row < str1.length())
	{
		int i = row, j = col, len = 0;
		/*从(i,j)开始向右下方遍历*/
		while (i < str1.length() && j < str2.length())
		{
			if (str1[i] != str2[j])
			{
				len = 0;
			}//if
			else {
				++len;
			}//else

			/*记录最大值以及结束字符的位置*/
			if (maxLen < len)
			{
				maxLen = len;
				end = i;
			}//if

			++i;
			++j;
		}//while

		/*斜线开始位置的列先向左移动*/
		if (col > 0)
		{
			--col;
		}//if
		/*列移动到最左以后，行向下移动*/
		else {
			++row;
		}//else
	}//while
	return str1.substr(end - maxLen + 1, maxLen);
}

int main()
{
	string str1 = "1AB2345CD", str2 = "12345EF";
	cout << longestCommonSubstring2(str1, str2) << endl;

	system("pause");
	return 0;
}