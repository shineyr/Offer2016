/*
面试题8：旋转数组的最小数字
题目：把一个数组的最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组{3，4，5，1，2}为数组{1，2，3，4，5}的一个旋转，该数组的最小值为1；
*/

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

/*顺序查找*/
int minNumber(int *arr, int beg, int end)
{
	int minRet = arr[beg];
	for (int i = beg; i <= end; ++i)
	{
		if (arr[i] < minRet)
			minRet = arr[i];
	}//for
	return minRet;
}

/*利用二分的思想查找*/
int minNumber(int *arr, int len)
{
	assert((arr != NULL) && (len > 0));

	int beg = 0, end = len - 1;
	int mid = beg;
	while (arr[beg] >= arr[end])
	{
		if (end - beg == 1)
		{
			mid = end;
			break;
		}//if

		mid = (beg + end) / 2;

		if (arr[beg] == arr[mid] && arr[mid] == arr[end])
			return minNumber(arr, beg, end);

		else if (arr[mid] >= arr[beg])
		{
			beg = mid;
		}
		else
		{
			end = mid;
		}//elif
	}//while
	return arr[mid];
}

int main()
{
	int arr[] = { 1, 0, 1, 1, 1 };
	int arr2[] = { 1, 1, 1, 0, 1 };
	int arr3[] = { 3, 4, 5, 1, 2 };

	cout << minNumber(arr, 5) << endl;
	cout << minNumber(arr2, 5) << endl;
	cout << minNumber(arr3, 5) << endl;

	system("pause");
	return 0;
}