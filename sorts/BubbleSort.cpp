/*
对于一个int数组，请编写一个冒泡排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*大数下沉 T(n)=O(n^2) S(n)=O(1) 稳定*/
int *BubbleSort(int *A, int n)
{
	if (n <= 0)
		return A;

	/*进行n-1趟冒泡*/
	for (int i = 0; i < n - 1; ++i)
	{
		/*每次冒泡针对头到n-i-1尾比较工作*/
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}//if
		}//for
	}//for
	return A;
}

/*小数上升 T(n)=O(n^2) S(n)=O(1) 稳定*/
int *BubbleSort2(int *A, int n)
{
	if (n <= 0)
		return A;

	/*进行n-1趟冒泡*/
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (A[j] < A[j - 1])
			{
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j-1] = tmp;
			}//if
		}
	}

	return A;
}

/*冒泡排序优化*/
int *BubbleSort3(int *A, int n)
{
	if (n <= 0)
		return A;

	/*进行n-1趟冒泡*/
	bool flag = true;
	for (int i = 0; i < n - 1 && flag; ++i)
	{
		flag = false;
		for (int j = n - 1; j > i; --j)
		{
			if (A[j] < A[j - 1])
			{
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j-1] = tmp;

				flag = true;
			}//if
		}
	}
	return A;
}
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	BubbleSort3(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}