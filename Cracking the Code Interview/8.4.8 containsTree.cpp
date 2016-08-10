/*
题目：你由两颗非常大的二叉树：T1,有几百万个节点；T2有几百个节点。
设计一个算法，判断T2是否为T1的子树。

如果T1有一个节点n，其子树与T2一模一样，则T2为T1的子树。也就是说，从节点n
处把树砍断，得到的树与T2完全相同。
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

class Solution {
public:
	bool containsTree(TreeNode *t1, TreeNode *t2)
	{
		if (t2 == NULL)
			return true;

		return subTree(t1, t2);
	}

	/*判断t2是否为t1的子树*/
	bool subTree(TreeNode *t1, TreeNode *t2)
	{
		if (t1 == NULL)
			return false;
		
		if (t1->val == t2->val)
			return matchTree(t1, t2);
		else
			return subTree(t1->left, t2) || subTree(t1->right, t2);
	}

	/*判断两颗树是否完全一致*/
	bool matchTree(TreeNode *t1, TreeNode *t2)
	{
		if (t1 == NULL && t2 == NULL)
			return true;
		else if (t1 == NULL || t2 == NULL)
			return false;
		else if (t1->val != t2->val)
			return false;
		else
			return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
	}

};

int main()
{
	vector<int> v1 = { 7, 6, flag, 4, flag, 2, 5, 8, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *t1 = generateTree(v1);

	vector<int> v2 = {2, 8, 3};
	TreeNode *t2 = generateTree(v2);

	cout << Solution().containsTree(t1, t2) << endl;
	system("pause");
	return 0;
}