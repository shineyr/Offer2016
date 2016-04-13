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

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	BubbleSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}