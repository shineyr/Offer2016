/*
 * 8.1.7 编写一个算法，若M*N矩阵中某个元素为0，则将其所在的行和列元素值清0
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	void setZeros(vector<vector<int>> &matrix)
	{
		if (matrix.empty())
			return;
		int r = matrix.size(), c = matrix[0].size();
		//标记含有0值的行和列
		vector<int> rows(r, 0), cols(c, 0);

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (matrix[i][j] == 0)
				{
					rows[i] = 1;
					cols[j] = 1;
				}//if
			}//for
		}//for

		//将标记的行和列元素清0
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (rows[i] || cols[j])
					matrix[i][j] = 0;
			}//for
		}//for
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v = { { 1, 2, 0 }, { 2, 4, 5 }, { 0, 3, 4 } };

	s.setZeros(v);

	for (unsigned i = 0; i < v.size(); ++i)
	{
		for (unsigned j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	system("pause");
	return 0;
}