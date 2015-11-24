/*
 * 面试题58：二叉树的下一个结点
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */

#include <iostream>
#include <cstdlib>

using namespace std;

using namespace std;
/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};
*/

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;

	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
			return NULL;

		// 1）如果pNode包含右子树，则右子树中的最左结点为其中序遍历的下一个结点
		if (pNode->right != NULL)
		{
			TreeLinkNode *node = pNode->right;
			while (node->left)
			{
				node = node->left;
			}//while
			return node;
		}
		// 2）没有右子树，且父节点不为空
		else if (pNode->right == NULL && pNode->next != NULL)
		{
			// 3）当前节点为其父节点的左子树,则其父节点便是中序遍历的下一个节点
			if (pNode == pNode->next->left)
			{
				return pNode->next;
			}
			else{
				TreeLinkNode *pCurrent = pNode, *pParent = pNode->next;
				while (pParent != NULL && pCurrent == pParent->right)
				{
					pCurrent = pParent;
					pParent = pParent->next;
				}//while
				
				return pParent;
			}

		}
		//父节点为空，且没有右子树
		else{
			return NULL;
		}
	}
};

