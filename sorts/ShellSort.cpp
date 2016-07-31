/*
对于一个int数组，请编写一个希尔排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*希尔排序*/
void ShellSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return;

	/*设置增量*/
	int d = n;
	while (d > 1)
	{
		d = (d + 1) / 2;
		for (int i = d; i < n; ++i)
		{						
			/*要插入的元素*/
			int tmp = A[i];
			/*从已有序序列尾向前寻找合适位置*/
			int j = i-d;
			for (; j >= 0; j-=d)
			{
				if (A[j] > tmp)
					A[j + d] = A[j];
				else
					break;
			}//for
			A[j + d] = tmp;
		}//for
	}//while
}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	ShellSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}