/*
* 题目: 矩形覆盖
* 描述:
* 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
* 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		int fminus1 = 2, fminus2 = 1 , fn;
		for (int i = 3; i <= number; ++i)
		{
			fn = fminus1 + fminus2;
			fminus2 = fminus1;
			fminus1 = fn;
		}//for

		return fn;
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.rectCover(4) << endl;
//
//	system("pause");
//
//	return 0;
//}