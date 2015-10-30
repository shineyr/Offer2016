/*
 * 二维数组中的查找：
 *
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		if (array.empty())
			return false;
		//求二维矩阵的行数和列数
		int rows = array.size(), cols = array[0].size();

		int r = 0, c = cols - 1;
		while (r < rows && c >= 0)
		{
			if (array[r][c] == target)
				return true;
			//则目标元素只可能位于左下侧子矩阵
			else if (array[r][c] > target)
			{
				c--;
			}
			//则目标元素只可能位于右下侧子矩阵
			else{
				++r;
			}
		}//while
		return false;
	}
};

int main()
{
	vector<vector<int> > arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	Solution s;

	bool ret = s.Find(arr, 9);

	cout << ret << endl;
	system("pause");
	return 0;
}
