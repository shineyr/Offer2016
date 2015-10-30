/*
 * 题目：调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty())
			return;

		int size = array.size();
		vector<int> odd, even;
		for (int i = 0; i < size; ++i)
		{
			if (array[i] & 0x1 == 1)
				odd.push_back(array[i]);
			else
				even.push_back(array[i]);
		}//for
		array.clear();
		for (size_t i = 0; i < odd.size(); ++i)
			array.push_back(odd[i]);
		for (size_t j = 0; j < even.size(); ++j)
			array.push_back(even[j]);
	}

};
//
//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//
//	Solution s;
//	s.reOrderArray(v);
//
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}