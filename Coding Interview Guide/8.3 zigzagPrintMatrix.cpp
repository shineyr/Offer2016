/*
8.3 "之"字形打印矩阵
给定一个矩阵matrix，按照“之”字形的方式打印这个矩阵，例如：
1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	16
之字形打印结果为：1 2 5 9 6 3 4 7 10 13 14 11 8 12 15 16

要求：额外空间复杂度为O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void zigzagPrintMatrix(vector<vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int tR = 0, tC = 0, dR = 0, dC = 0;

	int endR = m - 1, endC = n - 1;

	/*方向控制变量*/
	bool fromUp = false;
	while (tR != endR + 1)
	{
		if (fromUp)
		{
			int curR = tR, curC = tC;
			while (curR != dR + 1)
			{
				cout << matrix[curR++][curC--] << "\t";
			}//while
		}
		else{
			int curR = dR, curC = dC;
			while (curR != tR - 1)
			{
				cout << matrix[curR--][curC++] << "\t";
			}//while
		}//else

		tR = tC == endC ? tR + 1 : tR;
		tC = tC == endC ? tC : tC + 1;
		dC = dR == endR ? dC + 1 : dC;
		dR = dR == endR ? dR : dR + 1;

		fromUp = !fromUp;
	}//while
	cout << endl;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	zigzagPrintMatrix(matrix);

	system("pause");
	return 0;
}