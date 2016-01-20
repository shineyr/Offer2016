/*
题目描述

请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

/*二叉树节点数据结构*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

const int flag = INT_MAX;
TreeNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeNode *root = new TreeNode(nums[0]);
	queue<TreeNode *> que;
	que.push(root);
	//求出所给元素个数，对应二叉查找树节点个数
	int size = nums.size();
	for (int i = 1; i < size; i += 2)
	{
		//处理队首节点的左右子树
		TreeNode *tmp = que.front();
		TreeNode *left = NULL, *right = NULL;
		//定义非空左子树
		if (nums[i] != flag)
		{
			left = new TreeNode(nums[i]);
			que.push(left);
		}

		//定义非空右子树
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}

		tmp->left = left;
		tmp->right = right;
		//弹出当前处理的节点
		que.pop();
	}
	return root;
}

class Checker {
public:
	/*方法一，利用二叉查找树中序遍历为有序的规则*/
	int lastVal = INT_MIN;
	bool checkBST1(TreeNode* root) {
		// write code here
		if (!root)
			return true;

		/*递归检查左子树*/
		if (!checkBST1(root->left))
			return false;

		/*比较当前节点，并更新已遍历节点最后的值*/
		if (root->val <= lastVal)
			return false;
		lastVal = root->val;

		/*递归检查右子树*/
		if (!checkBST1(root->right))
			return false;
		return true;
	}

	/*方法二，最大最小值法*/
	bool checkBST(TreeNode* root) {
		// write code here
		if (!root)
			return true;
		return checkBST2(root, INT_MAX, INT_MIN);
	}
	bool checkBST2(TreeNode *root, int maxVal, int minVal)
	{
		if (!root)
			return true;
		if (root->val < minVal || root->val >= maxVal)
			return false;
		if (!checkBST2(root->left, root->val, minVal) || !checkBST2(root->right, maxVal, root->val))
			return false;
		return true;
	}
};

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);

	Checker c;
	bool ret = c.checkBST(root);

	cout << ret << endl;

	system("pause");
	return 0;
}