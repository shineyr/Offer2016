/*
 *
 * 题目: 06 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> preOrder, vector<int> inOrder) {
		if (preOrder.empty() && inOrder.empty())
			return NULL;

		return reConstructBinaryTree(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end());
	}

	TreeNode *reConstructBinaryTree(vector<int>::iterator preBeg, vector<int>::iterator preEnd,
		vector<int>::iterator inBeg, vector<int>::iterator inEnd)
	{
		if (preBeg == preEnd && inBeg == inEnd)
			return NULL;

		/*构建根节点*/
		TreeNode *root = new TreeNode(*preBeg);

		int leftLen = 0;
		for (auto iter = inBeg; iter != inEnd; ++iter)
		{
			if (*iter == *preBeg)
				break;
			++leftLen;
		}//for

		root->left = reConstructBinaryTree(preBeg + 1, preBeg + leftLen + 1, inBeg, inBeg + leftLen);
		root->right = reConstructBinaryTree(preBeg + leftLen + 1, preEnd, inBeg + leftLen + 1, inEnd);

		return root;
	}
};

int main()
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 },
		inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Solution s;
	TreeNode *root = s.reConstructBinaryTree(preOrder, inOrder);

	system("pause");
	return 0;
}