/*
 * 面试题 31 连续子数组的最大和

 * HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
 * 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
 * 常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
 * 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
 * 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 * 你会不会被他忽悠住？
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;

		int maxSum = array[0], tmpSum = array[0] , size = array.size();

		for (int i = 1; i < size; ++i)
		{
			tmpSum += array[i];
			if (tmpSum > maxSum)
				maxSum = tmpSum;			
			//如果当前最大和小于当前元素，改变子数组起点
			if (maxSum < array[i])
			{
				maxSum = array[i];
				tmpSum = array[i];
			}else
				continue;
		}//for
		return maxSum;
	}
};


int main()
{
	Solution s;
	vector<int> v = { 1, -2, 3, 10, -4, 7, 2, -5 };

	cout << s.FindGreatestSumOfSubArray(v) << endl;

	system("pause");
	return 0;
}
