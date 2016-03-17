/*
04 相关题目：合并整型数组

有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间以容纳A2。
请实现一个函数，把A2中所有的数字插入到A1中，并且所有的数字是排序的。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void mergeArray(int a[], int la , int maxLen, int b[], int lb)
{
	int newLen = la + lb;
	if (newLen > maxLen)
		return;
	int i = la - 1, j = lb - 1, k = newLen - 1;
	while ( i >= 0 && j >= 0)
	{
		if (a[i] > b[j])
		{
			a[k--] = a[i];
			--i;
		}//if
		else {
			a[k--] = b[j];
			--j;
		}//else
	}//while

	while (i >= 0)
	{
		a[k--] = a[i--];
	}//while

	while (j >= 0)
	{
		a[k--] = b[j--];
	}//while

	return;
}

int main()
{
	int a[100] = { 1, 5, 7, 9, 12 };
	int b[10] = { 2, 4, 8, 24 };

	mergeArray(a, 5, 100, b,4);

	system("pause");
	return 0;

}