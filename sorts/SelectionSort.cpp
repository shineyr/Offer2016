/*
对于一个int数组，请编写一个选择排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int *SelectionSort(int *A, int n)
{
	if (n <= 0)
		return A;

	/*进行n-1趟选择*/
	for (int i = 0; i < n - 1; ++i)
	{
		/*每次选择，找到i到n-1处最小元素位置，放在i位置*/
		int minPos = i;
		for (int j = i+1; j < n; ++j)
		{
			if (A[j] < A[minPos])
			{
				minPos = j;
			}//if
		}//for

		/*将最小元素放在此趟选择的首位*/
		int tmp = A[i];
		A[i] = A[minPos];
		A[minPos] = tmp;
	}//for
	return 0;
}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	SelectionSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}