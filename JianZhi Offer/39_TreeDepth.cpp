/*
 * 面试题39 求二叉树的深度
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot)
			return 0;
		int dLeft = TreeDepth(pRoot->left);
		int dRight = TreeDepth(pRoot->right);
		return (dLeft > dRight) ? (dLeft + 1) : (dRight + 1);
	}
};