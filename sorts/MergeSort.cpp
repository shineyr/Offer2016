/*
对于一个int数组，请编写一个归并排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;
void MergeSort(int *A, int left, int right);
void Merge(int *A, int left, int mid, int right);

int* MergeSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;

	MergeSort(A, 0, n - 1);
	return A;
}

void MergeSort(int *A, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);

	Merge(A, left, mid, right);
}

/*将排序后的left~mid与mid+1~right两个子序列合并*/
void Merge(int *A, int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	/*合并排序后的元素到tmp临时数组*/
	int lhs = left, rhs = mid + 1, k = 0;
	while (lhs <= mid && rhs <= right)
	{
		if (A[lhs] <= A[rhs])
			tmp[k++] = A[lhs++];
		else
			tmp[k++] = A[rhs++];
	}//while

	/*直接拷贝剩余元素*/
	while (lhs <= mid)
	{
		tmp[k++] = A[lhs++];
	}//while

	while (rhs <= right)
	{
		tmp[k++] = A[rhs++];
	}//while

	/*拷贝临时数组数据到原数组*/
	for (int i = left; i <= right; ++i)
	{
		A[i] = tmp[i - left];
	}//for

	delete[]tmp;
}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	MergeSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}