/*
8.13 计算数组的小和
题目：
数组小和的定义如下：例如数组 s = [1,3,5,2,4,6] 在s[0]的左边小于等于s[0]的数的和为0，
在s[1]的左边小于等于s[1]的数的和为1...依次规律，得到s的小和为0+1+4+1+6+15=27.
给定一个数组s，实现函数返回s的小和。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*方法一：两层循环实现，复杂度O(N^2)*/
int getSmallSum(const vector<int> &arr)
{
	if (arr.empty())
		return 0;

	int sum = 0, len = arr.size();
	/*计算每个元素的左侧小和*/
	for (int i = 0; i < len; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] <= arr[i])
			{
				tmp += arr[j];
			}//if
		}//for
		sum += tmp;
	}//for

	return sum;
}

/*方法二：利用归并排序的思想，得到时间复杂度为O(nlogn)，空间复杂度为O(n)的算法*/
int merge(vector<int> &arr, int left, int mid, int right)
{
	/*借助一个临时动态数组*/
	vector<int> tmp(right - left + 1, 0);

	int smallSum = 0, i = left, j = mid + 1, k = -1;
	for (; i <= mid&&j <= right;)
	{
		if (arr[i] < arr[j])
		{
			/*小和*/
			smallSum += arr[i] * (right - j + 1);
			tmp[++k] = arr[i++];
		}//if
		else{
			/*没有小和*/
			tmp[++k] = arr[j++];
		}//else
	}//for

	/*剩余*/
	for (; i <= mid || j <= right; ++i, ++j)
	{
		tmp[++k] = i > mid ? arr[j] : arr[i];
	}//for
	
	/*更新原始数组*/
	for (int i = 0; i < k; ++i)
	{
		arr[left + i] = tmp[i];
	}//for
	tmp.clear();

	return smallSum;
}

int func(vector<int> &arr, int l, int r)
{
	if (arr.empty() || l >= r)
		return 0;

	int mid = (l + r) / 2;
	return func(arr, l, mid) + func(arr, mid + 1, r) + merge(arr, l, mid, r);
}
int getSmallSum2(vector<int> &arr)
{
	if (arr.empty())
		return 0;

	return func(arr, 0, arr.size() - 1);
}

int main()
{
	vector<int> v = { 1, 3, 5, 2, 4, 6 };
	cout << getSmallSum(v) << endl;

	cout << getSmallSum2(v) << endl;

	system("pause");
	return 0;
}
