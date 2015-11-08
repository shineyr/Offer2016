/*
 * 面试题29 ：数组中出现次数超过一半的数字
 * 数组中有一个数字出现的次数超过数组长度的一半，
 * 请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
 * 如果不存在则输出0。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//方法一：排序，找中位数
	int MoreThanHalfNum_Solution1(vector<int> numbers) {
		if (numbers.empty())
			return 0;

		//求数组长度
		int size = numbers.size();

		sort(numbers.begin(), numbers.end());

		int ret = numbers[size / 2 - 1];

		//检验出现次数是否超过数组长度的一半
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (numbers[i] == ret)
				++count;
		}//for
		if (count > size / 2)
			return ret;
		else
			return 0;
	}

	//方法二，根据数组的特点找出O(n)的算法
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		/* 利用两个变量 一个ret存储数组中当前值，一个count保存次数
		 * 当遍历下一个元素时，若与前一元素相同则次数+1 ， 若不同则次数-1 ， 当次数 = 0 时，保存下一个元素，并把次数 设为1
		 * 由于我们要找的元素出现次数比其他所有元素出现的次数之和还多，所以要找的元素肯定是最后一次把次数设定为1的元素
		*/

		int ret = numbers[0], count = 1;
		int size = numbers.size();
		for (int i = 1; i < size; ++i)
		{
			if (count == 0)
			{
				ret = numbers[i];
				count = 1;
				continue;
			}
			else if (numbers[i] == ret)
			{
				++count;
			}
			else{
				--count;
			}
		}//for

		//检验出现次数是否超过数组长度的一半
		count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (numbers[i] == ret)
				++count;
		}//for
		if (count > size / 2)
			return ret;
		else
			return 0;
		
	}

};

int main()
{
	vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };

	Solution s;
	cout << s.MoreThanHalfNum_Solution(v) << endl;

	system("pause");
	return 0;
}