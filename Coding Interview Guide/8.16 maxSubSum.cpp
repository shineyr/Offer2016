/*
8.16 子数组的最大累加和

题目：
给定一个数组arr，返回子数组的最大累加和。
例如，arr={1,-2,3,5,-2,6,-1};所有的子数组中，[3,5,-2,6]可以累加出最大的和12，
所以返回12；
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int maxSubSum(vector<int> arr)
{
	if (arr.empty())
		return 0;
	int len = arr.size(), maxSum = 0, tmpSum = 0, beg = 0, end = -1;
	for (int i = 0; i < len; ++i)
	{
		tmpSum += arr[i];
		if (tmpSum > maxSum)
		{
			maxSum = tmpSum;
			end = i;
		}//if
		else if (tmpSum < 0)
		{
			tmpSum = 0;
			beg = i+1;
		}
		else
			continue;
	}//for
	if (end>beg)
		cout << "最大字段和起始位置：" << beg << ", " << end << endl;
	return maxSum;
}

int main()
{
	vector<int> v = { 1, -2, 3, 5, -2, 6, -1 };

	cout << maxSubSum(v) << endl;

	system("pause");
	return 0;
}