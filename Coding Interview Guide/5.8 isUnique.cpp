/*
5.8 判断字符数组中是否所有的字符都只出现过一次

题目：
给定一个字符类型数组chas[]，判断chas中是否所有的字符都只出现过一次，
请根据以下不同的两种要求实现两个函数。

要求：
（1）实现时间复杂度为O(N)的方法
（2）在保证额外空间复杂度O(1)的前提下，实现时间复杂度尽量低的算法。
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

/*要求（1）利用set结构的唯一性辅助实现*/
bool isUnique(char str[])
{
	if (str == NULL)
		return true;

	unordered_set<char> cSet;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (cSet.find(str[i]) != cSet.end())
			return false;
		cSet.insert(str[i]);
	}//for

	return true;
}

/*要求（2）采用堆排序算法对字符数组排序，然后遍历判断字符的唯一性*/
void swap(char str[], int parent, int i)
{
	char tmp = str[parent];
	str[parent] = str[i];
	str[i] = tmp;
}

void heapInsert(char str[], int i)
{
	int parent = 0;
	while (i != 0)
	{
		parent = (i - 1) / 2;
		if (str[parent] < str[i])
		{
			swap(str, parent, i);
			i = parent;
		}//if
		else
		{
			break;
		}
	}//while
}

/*堆调整*/
void heapify(char str[], int i, int size)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;
	while (left < size)
	{
		if (str[left] > str[i])
			largest = left;

		if (right < size && str[right] > str[largest])
			largest = right;

		if (largest != i)
			swap(str, largest, i);
		else
		{
			break;
		}//else

		i = largest;
		left = 2 * i + 1;
		right = 2 * i + 2;
	}//while
}
void heapSort(char str[])
{
	if (str == NULL)
		return;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		heapInsert(str, i);
	}//for

	for (int i = strlen(str) - 1; i > 0; --i)
	{
		swap(str, 0, i);
		heapify(str, 0, i);
	}//for
}
bool isUnique2(char str[])
{
	if (str == NULL)
		return true;
	heapSort(str);
	for (int i = 1; i < strlen(str); ++i)
	{
		if (str[i] == str[i - 1])
			return false;
	}//for
	return true;
}

//int main()
//{
//	char str[] = "121";
//	cout << isUnique(str) << endl;
//	cout << isUnique2(str) << endl;
//
//	char str2[] = "abc";
//	cout << isUnique(str2) << endl;
//	cout << isUnique2(str2) << endl;
//
//	system("pause");
//	return 0;
//}