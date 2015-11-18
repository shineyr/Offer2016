/*
 * 面试题41 ：和为s的两个数字
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
 * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	//方法一：二次遍历
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty())
			return vector<int>();

		int sz = array.size();
		vector<int> ret;

		int multi = INT_MAX;
		for (int i = 0; i < sz; ++i)
		{
			for (int j = i + 1; j < sz; ++j)
			{
				if (array[i] + array[j] == sum)
				{
					if (array[i] * array[j] < multi)
					{
						multi = array[i] * array[j];
						ret.clear();
						ret.push_back(array[i]);
						ret.push_back(array[j]);
					}//if
				}//if
			}//for
		}//for
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3, 4, 11, 15 };
	vector<int> ret = s.FindNumbersWithSum(v , 15);

	if (!ret.empty())
		cout << ret[0] << "\t" << ret[1] << endl;

	system("pause");
	return 0;
}