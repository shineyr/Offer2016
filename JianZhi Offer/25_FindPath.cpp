/*
* 题目：面试题25 二叉树和为某一值的路径
* 描述：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
* 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return vector<vector<int>>();

		vector<vector<int> > paths;
		vector<int> path;

		findPaths(root, expectNumber, path, 0, paths);

		return paths;
	}

	void findPaths(TreeNode *root, int expectNumber, vector<int> path, int curNumber, vector<vector<int>> &paths)
	{
		//将当前节点值，保存到当前遍历路径
		path.push_back(root->val);
		curNumber += root->val;

		//若是叶节点且路径和为目标值，则保存当前路径
		if (root->left == NULL && root->right == NULL && curNumber == expectNumber)
		{
			paths.push_back(path);
		}

		if (root->left)
			findPaths(root->left, expectNumber, path, curNumber, paths);

		if (root->right)
			findPaths(root->right, expectNumber,path, curNumber, paths);

		//否则，弹出当前节点，返回父节点
		path.pop_back();
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
	vector<int> v = { 10, 5, 12, 4, 7 };
	TreeNode *root = generateTree(v);

	Solution  s;
	vector<vector<int> > ret = s.FindPath(root , 22);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	system("pause");
	return 0;
}