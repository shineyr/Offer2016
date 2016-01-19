/*
题目描述

实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，
其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Balance {
public:

	bool isBalance(TreeNode* root) {
		// write code here
		if (!root)
			return true;
		else if (abs(height(root->left) - height(root->right)) > 1)
			return false;
		else
			return isBalance(root->left) && isBalance(root->right);

	}

	int height(TreeNode *root)
	{
		if (!root)
			return 0;
		else
		{
			return max(height(root->left), height(root->right)) + 1;
		}//ekse
	}

	/*改进过的算法,空间复杂度为O(H) 时间复杂度为O(N)*/
	bool isBalance2(TreeNode *root)
	{
		if (checkHeight(root) == -1)
			return false;
		else
			return true;
	}

	int checkHeight(TreeNode *root)
	{
		/*返回空树的高度为0*/
		if (root == NULL)
			return 0;

		/*检查左子树是否平衡*/
		int leftHeight = checkHeight(root->left);
		/*若返回-1，说明左子树为非平衡树*/
		if (leftHeight == -1)
			return -1;

		int rightHeight = checkHeight(root->right);
		if (rightHeight == -1)
			return -1;

		/*检查当前节点是否平衡*/
		int heightDiff = abs(leftHeight - rightHeight);
		if (heightDiff > 1)
			return -1;
		else{
			/*返回高度*/
			return max(leftHeight, rightHeight) + 1;
		}
	}
};

