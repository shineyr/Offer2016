/*
对于一个int数组，请编写一个归并排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

/*划分函数*/
int partition(int *A, int left, int right);
/*递归实现*/
void QuickSort(int *A, int left, int right);
/*非递归实现*/
void QuickSort2(int *A, int left, int right);

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = a;
}

int partition(int *A, int left, int right)
{
	///*随机选择*/
	srand((int)time(NULL));
	int pos = left + (rand() % (right - left + 1));
	///*交换*/
	swap(A[pos], A[right]);

	/*设置左侧小于等于区间{}，初始化为left左侧*/
	int lessPos = left - 1;
	int pivot = A[right];
	for (int i = left; i < right; ++i)
	{
		if (A[i] <= pivot)
		{
			/*交换，并小于等于区间尾部右移*/
			++lessPos;
			swap(A[lessPos], A[i]);
		}//if
	}
	swap(A[lessPos + 1], A[right]);
	return lessPos + 1;
}


/*快速排序*/
int *QuickSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;
	QuickSort2(A, 0, n-1);
	return A;
}


/*快速排序的递归实现*/
void QuickSort(int *A, int left, int right)
{
	if (left < right)
	{
		int pos = partition(A, left, right);
		QuickSort(A, left, pos - 1);
		QuickSort(A, pos + 1, right);
	}//if
}

/*快速排序的非递归实现*/
void QuickSort2(int *A, int left, int right)
{
	stack<int> st;
	if (left < right)
	{
		int mid = partition(A, left, right);
		if (left < mid - 1)
		{
			st.push(left);
			st.push(mid - 1);
		}//if

		if (right > mid + 1)
		{
			st.push(mid + 1);
			st.push(right);
		}//if

		/*其实就是用栈保存每一个待排序子串的首尾元素下标，
		下一次while循环时取出这个范围，对这段子序列进行partition操作*/
		while (!st.empty())
		{
			int rhs = st.top();
			st.pop();
			int lhs = st.top();
			st.pop();

			mid = partition(A, lhs, rhs);

			if (lhs < mid - 1)
			{
				st.push(lhs);
				st.push(mid - 1);
			}//if

			if (rhs > mid + 1)
			{
				st.push(mid + 1);
				st.push(rhs);
			}//if
		}//while
	}//if

}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	QuickSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}