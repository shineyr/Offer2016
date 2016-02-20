/*
8.2 将正方形矩阵顺时针转动90度

给定一个N*N的矩阵matrix，把这个矩阵调整成顺时针转动90度后的形式。

要求：空间复杂度O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void rotate90(vector<vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();

	int tR = 0, tC = 0, dR = m - 1, dC = n - 1;
	while (tR < dR)
	{
		int times = dC - tC;
		for (int i = 0; i < times; ++i)
		{
			int tmp = matrix[tR][tC + i];
			matrix[tR][tC + i] = matrix[dR - i][tC];
			matrix[dR - i][tC] = matrix[dR][dC - i];
			matrix[dR][dC - i] = matrix[tR + i][dC];
			matrix[tR + i][dC] = tmp;
		}//for
		++tR; ++tC;
		--dR; --dC;
	}//while
	return;
}


int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	for (unsigned int i = 0; i < matrix.size(); ++i)
	{
		for (unsigned int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	rotate90(matrix);
	cout << "旋转后：" << endl;
	for (unsigned int i = 0; i < matrix.size(); ++i)
	{
		for (unsigned int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	system("pause");
	return 0;
}