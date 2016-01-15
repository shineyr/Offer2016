/*
题目：最大值减去最小值小于或等于num的子数组数量
给定数组arr和整数num，共返回有多少个子数组满足如下情况：
max(arr[i...j]) - min(arr[i...j]) <= num

max(arr[i...j])表示子数组arr[i...j]中的最大值，min(arr[i...j])表示子数组arr[i...j]中的最小值。

要求，如果数组长度为N，请实现时间复杂度为O(N)的算法。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

int getNum(vector<int> arr, int num)
{
	if (arr.empty())
		return 0;

	deque<int> qmin, qmax;
	int i = 0, j = 0, ret = 0, len = arr.size();
	while (i < len)
	{
		while (j < len)
		{
			while (!qmin.empty() && arr[qmin.back()] >= arr[j])
				qmin.pop_back();
			qmin.push_back(j);
			while (!qmax.empty() && arr[qmax.back()] <= arr[j])
				qmax.pop_back();
			qmax.push_back(j);

			if (arr[qmax.front()] - arr[qmin.front()] > num)
				break;
			++j;
		}//while
		if (qmin.front() == i)
			qmin.pop_front();
		if (qmax.front() == i)
			qmax.pop_front();

		ret += (j - i);
		++i;
	}//while
	return ret;
}

int main()
{
	vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7 };
	cout << getNum(v, 2) << endl;

	system("pause");
	return 0;
}