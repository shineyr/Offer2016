/*
8.8 最长可整合子数组长度
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

int getLongestLen(const vector<int> &arr)
{
	if (arr.empty())
		return 0;

	int size = arr.size(), maxLen = 0;
	unordered_set<int> subArr;
	/*验证所有子数组*/
	for (int i = 0; i < size; ++i)
	{
		subArr.clear();
		int maxNum = INT_MIN, minNum = INT_MAX;
		for (int j = i; j < size; ++j)
		{
			/*若含有重复元素，则此子数组不可整合，进入下一循环*/
			if (subArr.count(arr[j]))
				continue;
		
			subArr.insert(arr[j]);
			/*更新该子数组的最大最小值*/
			if (maxNum < arr[j])
				maxNum = arr[j];
			else if (minNum > arr[j])
				minNum = arr[j];

			/*验证该子数组是否为可整合数组:最大值-最小值+1等于子数组长度*/
			if (maxNum - minNum == j - i)
				maxLen = maxLen > (j - i + 1) ? maxLen : (j - i + 1);
		}//for
		return maxLen;
	}
}

int main()
{
	vector<int> arr = { 5, 5, 3, 2, 6, 4, 3 };
	cout << getLongestLen(arr) << endl;

	system("pause");
	return 0;
}