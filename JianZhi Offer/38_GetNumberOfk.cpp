/*
 * 面试题38：数字在排序数组中出现的次数
 * 描述：统计一个数字在排序数组中出现的次数。
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//二分法最差时间复杂度O(n)
	int GetNumberOfK1(vector<int> data, int k) {
		if (data.empty())
			return 0;
	
		int lhs = 0, rhs = data.size() - 1, pos = -1;

		while (lhs <= rhs)
		{
			pos = (lhs + rhs) / 2;
			if (data[pos] == k)
				break;
			else if (data[pos] < k)
			{
				lhs = pos + 1;
			}
			else{
				rhs = pos - 1;
			}//else
		}//while
		//若目标元素不存在
		if (pos == -1 || lhs > rhs)
			return 0;
		else{
			int count = 1;
			int i = pos - 1, j = pos + 1;
			while (i >= 0 && data[i] == k)
			{
				++count;
				--i;
			}

			while (j < data.size() && data[j] == k)
			{
				++count;
				++j;
			}

			return count;
		}//else
	}
	//方法二：使用二分查找得到第一个和最后一个k出现的位置
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int first = getFirstK(data, k);
		int last = getLastK(data, k);

		if (first != -1 && last != -1)
			return last - first + 1;
		return 0;
	}

	int getFirstK(vector<int> data, int k)
	{
		if (data.empty())
			return -1;

		int pos = -1, lhs = 0, rhs = data.size() - 1;
		while (lhs <= rhs)
		{
			pos = (lhs + rhs) / 2;
			if (data[pos] == k)
			{
				//出现在首尾或者是第一个k时直接返回
				if ((pos == 0) || (pos > 0 && data[pos - 1] != k))
					return pos;
				else
					rhs = pos - 1;
			}//if
			else if (data[pos] < k)
			{
				lhs = pos + 1;
			}
			else{
				rhs = pos - 1;
			}
		}//while
		return -1;
	}
	int getLastK(vector<int> data, int k)
	{
		if (data.empty())
			return -1;

		int pos = -1, lhs = 0, rhs = data.size() - 1;
		while (lhs <= rhs)
		{
			pos = (lhs + rhs) / 2;
			if (data[pos] == k)
			{
				//出现在首尾或者是第一个k时直接返回
				if ((pos == data.size() - 1) || (pos < data.size()-1 && data[pos + 1] != k))
					return pos;
				else
					lhs = pos + 1;
			}//if
			else if (data[pos] < k)
			{
				lhs = pos + 1;
			}
			else{
				rhs = pos - 1;
			}
		}//while
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> data = { 1, 2, 3, 4, 5, 5, 5, 6, 7 };
	cout << s.GetNumberOfK(data , 5) << endl;

	system("pause");
	return 0;
}