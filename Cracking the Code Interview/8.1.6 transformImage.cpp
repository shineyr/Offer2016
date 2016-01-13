/*
题目描述

有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		if (mat.empty())
			return mat;

		for (int layer = 0; layer < n/2; ++layer)
		{
			int first = layer, last = n - layer - 1;
			for (int i = first; i < last; ++i)
			{
				int offset = i - first;
				/*存储上边*/
				int top = mat[first][i];
				/*左到上*/
				mat[first][i] = mat[last - offset][first];

				/*下到左*/
				mat[last - offset][first] = mat[last][last - offset];

				/*右到下*/
				mat[last][last - offset] = mat[i][last];

				/*上到右*/
				mat[i][last] = top;
			}//for
		}//for

		return mat;
	}
};

int main()
{
	vector<vector<int> > mat = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	for (unsigned i = 0; i < mat.size(); ++i)
	{
		for (unsigned j = 0; j < mat[i].size(); ++j)
		{
			cout << mat[i][j] << "\t";
		}//for
		cout << endl;
	}
	Transform t;
	mat = t.transformImage(mat , mat.size());
	for (unsigned i = 0; i < mat.size(); ++i)
	{
		for (unsigned j = 0; j < mat[i].size(); ++j)
		{
			cout << mat[i][j] << "\t";
		}//for
		cout << endl;
	}
	system("pause");
	return 0;


}