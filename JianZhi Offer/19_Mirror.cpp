/*
 * 面试题20 ： 二叉树的镜像
 * 题目描述
 * 操作给定的二叉树，将其变换为源二叉树的镜像。 
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
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		//空树或者单根树，直接返回
		if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
			return;

		TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;

		if (pRoot->left)
			Mirror(pRoot->left);

		if (pRoot->right)
			Mirror(pRoot->right);
	}
};

//int main()
//{
//
//}