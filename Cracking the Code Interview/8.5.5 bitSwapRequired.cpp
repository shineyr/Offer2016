/*
* 面试题8.5.5 编写一个函数，确定需要改变几个位才能将整数A转换为整数B
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	int bitSwapRequired(int A, int B)
	{
		//对AB异或结果，从低到高依次判断当前位是否为1
		int c = A^B, count = 0;
		for (; c != 0; c >>= 1)
		{
			count += c & 1;
		}//for
		return count;
	}

	//方法二
	int bitSwapRequired2(int a, int b)
	{
		int c = a ^ b, count = 0;
		//对ab异或结果，依次反转最低有效位
		for (; c != 0; c = c&(c - 1))
		{
			++count;
		}//for
		return count;
	}

};

int main()
{
	Solution s;

	cout << s.bitSwapRequired(7, 8) << endl;
	cout << s.bitSwapRequired2(7, 8) << endl;

	system("pause");
	return 0;
}