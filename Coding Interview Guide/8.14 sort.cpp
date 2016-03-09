/*
8.14 自然数组的排序
题目：给定一个长度为N的整型数组arr，其中有N个互不相等的自然数1~N，
请实现arr的排序。
要求：时间复杂度O(N)，空间复杂度O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*方法一：借助一个临时变量，跳跃填充方式*/
void sort1(vector<int> &arr)
{
	if (arr.empty())
		return;

	int len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == (i+1))
			continue;
		else{
			/*将i位置的数值tmp放在它应在的位置tmp-1*/
			int tmp = arr[i];
			while (arr[i] != (i + 1))
			{
				/*保存tmp-1位置处，存储的值，下一循环将其放在应该在的位置*/
				int next = arr[tmp - 1];
				arr[tmp - 1] = tmp;
				tmp = next;
			}//while
		}//else
	}//for
}

/*方法二：采用替换的方式*/
void sort2(vector<int> &arr)
{
	if (arr.empty())
		return;

	int len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == (i+1))
			continue;
		else{			
			while (arr[i] != (i + 1))
			{
				int tmp = arr[i];
				arr[i] = arr[tmp - 1];
				arr[tmp - 1] = tmp;
			}//while
		}//else
	}//for
}

int main()
{
	vector<int> v = { 2, 3, 1, 5, 4 };
	sort2(v);

	system("pause");
	return 0;
}