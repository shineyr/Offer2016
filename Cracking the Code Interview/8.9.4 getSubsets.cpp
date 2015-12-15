/*
* 面试题8.9.4 编写一个方法，返回某集合的所有子集；
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	/*方法一：递归实现*/
	vector<vector<int>> getSubsets(vector<int> &nums)
	{
		vector<vector<int> > ret;
		/*空集合只有一个空子集*/
		if (nums.empty())
		{
			ret.push_back(vector<int>());
			return ret;
		}
		/*得到[0,len-2]的子序列的所有子集*/
		vector<vector<int>> tmpSets = getSubsets(vector<int>(nums.begin(), nums.begin() + nums.size() - 1));
		auto iter = tmpSets.begin();
		while (iter != tmpSets.end())
		{
			ret.push_back(*iter);
			(*iter).push_back(nums[nums.size() - 1]);
			ret.push_back(*iter);
			++iter;
		}//while
		return ret;
	}

	/*方法二：利用组合数学的知识*/
	vector<vector<int>> getSubsets2(vector<int> &nums)
	{
		vector<vector<int>> ret;
		/*子集合的个数*/
		int size = 1 << nums.size();
		
		/*每个值对应的二进制序列都反应了一个子集合*/
		for (int i = 0; i < size; ++i)
		{
			vector<int> tmp = convertIntToSet(i, nums);
			ret.push_back(tmp);
		}//for
		return ret;
	}

	vector<int> convertIntToSet(int x, vector<int> &nums)
	{
		vector<int> subset = vector<int>();

		int idx = 0;
		for (int i = x; i > 0; i >>= 1)
		{
			if ((i & 1) == 1)
				subset.push_back(nums[idx]);
			++idx;
		}//for
		return subset;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };

	vector<vector<int>> ret = s.getSubsets2(v);

	for (unsigned i = 0; i < ret.size(); ++i)
	{
		for (unsigned j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << "\t";
		cout << endl;
	}//for

	system("pause");
	return 0;
}