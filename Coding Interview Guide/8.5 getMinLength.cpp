/*
题目：8.5  需要排序的最短子数组长度
给定一个无序数组arr，求出需要排序的最短子数组长度。
例如：arr={1，5，3，4，2，6，7}返回4，
只有{5，3，4，2}才需要排序。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int getMinLength(int arr[], int n)
{
	if (n <= 0)
		return 0;
	
	int minNum = arr[n - 1];
	int noMinIdx = -1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (arr[i] > minNum)
		{
			noMinIdx = i;
		}
		else{
			minNum = arr[i];
		}//else
	}//for

	if (-1 == noMinIdx)
		return 0;

	int maxNum = arr[0], noMaxIdx = -1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < maxNum)
		{
			noMaxIdx = i;
		}
		else{
			maxNum = arr[i];
		}//else
	}//for

	if (-1 == noMaxIdx)
		return 0;

	return noMaxIdx - noMinIdx + 1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	int len = getMinLength(arr, 7);

	cout << len << endl;

	system("pause");
	return 0;
}
