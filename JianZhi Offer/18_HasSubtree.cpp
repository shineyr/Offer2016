/*
 * 树的子结构
 * 题目描述
 * 输入两颗二叉树A，B，判断B是不是A的子结构
 */

#include <iostream>
#include <cstdlib>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

const int flag = INT_MIN;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool ret = false;
		if (pRoot1 && pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
				ret = HasSubtree2(pRoot1, pRoot2);
			if (!ret)
				ret = HasSubtree2(pRoot1->left, pRoot2);
			if (!ret)
				ret = HasSubtree2(pRoot1->right, pRoot2);
		}
		return ret;		
	}

	//第二步骤
	bool HasSubtree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)
			return true;
		
		if (pRoot1 == NULL)
			return false;

		if (pRoot1->val != pRoot2->val)
			return false;
		else
			return HasSubtree2(pRoot1->left, pRoot2->left) && HasSubtree2(pRoot1->right, pRoot2->right);
	}
};

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

int main()
{
	Solution s;

	vector<int> v1 = { 8, flag, 9, 3, 2 };
	vector<int> v2 = {};

	TreeNode *root1 = generateTree(v1);
	TreeNode *root2 = generateTree(v2);
	bool ret = s.HasSubtree(root1, root2);
	cout << ret << endl;

	system("pause");
	return 0;
}