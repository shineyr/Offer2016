/*
* 面试题8.9.3 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i]=i。
* 给定一个有序整数数组，元素值各不相同，编写一个方法，在数组A中找出一个魔术索引，若存在的话；
* 进阶如果数组中有重复元素，又该如何处理？
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
	/*方法一：暴力法解决 O(n)*/
	int magicIndex(vector<int> &nums)
	{
		if (nums.empty())
			return INT_MAX;

		/*序列长度*/
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == i)
				return i;
		}//for
		return INT_MIN;
	}

	/*方法二：二分法解决*/
	int magicIndex2(vector<int> &nums)
	{
		if (nums.empty())
			return INT_MIN;
		
		/*二分索引*/
		int lhs = 0, rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (mid == nums[mid])
				return mid;
			else if (mid < nums[mid])
				rhs = mid - 1;
			else
				lhs = mid + 1;
		}//while
		return INT_MIN;
	}

	/*当给定序列有重复元素，递归实现*/
	int magicIndex(vector<int> &nums, int beg, int end)
	{
		if (nums.empty() || beg > end || beg < 0 || end > nums.size())
			return INT_MIN;

		int mid = (beg + end) / 2;

		if (mid == nums[mid])
			return mid;

		/*搜索左半部分*/
		int leftIndex = magicIndex(nums, beg, min(mid - 1, nums[mid]));
		if (leftIndex != INT_MIN)
			return leftIndex;

		/*搜索右半部分*/
		int rightIndex = magicIndex(nums, max(mid + 1, nums[mid]), end);
		if (rightIndex != INT_MIN)
			return rightIndex;
		
		/*不存在*/
		return INT_MIN;
	}

};


int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3, 3, 4, 5, 6 };
	cout << s.magicIndex(v) << endl;

	cout << s.magicIndex(v, 0, v.size() - 1) << endl;

	system("pause");
	return 0;
}