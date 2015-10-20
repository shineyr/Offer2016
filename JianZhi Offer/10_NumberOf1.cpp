/*
 * 题目：二进制中1的个数
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			++count;
			//把一个整数减去1 再与原整数做与运算，会把该整数最右边一个1变为0
			n = (n - 1) & n;
		}//while

		return count;
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1(9) << endl;

	
	system("pause");
	return 0;
}