/*
 * 题目：面试题34 丑数
 * 把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	//方法一：逐个判断，时间复杂度高
	int GetUglyNumber_Solution1(int index) {
		if (index <= 0)
			return 0;
		if (index == 1)
			return 1;

		int count = 0 , number = 0;
		while (count < index)
		{
			++number;

			if (isUgly(number))
				++count;
		}//while
		return number;
	}

	//判断丑数
	bool isUgly(int num)
	{
		while (num % 2 == 0)
			num /= 2;

		while (num % 3 == 0)
			num /= 3;

		while (num % 5 == 0)
			num /= 5;

		if (num == 1)
			return true;
		else
			return false;
	}

	//方法二：空间换时间
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		else if (index == 1)
			return 1;

		vector<int> uglyNums(index, 0);
		uglyNums[0] = 1;
		int count = 1;
		vector<int>::iterator iter1, iter2, iter3;
		iter1 = uglyNums.begin();
		iter2 = uglyNums.begin();
		iter3 = uglyNums.begin();

		while (count < index)
		{
			int tmp = min(min(*iter1 * 2, *iter2 * 3), *iter3 * 5);
			uglyNums[count] = tmp;

			//找到下一个* 2、3、5值大于目前最后一个丑数的丑数
			while (*iter1 * 2 <= uglyNums[count])
				iter1++;

			while (*iter2 * 3 <= uglyNums[count])
				iter2++;

			while (*iter3 * 5 <= uglyNums[count])
				iter3++;
			//当前丑数序列数量加1
			++count;
		}//while
		return uglyNums[count - 1];
	}

};

int main()
{
	Solution s;
	cout << s.GetUglyNumber_Solution(5) << endl;

	system("pause");
	return 0;
}