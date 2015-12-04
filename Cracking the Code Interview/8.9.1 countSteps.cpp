/*
* 面试题8.9.1 n阶楼梯问题
* 有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1、2、3阶，实现一个方法，计算小孩有多少种上楼梯的方式。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	//方法一，递归实现，时间复杂度O(3^n)
	int countSteps1(int n)
	{
		if (n <= 0)
			return 0;
		else if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else if (n == 3)
			return countSteps1(1) + countSteps1(2) + 1;
		else
		{
			return countSteps1(n - 1) + countSteps1(n - 2) + countSteps1(n - 3);
		}//else
	}

	//方法二：借助中间缓存，利用动态规划的思想，优化性能
	int countSteps(int n)
	{
		if (0 == n)
			return 0;
		vector<int> nums(n + 1, 0);
		nums[1] = 1;
		nums[2] = 2;
		nums[3] = nums[1] + nums[2] + 1;

		for (int i = 4; i <= n; ++i)
		{
			nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
		}//for
		return nums[n];
	}
};

int main()
{
	Solution s;
	cout << s.countSteps1(6) << endl;
	cout << s.countSteps(6) << endl;
	system("pause");
	return 0;
}