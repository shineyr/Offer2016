/*
面试题8.12 未排序数组中累加和小于或等于给定值的最长子数组长度
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int firstIdx(vector<int> v, int target)
{
	if (v.empty())
		return -1;

	int l = 0, r = v.size() - 1, pos = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (v[mid] >= target)
		{
			pos = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}//else
	}//while
	return pos;
}

/*算法原型：求无序数组的累加和<=k的最长子数组大小*/
int maxLength(vector<int> v, int k)
{
	if (v.empty())
		return 0;

	int n = v.size();
	vector<int> helpSum(n + 1, 0);

	/*同时将辅助数组构造为递增有序*/
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		helpSum[i + 1] = max(sum, helpSum[i]);
	}//for

	 /*求以i结尾的，累加和<=k的最长子数组，等价于从前面找到第一个累加和大于等于sum-k的索引*/
	sum = 0;

	int pos = -1;
	int len = 0, maxLen = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		pos = firstIdx(helpSum, sum - k);
		if (pos == -1)
		{
			len = 0;
		}
		else {
			len = i - pos + 1;
		}
		maxLen = max(maxLen, len);
	}
	return maxLen;
}
