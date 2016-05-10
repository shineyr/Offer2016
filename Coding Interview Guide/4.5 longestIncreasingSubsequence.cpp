/*
4.5 最长递增子序列
给定一个整数序列arr，长度为N，找到最长上升子序列（LIS），返回LIS的长度。

举例：
给出 [5,4,1,2,3]，LIS 是 [1,2,3]，返回 3
给出 [4,2,4,5,3,7]，LIS 是 [4,4,5,7]，返回 4
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//O(n^2)的复杂度
vector<int> getDp1(vector<int> &nums)
{
	if (nums.empty())
	{
		return vector<int>();
	}//if

	int len = nums.size();
	vector<int> dp(len, 0);
	for (int i = 0; i < len; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] >= nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}//if
		}//for
	}//for

	return dp;
}

//O(nlogn)的复杂度（针对不含重复元素的最长递增子序列）
vector<int> getDp2(vector<int> &nums)
{
	if (nums.empty())
	{
		return vector<int>();
	}//if

	int len = nums.size();
	vector<int> dp(len, 0), ends(len, 0);
	dp[0] = 1;
	ends[0] = nums[0];

	int right = 0;

	int l = 0, r = 0, m = 0;
	for (int i = 1; i < len; ++i)
	{
		l = 0;
		r = right;
		/*采用二分的思想，降低复杂度*/
		while (l <= r)
		{
			m = (l + r) / 2;
			if (nums[i] < ends[m])
			{
				l = m + 1;
			}//if
			else {
				r = m - 1;
			}//else
		}//while

		right = max(right, l);
		ends[l] = nums[i];
		dp[i] = l + 1;
	}//for

	return dp;
}

//动态规划
int longestIncreasingSubsequence(vector<int> nums) {
	// write your code here
	if (nums.empty())
	{
		return 0;
	}//if

	vector<int> dp = getDp1(nums);
	int maxLen = 0, len = dp.size();
	for (int i = 0; i < len; ++i)
	{
		if (dp[i] > maxLen)
		{
			maxLen = dp[i];
		}//if
	}//for

	return maxLen;
}


int main()
{
	vector<int> v = { 5,4,1,2,3 };
	cout << longestIncreasingSubsequence(v) << endl;

	system("pause");
	return 0;
}