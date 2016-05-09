/*
4.7 最长公共子序列

给定两个字符串str1和str2，返回两个字符串的最长公共子序列。
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
	if (A.empty() || B.empty())
	{
		return vector<vector<int>>();
	}//if

	int aLen = A.size(), bLen = B.size();

	/*矩阵dp[i][j]的含义是字符串A[0...i]与字符串B[0...j]的最长公共子序列长度，从左到右，从上到下计算矩阵dp*/
	vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
	dp[0][0] = A[0] == B[0] ? 1 : 0;
	for (int i = 1; i < aLen; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], A[i] == B[0] ? 1 : 0);
	}//for

	for (int j = 1; j < bLen; ++j)
	{
		dp[0][j] = max(dp[0][j], A[0] == B[j] ? 1 : 0);
	}//for

	for (int i = 1; i < aLen; ++i)
	{
		for (int j = 1; j < bLen; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (A[i] == B[j])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}//if
		}//for
	}//for

	/*此时dp[aLen-1][bLen-1]便是最长公共子序列的长度*/
	return dp;
}

/*求最长公共子序列*/
string longestCommonSubsequence(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*得到最长公共子序列长度的动态规划长度矩阵*/
	vector<vector<int>> dp = getDp(str1, str2);

	int m = str1.length() - 1, n = str2.length() - 1, len = dp[m][n];
	/*最长公共子序列长度为len，初始化一个结果字符串*/
	string ret(len,'0');
	/*从右下角遍历矩阵*/
	for (int idx = len - 1; idx >= 0; )
	{
		if (n > 0 && dp[m][n] == dp[m][n - 1])
		{
			/*不选str1[m] 和 str2[n] 向左移动*/
			--n;
		}//if
		else if (m > 0 && dp[m][n] == dp[m - 1][n])
		{
			/*不选str1[m] 和 str2[n] 向上移动*/
			--m;
		}//elif
		else {
			/*选择当前字符，向左上方移动*/
			ret[idx--] = str1[m];
			--m;
			--n;
		}//else
	}//for

	return ret;
}

int main()
{
	string str1 = "1A2C3D4B56", str2 = "B1D23CA45B6A";
	cout << longestCommonSubsequence(str1, str2) << endl;

	system("pause");
	return 0;
}