/*
8.10 未排序正数数组中累加和为给定值的最长子数组长度
题目：
给定一个数组arr，该数组无序，但每个值均为正数，再给定一个正数k。
求arr的所有子数组中所有元素相加和为k的最长子数组长度。
例如：arr=[1,2,1,1,1] k=3
累加和为3的最长子数组长度为1 1 1 返回3
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int getMaxLen(vector<int> &arr, int k)
{
	if (arr.empty() || k <= 0)
		return 0;

	int lhs = 0, rhs = 0, len = 0, sum = arr[0];
	while (rhs < arr.size())
	{
		if (sum == k)
		{
			/*更新等于指定大小k的子数组长度*/
			len = (rhs - lhs + 1) > len ? (rhs - lhs + 1) : len;
			/*考察从lhs之后开始的子数组*/
			sum -= arr[lhs++];
		}//if
		else if (sum < k)
		{
			++rhs;
			if (rhs >= arr.size())
				break;
			sum += arr[rhs];
		}//elif
		else
		{
			sum -= arr[lhs++];
		}//else
	}//while
	return len;
}

int main()
{
	vector<int> arr = { 1, 2, 1, 1, 1 };
	cout << getMaxLen(arr, 3) << endl;

	system("pause");
	return 0;
}