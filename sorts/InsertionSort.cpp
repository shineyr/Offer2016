/*
对于一个int数组，请编写一个插入排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*直接插入排序*/
int *IntertionSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;

	/*将序列中的i=1~i=n-1的元素依次选择合适位置插入*/
	for (int i = 1; i < n; ++i)
	{
		/*要插入的元素*/
		int tmp = A[i];
		/*从已有序序列尾向前寻找合适位置*/
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (A[j] > tmp)
				A[j + 1] = A[j];
			else
				break;
		}//for
		A[j + 1] = tmp;
	}
	return A;
}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	IntertionSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}
