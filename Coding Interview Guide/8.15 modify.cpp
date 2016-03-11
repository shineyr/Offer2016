/*
8.15 奇数下标都是奇数或者偶数下标都是偶数

题目：给定一个长度不小于2的数组arr，实现一个函数调整arr，要么让所有的偶数下标都是偶数，
要么让所有的奇数下标都是奇数。

要求：如果arr的长度为N，函数要求时间复杂度为O(N)，额外空间复杂度为O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*交换元素值*/
void swap3(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*按要求调整数组元素,最大程度的保证偶数下标存储偶数元素，奇数下标存储奇数元素*/
void modify(vector<int> &arr)
{
	if (arr.empty() || arr.size() < 2)
		return;

	int len = arr.size();
	int even = 0, odd = 1, end = len - 1;
	while (even < len && odd < len)
	{
		/*若尾元素为偶数*/
		if ((arr[end] & 0x1) == 0)
		{
			/*交换当前偶数下标与尾元素*/
			swap3(arr[end], arr[even]);
			even += 2;
		}//if
		/*尾元素为奇数，交换*/
		else{
			swap3(arr[end], arr[odd]);
			odd += 2;
		}//else
	}//while
}

int  main()
{
	vector<int> arr = { 1, 3, 4, 2, 5, 7, 21, 48 };
	modify(arr);

	system("pause");
	return 0;

}