/*
* 面试题8.9.2 计算网格路径数。
* 设想有个机器人坐在X*Y网络的左上角，只能向右、向下移动。机器人从(0,0)到(x,y)有多少种走法。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	//方法一：递归实现，性能比较差
	int countPaths1(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		if (x == 0 || y == 0)
			return 1;
		else
			return countPaths1(x - 1, y) + countPaths1(x, y - 1);
	}

	//方法二：二项式推导结果为(x+y)!/x!y!
	int countPaths2(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		if (x == 0 || y == 0)
			return 1;
		else
			return factorial(x + y) / (factorial(x)*factorial(y));
	}
	int factorial(int n)
	{
		int ret = 1;
		while (n)
			ret *= n--;
		return ret;
	}

	//方法三：动态规划
	int countPaths(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		vector<vector<int> > paths(x + 1, vector<int>(y + 1, 0));
		for (int i = 1; i <= x; ++i)
			paths[i][0] = 1;
		for (int j = 1; j <= y; ++j)
			paths[0][j] = 1;
		
		for (int i = 1; i <= x; ++i)
		{
			for (int j = 1; j <= y; ++j)
			{
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}//for
		}//for
		return paths[x][y];
	}
};

int main()
{
	Solution s;
	cout << s.countPaths1(2, 4) << endl;
	cout << s.countPaths2(2, 4) << endl;
	cout << s.countPaths(2, 4) << endl;

	system("pause");
	return 0;
}