/*
 * 面试题39 平衡二叉树
 * 题目二 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
#include <iostream>
#include <cstdlib>

using namespace std;
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	//求深度
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot)
			return 0;
		int dLeft = TreeDepth(pRoot->left);
		int dRight = TreeDepth(pRoot->right);
		return (dLeft > dRight) ? (dLeft + 1) : (dRight + 1);
	}

	//方法一：需要重复遍历多次
	bool IsBalanced_Solution1(TreeNode* pRoot) {
		if (!pRoot)
			return true;

		int dLeft = TreeDepth(pRoot->left);
		int dRight = TreeDepth(pRoot->right);

		if (abs(dLeft - dRight) > 1)
			return false;
		else{
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		}
	}

	//方法二：每个节点只需要遍历一次
	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		int depth = 0;
		return ISBalanced(pRoot, depth);
	}

	bool ISBalanced(TreeNode *root, int &depth)
	{
		if (!root)
		{
			depth = 0;
			return true;
		}
		
		int dLeft, dRight;
		if (ISBalanced(root->left, dLeft) && ISBalanced(root->right, dRight))
		{
			if (abs(dLeft - dRight) <= 1)
			{
				depth = 1 + (dLeft > dRight ? dLeft : dRight);
				return true;
			}
		}//if
		return false;
	}
};