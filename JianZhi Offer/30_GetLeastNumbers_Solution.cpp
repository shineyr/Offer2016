/*
 * 面试题 30 最小的k个数
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
	//方法一：使用stl库函数排序，然后返回前k个元素，复杂度为O(nlogn)
	vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
		if (input.empty() || k <= 0 || k > input.size())
			return vector<int>();

		int size = input.size();

		if (k == size)
			return input;

		sort(input.begin(), input.end());

		return vector<int>(input.begin(), input.begin() + k);
	}

	//方法二：O(nlogk)的算法，特别适合处理海量数据
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k <= 0 || k > input.size())
			return vector<int>();

		int size = input.size();

		if (k == size)
			return input;

		//选择基于红黑树的multiset容器
		typedef multiset<int , std::greater<int> > intSet;
		typedef multiset<int>::iterator setIter;

		intSet kNums;
		for (int i = 0; i < size; ++i)
		{
			if (kNums.size() < k)
				kNums.insert(input[i]);
			else{
				//替换最大元素
				setIter iterMax = kNums.begin();
				if (input[i] < *iterMax)
				{
					//删除最大
					kNums.erase(iterMax);
					kNums.insert(input[i]);
				}//if
				continue;
			}
		}//for
		vector<int> ret(kNums.begin(), kNums.end());
		reverse(ret.begin(), ret.end());
		return ret;

	}
};

int main()
{
	Solution s;
	vector<int > v = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> ret = s.GetLeastNumbers_Solution(v, 4);

	system("pause");
	return 0;
}