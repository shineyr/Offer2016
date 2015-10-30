///*
// * 从上往下打印二叉树	
// * 题目描述
// * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
// */
//
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
///*
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};*/
//
//struct TreeNode
//{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL){}
//};
//
//class Solution {
//public:
//	vector<int> PrintFromTopToBottom(TreeNode *root) {
//		if (!root)
//			return vector<int>();
//
//		vector<int> ret;
//
//		queue<TreeNode *> parent;
//		parent.push(root);
//
//		while (!parent.empty())
//		{
//			queue<TreeNode *> child;
//			while (!parent.empty())
//			{
//				ret.push_back(parent.front()->val);
//				if (parent.front()->left)
//					child.push(parent.front()->left);
//				if (parent.front()->right)
//					child.push(parent.front()->right);
//				//弹出父层当前节点
//				parent.pop();
//			}
//			parent = child;
//		}//while
//		return ret;
//	}
//};
//
//const int flag = INT_MIN;
//
//TreeNode *generateTree(vector<int> &nums)
//{
//	if (nums.empty())
//		return NULL;
//
//	TreeNode *root = new TreeNode(nums[0]);
//	queue<TreeNode *> que;
//	que.push(root);
//	//求出所给元素个数，对应二叉查找树节点个数
//	int size = nums.size();
//	for (int i = 1; i < size; i += 2)
//	{
//		//处理队首节点的左右子树
//		TreeNode *tmp = que.front();
//		TreeNode *left = NULL, *right = NULL;
//		//定义非空左子树
//		if (nums[i] != flag)
//		{
//			left = new TreeNode(nums[i]);
//			que.push(left);
//		}
//
//		//定义非空右子树
//		if (i + 1 < size && nums[i + 1] != flag)
//		{
//			right = new TreeNode(nums[i + 1]);
//			que.push(right);
//		}
//
//		tmp->left = left;
//		tmp->right = right;
//		//弹出当前处理的节点
//		que.pop();
//	}
//	return root;
//}
//
//int main()
//{
//	Solution s;
//
//	vector<int> v1 = { 8, flag, 9, 3, 2 };
//
//	TreeNode *root1 = generateTree(v1);
//	vector<int> ret = s.PrintFromTopToBottom(root1);
//	for (size_t i = 0; i < ret.size(); ++i)
//		cout << ret[i] << "\t";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}