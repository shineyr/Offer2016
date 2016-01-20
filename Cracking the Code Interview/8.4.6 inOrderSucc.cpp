/*
题目描述

请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后
继结点的值。保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

/*建树函数*/
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
		}//if

		//定义非空右子树
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}//if

		tmp->left = left;
		tmp->right = right;
		//弹出当前处理的节点
		que.pop();
	}//for
	return root;
}

class Successor {
public:
	/*方法一，得到中序遍历序列*/
	int findSucc(TreeNode* root, int p) {
		// write code here
		vector<int> inOrderVals;
		inOrder(inOrderVals, root);
		auto iter = find(inOrderVals.begin(), inOrderVals.end(), p);
		if (++iter != inOrderVals.end())
			return *iter;
		return -1;
	}

	/*中序遍历二叉树*/
	void inOrder(vector<int> &vals, TreeNode *root)
	{
		if (!root)
			return;
		inOrder(vals, root->left);
		vals.push_back(root->val);
		inOrder(vals, root->right);
	}

	///*方法二：根据树的结构构造，但是需要树中包含指向父节点的指针*/
	//int findSucc2(TreeNode* root, int p) {
	//	// write code here
	//	/*第一步，找到值为p的二叉树节点*/
	//	TreeNode *node = findTreeNode(root, p);
	//	if (!node)
	//		return -1;
	//	else{
	//		int ret = -1;
	//		/*（1）如果该节点有右子树，则其右子树的最左节点便是其后继*/
	//		if (node->right)
	//		{
	//			node = node->right;
	//			while (node)
	//			{
	//				ret = node->val;
	//				node = node->left;
	//			}//while
	//			return ret;
	//		}//if
	//		else{
	//			/*向上递增，找到node的第一个未遍历祖先*/
	//			TreeNode *p = node->parent;
	//			while (node && p->left != node)
	//			{
	//				node = p;
	//				p = p->parent;
	//			}//while
	//			ret = p->val;
	//			return ret;
	//		}//else
	//		return -1;
	//	}
	//}

	//TreeNode *findTreeNode(TreeNode *root, int p)
	//{
	//	if (!root)
	//		return NULL;
	//	if (root->val == p)
	//		return root;
	//	else{
	//		TreeNode *node = findTreeNode(root->left, p);
	//		if (node != NULL)
	//			return node;
	//		else
	//			return findTreeNode(root->right, p);
	//	}//else		
	//}
};

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);
	Successor s;
	cout << s.findSucc(root, 5) << endl;

	system("pause");
	return 0;
}
