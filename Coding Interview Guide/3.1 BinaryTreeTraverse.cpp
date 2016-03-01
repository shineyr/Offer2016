/*
3.1 分别用递归和非递归的方式实现二叉树先序、中序、后序遍历
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int v) :val(v), left(NULL), right(NULL){}
};

/*递归先序遍历*/
void preOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	cout << tree->val << "\t";
	preOrderRecur(tree->left);
	preOrderRecur(tree->right);
}

/*非递归实现先序遍历*/
void preOrderUnRecur(TreeNode *tree)
{
	if (!tree)
		return;

	stack<TreeNode *> stk;
	/*压入根节点*/
	stk.push(tree);
	while (!stk.empty())
	{
		TreeNode *tmp = stk.top();
		cout << tmp->val << "\t";
		stk.pop();

		/*先压入栈右子树节点，再压入栈左子树节点*/
		if (tmp->right)
			stk.push(tmp->right);
		if (tmp->left)
			stk.push(tmp->left);
	}//while
}

/*递归实现中序遍历*/
void inOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	inOrderRecur(tree->left);
	cout << tree->val << "\t";
	inOrderRecur(tree->right);
}

/*非递归实现中序遍历*/
void inOrderUnRecur(TreeNode *tree)
{
	if (!tree)
		return;

	stack<TreeNode *> stk;
	TreeNode *cur = tree;
	while (!stk.empty() || cur)
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}//if
		else{
			cur = stk.top();
			stk.pop();
			cout << cur->val << "\t";
			cur = cur->right;
		}//else
	}//while
}

/*递归实现后序遍历*/
void postOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	postOrderRecur(tree->left);
	postOrderRecur(tree->right);
	cout << tree->val << "\t";
}

/*非递归实现后序遍历1*/
void postOrderRecur1(TreeNode *tree)
{
	if (!tree)
		return;

	/*两个辅助栈*/
	stack<TreeNode *> stk1;
	stack<TreeNode *> stk2;

	stk1.push(tree);
	while (!stk1.empty())
	{
		TreeNode *tmp = stk1.top();
		stk2.push(tmp);
		stk1.pop();
		if (tmp->left)
			stk1.push(tmp->left);
		if (tmp->right)
			stk1.push(tmp->right);		
	}//while

	while (!stk2.empty())
	{
		cout << stk2.top()->val << "\t";
		stk2.pop();
	}//while
}

/*非递归实现后序遍历2*/
void postOrderRecur2(TreeNode *h)
{
	if (!h)
		return;

	/*实现过程中，h代表最近一次弹出并打印的节点*/
	stack<TreeNode *> stk;
	stk.push(h);
	TreeNode *tmp;
	while (!stk.empty())
	{
		/*tmp代表栈顶节点*/
		tmp = stk.top();
		if (tmp->left && h != tmp->left && h != tmp->right)
		{
			stk.push(tmp->left);
		}//else
		else if (tmp->right && h != tmp->right)
		{
			stk.push(tmp->right);
		}//elif
		else
		{
			cout << tmp->val << "\t";
			stk.pop();
			h = tmp;
		}//else
	}//while
}

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

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);

	cout << "先序遍历：" << endl;
	cout << "\t递  归：\t";
	preOrderRecur(root);
	cout << endl;
	cout << "\t非递归：\t";
	preOrderUnRecur(root);
	cout << endl;

	cout << "中序遍历：" << endl;
	cout << "\t递  归：\t";
	inOrderRecur(root);
	cout << endl;
	cout << "\t非递归：\t";
	inOrderUnRecur(root);
	cout << endl;

	cout << "后序遍历：" << endl;
	cout << "\t递   归：\t";
	postOrderRecur(root);
	cout << endl;
	cout << "\t非递归1：\t";
	postOrderRecur1(root);
	cout << endl;

	cout << "\t非递归2：\t";
	postOrderRecur2(root);
	cout << endl;

	system("pause");
	return 0;

}
