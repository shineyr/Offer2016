/*
4.2 矩阵的最小路径和
题目：
给定一个矩阵m，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，
路径上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/*动态规划1，T(n)=O(m*n) S(n)=O(m*n)*/
int minPathSum(vector<vector<int>> matrix)
{
	if (matrix.empty())
		return 0;

	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> ret(m, vector<int>(n, 0));

	/*对于首行和首列的最小路径和*/
	ret[0][0] = matrix[0][0];
	for (int i = 1; i < m; ++i)
		ret[i][0] = ret[i-1][0] + matrix[i][0];
	for (int j = 1; j < n; ++j)
		ret[0][j] = ret[0][j-1] + matrix[0][j];

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			ret[i][j] = min(ret[i - 1][j], ret[i][j - 1]) + matrix[i][j];
		}//for 
	}//for

	return ret[m - 1][n - 1];
}

/*动态规划2 T(n)=O(m*n) S(n)=O(min(m,n))*/
int minPathSum2(vector<vector<int>> matrix)
{
	if (matrix.empty())
		return 0;

	int m = matrix.size(), n = matrix[0].size();
	int less = min(m, n), more = max(m, n);
	bool rowMore = (more == m ? true : false);

	vector<int> ret(less, 0);
	ret[0] = matrix[0][0];
	for (int i = 1; i < less; ++i)
	{
		ret[i] = ret[i - 1] + (rowMore ? matrix[0][i] : matrix[i][0]);
	}//for

	for (int i = 1; i < more; ++i)
	{
		ret[0] = ret[0] + (rowMore ? matrix[i][0] : matrix[0][i]);
		for (int j = 1; j < less; ++j)
		{
			ret[j] = min(ret[j - 1], ret[j]) + (rowMore ? matrix[i][j] : matrix[j][i]);
		}//for
	}//for
	return ret[less - 1];
}

int main()
{
	vector<vector<int>> v = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };

	cout << minPathSum(v) << endl;
	cout << minPathSum2(v) << endl;

	system("pause");
	return 0;
}