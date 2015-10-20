/*
* 题目: 跳台阶
* 描述:
* 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



class Solution {
public:
	int jumpFloor(int number) {
		if (number < 1)
			return 0;
		else if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else{
			int fminus2 = 1, fminus1 = 2 , fn = 0;
			for (int i = 3; i <= number; ++i)
			{
				fn = fminus1 + fminus2;
				fminus2 = fminus1;
				fminus1 = fn;
			}//for
			return fn;
		}//else
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.jumpFloor(4) << endl;
//
//	system("pause");
//	return 0;
//}