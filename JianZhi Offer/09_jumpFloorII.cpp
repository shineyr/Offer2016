/*
* 题目: 跳台阶
* 描述:
* 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
		
		vector<int> ways(number + 1, 0);
		//只有一级台阶时，一种方式
		ways[1] = 1;
		for (int i = 2; i <= number; ++i)
		{
			//可以一次跳
			ways[i] += 1;
			//多次跳
			for (int j = 1; j < i; ++j)
			{
				ways[i] += ways[j];
			}
		}
		return ways[number];
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.jumpFloorII(4) << endl;
//
//	system("pause");
//	return 0;
//}