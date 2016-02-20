/*
8.1 转圈打印矩阵
给定一个整型矩阵matrix，请按照转圈的方式打印；

要求：
额外空间复杂度为O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void spiralPrintMatrix(vector<vector<int>> &matrix)
{
	if (matrix.empty())
		return;
	int m = matrix.size();
	int n = matrix[0].size();

	int tRow = 0, tCol = 0, dRow = m - 1, dCol = n - 1;
	while (tRow <= dRow && tCol <= dCol)
	{
		int r = tRow, c = tCol;
		/*打印首行*/
		for (; c < dCol; ++c)
			cout << matrix[r][c] << "\t";
		/*打印尾列*/
		for (; r < dRow; ++r)
			cout << matrix[r][c] << "\t";
		/*打印尾行*/
		for (; c>tCol; --c)
			cout << matrix[r][c] << "\t";
		for (; r>tRow; --r)
			cout << matrix[r][c] << "\t";

		++tRow; ++tCol;
		--dRow; --dCol;
	}//while
	cout << endl;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	spiralPrintMatrix(matrix);

	system("pause");
	return 0;
}