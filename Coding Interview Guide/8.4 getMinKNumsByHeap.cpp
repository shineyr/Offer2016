/*
8.4 找到无序数组中最小的k个数。
题目：给定一个无序的整型数组arr，找到其中最小的k个数。

要求：如果数组arr的长度为N，排序之后自然可以得到最小的k个数，此时时间复杂度与排序的时间复杂度相同，
均为O(nlogn)。本题要求读者实现时间复杂度为O(nlogk)和O(n)的算法。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*交换函数*/
void swap2(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*建堆函数*/
void heapInsert(vector<int> &arr, int val, int idx)
{
	arr[idx] = val;
	while (idx != 0)
	{
		int parent = (idx - 1) / 2;
		if (arr[parent] < arr[idx])
		{
			swap2(arr[parent], arr[idx]);
			idx = parent;
		}//if
		else
			break;
	}//while
}

/*堆调整函数*/
void heapify(vector<int> kHeap, int idx, int heapSize)
{
	/*求得调整目标节点的左右孩子*/
	int lhs = 2 * idx + 1, rhs = 2 * idx + 2;
	int largest = idx;

	/*找到当前节点与其左右孩子中最大值节点*/
	while (lhs < heapSize)
	{
		if (kHeap[lhs] > kHeap[idx])
			largest = lhs;
		if (rhs < heapSize && kHeap[rhs] > kHeap[largest])
			largest = rhs;

		if (largest != idx)
		{
			swap2(kHeap[largest], kHeap[idx]);
		}//if
		else
		{
			break;
		}//else

		/*自底向上调整*/
		idx = largest;
		lhs = 2 * idx + 1;
		rhs = 2 * idx + 2;
	}//while
}

/*使用堆排序实现*/
vector<int> getMinKNumsByHeap(vector<int> arr , int k)
{
	if (arr.empty() || k <= 0)
		return vector<int>();
	int len = arr.size();
	if (len <= k)
		return arr;

	/*建堆*/
	vector<int> kHeap(k, 0);
	for (int i = 0; i < k; ++i)
	{
		heapInsert(kHeap, arr[i], i);
	}//for

	/*遍历剩余元素，更新小元素到kHeap*/
	for (int i = k; i < len; ++i)
	{
		if (arr[i] < kHeap[0])
		{
			kHeap[0] = arr[i];
			/*大顶推调整*/
			heapify(kHeap, 0, k);
		}//if
	}//for
	return kHeap;
}

int main()
{
	vector<int> v = { 2, 3, 5, 23, 56, 2, 6, 8, 9, 9, 10, 34, 54 };
	vector<int> kV = getMinKNumsByHeap(v, 3);

	for (unsigned int i = 0; i < kV.size(); ++i)
		cout << kV[i] << "\t";

	cout << endl;
	system("pause");
	return 0;
}