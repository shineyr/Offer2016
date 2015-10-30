/*
 * 二叉搜索树的后序遍历序列	
 * 题目描述
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		int size = sequence.size();

		vector<int> left_sequence , right_sequence;
		//遍历该后序序列，小于尾节点的元素为左子树，大于尾节点的元素为右子树
		int i;
		for (i = 0; i < size && sequence[i] < sequence[size - 1]; ++i)
			left_sequence.push_back(sequence[i]);

		while (i < size - 1)
		{
			if (sequence[i] < sequence[size - 1])
				return false;
			right_sequence.push_back(sequence[i]);
			++i;
		}

		//左右子树可以为空
		bool l = true, r = true;
		if (!left_sequence.empty())
			l = VerifySquenceOfBST(left_sequence);
		if (!right_sequence.empty())
			r = VerifySquenceOfBST(right_sequence);
		return l && r;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> v = { 4, 8, 6, 12, 16, 14, 10 };
//
//	cout << s.VerifySquenceOfBST(v) << endl;
//
//	system("pause");
//	return 0;
//}