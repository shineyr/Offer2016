/*
 * 题目描述
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty())
			return vector<int>();

		vector<int> ret;
		//求出该矩阵的行数和列数
		int m = matrix.size(), n = matrix[0].size();
		//当前处理的螺旋起始行数和列数
		int r = 0, c = 0;

		for (int r = 0, c = 0; r < m&&c < n; ++r, ++c)
		{
			//输出该螺旋首行
			for (int j = c; j < n; ++j)
				ret.push_back(matrix[r][j]);

			//输出该螺旋尾列
			for (int i = r + 1; i < m; ++i)
				ret.push_back(matrix[i][n-1]);

			//输出该螺旋尾行
			for (int j = n - 2; j >= c && r != m-1; --j)
				ret.push_back(matrix[m - 1][j]);

			//输出该螺旋首列
			for (int i = m - 2; i > r && c != n-1; --i)
				ret.push_back(matrix[i][c]);

			//处理下一螺旋
			--m;
			--n;
		}//while
		return ret;
	}
};

int main()
{
	vector<vector<int> > v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<int> > v2 = { { 1 }, { 2 }, { 3 }, { 4 } ,{ 5 } };
	Solution s;
	vector<int> ret = s.printMatrix(v);

	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}