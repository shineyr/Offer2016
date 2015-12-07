/*
* 面试题8.5.1 给定两个32位的整数N和M，以及表示比特位置的i和j。编写一个方法，将M插入N，
* 使得M从N的第j位开始，到第i位结束。假定从第j位到第i位足以容纳M，也即若M=10011，那么j和i之间
* 至少可以容纳5个位。例如，不可能出现j=3和i=2的情况，因为第3位和第2位之间放不下M。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	
	int updateBits(int n, int m, int j, int i)
	{
		/*第一步，将n的第j位到第i位清零，依次处理区间左侧和右侧*/
		//得到一连串1
		int tmp = ~0;
		//在位置j之前的位均为1
		int left = tmp << (j + 1);

		//在位置i之后的位均为1
		int right = (1 << i) - 1;

		//得到除了i到j位为0，其余位为1
		int mask = left | right;

		/*第二步，清除n的第i到j位之间的值*/
		n &= mask;

		/*第三步，填充m */
		m <<= i;

		return n | m;
	}
};

int main()
{
	Solution s;
	int n = 10000000000, m = 10011, i = 2, j = 6;

	cout << s.updateBits(n, m, j, i) << endl;

	system("pause");
	return 0;

}