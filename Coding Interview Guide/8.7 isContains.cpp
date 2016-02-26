/*
8.7 在行列都排好序的矩阵中找数
给定一个有N*M的整型矩阵matrix和一个整数k，matrix的每一行，每一列都是排好序的。
实现一个函数，判断k是否在matrix中。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

bool isContains(const vector<vector<int>> &matrix, const int &k)
{
	if (matrix.empty())
		return false;
	int m = matrix.size(), n = matrix[0].size();
	int row = 0, col = n - 1;
	while (row < m&& col >= 0)
	{
		if (k == matrix[row][col])
			return true;
		else if (k > matrix[row][col])
			++row;
		else
			--col;
	}//while
	return false;
}

int main()
{
	vector<vector<int>> matrix = { { 0, 1, 2, 5 }, { 2, 3, 4, 7 }, { 4, 4, 4, 8 }, { 5, 7, 7, 9 } };

	bool ret = isContains(matrix, 7);

	cout << ret << endl;

	system("pause");
	return 0;
}