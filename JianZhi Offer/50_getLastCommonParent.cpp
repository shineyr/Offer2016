/*面试题50 树中两个节点的最低公共祖先*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;






/*（1）情况1，在二叉搜索树中找节点p和q的最低公共祖先*/
/*二叉搜索树节点结构*/
typedef struct BSTNode {
	int val;
	BSTNode *left;
	BSTNode *right;

	BSTNode(int val) :val(val), left(NULL), right(NULL) {}
};

BSTNode *getLastCommonParent1(BSTNode *root, BSTNode *p, BSTNode *q)
{
	if (root == NULL)
		return NULL;

	BSTNode *ret = root;

	while (ret != NULL)
	{
		//如果两个节点p,q的值比根节点ret都大，则最低公共祖先在右子树
		if (ret->val < p->val && ret->val < q->val)
		{
			ret = ret->right;
		}
		//如果两个节点p,q的值比根节点ret都小，则最低公共祖先在左子树
		else if (ret->val > p->val && ret->val > q->val) {
			ret = ret->left;
		}
		//如果ret的值在p和q的中间，则ret即是p和q的最低公共祖先
		else {
			break;
		}
	}//while
	return ret;
}

/*（2）情况2，非二叉搜索树，只是普通的二叉树，树中每个节点包含指向父节点的指针
此时，所给节点p和q均有一条指向跟节点root的链表。该题目即可转换为两个链表的第一个公共节点。
*/
/*含有父节点指针的普通二叉树节点结构*/
typedef struct TPNode {
	int val;
	TPNode *left;
	TPNode *right;
	TPNode *parent;

	TPNode(int val) :val(val), left(NULL), right(NULL), parent(NULL) {}
};

TPNode *getLastCommonParent2(TPNode *root, TPNode *p, TPNode *q)
{
	if (root == NULL)
		return NULL;

	int pLen = 0, qLen = 0;
	TPNode *pTmp = p;
	while (pTmp != NULL)
	{
		++pLen;
		pTmp = pTmp->parent;
	}

	TPNode *qTmp = q;
	while (qTmp != NULL)
	{
		++qLen;
		qTmp = qTmp->parent;
	}

	pTmp = p;
	qTmp = q;
	if (pLen > qLen)
	{
		int diff = pLen - qLen;
		while (diff > 0)
		{
			pTmp = pTmp->parent;
		}//while
	}
	else {
		int diff = qLen - pLen;
		while (diff > 0)
		{
			qTmp = qTmp->parent;
		}
	}//else

	while (pTmp != qTmp)
	{
		pTmp = pTmp->parent;
		qTmp = qTmp->parent;
	}

	return pTmp;
}

/*（3）情况3，非二叉搜索树，只是普通的二叉树，且树中每个节点不包含指向父节点的指针
此时，顺着一条p和q都在同一边的链子，也就是说，如果p和q都在某节点的左边，就到左子树中去
查找公共祖先，如果都在右边就去右子树去查找公共祖先。要是p和q不在同一边，那么就表示已经找到第一个公共祖先。
*/
/*不含父节点指针的普通二叉树节点结构*/
typedef struct BTNode {
	int val;
	BTNode *left;
	BTNode *right;

	BTNode(int val) :val(val), left(NULL), right(NULL) {}
};

bool judge(BTNode *root, BTNode *p)
{
	//判断二叉树root中是否含有节点p
	if (root == NULL)
		return false;
	if (root == p)
		return true;

	return judge(root->left, p) || judge(root->right, p);
}
BTNode *getLastCommonParent3(BTNode *root, BTNode *p, BTNode *q)
{
	if (root == NULL || !judge(root,p) || !judge(root,q))
		return NULL;

	if (root == p || root == q)
		return root;

	/*p和q不在root的同一边，说明root即是它们的最低公共祖先*/
	bool isPOnLeft = judge(root->left, p);
	bool isQOnLeft = judge(root->left, q);

	/*如果p和q都在root的左边*/
	if (isPOnLeft && isQOnLeft)
	{
		return getLastCommonParent3(root->left, p, q);
	}
	//否则如果p和q都在root的右边
	else if(!isPOnLeft && !isQOnLeft){
		return getLastCommonParent3(root->right, p, q);
	}
	//否则，说明p和q不在同一边，此时便找到两者最低公共祖先
	else {
		return root;
	}
}

/*（4）情况4，非二叉树，只是普通的多叉树，且树中每个节点不包含指向父节点的指针
此时，先求得从根节点到p和q的路径，转换为求链表的最后一个公共子节点。
*/

/*含有父节点指针的普通二叉树节点结构*/
typedef struct TreeNode {
	int val;
	TreeNode *left;
	vector<TreeNode *> m_vChildren;

	TreeNode(int val) :val(val), m_vChildren(vector<TreeNode*>()) {}
};

//获取node节点在树root中的路径
bool getNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
{
	if (root == node)
		return true;

	path.push_back(root);
	bool found = false;
	vector<TreeNode *>::iterator iter = root->m_vChildren.begin();
	while (!found && iter < root->m_vChildren.end())
	{
		found = getNodePath(*iter, node, path);
		++iter;
	}//while

	if (!found)
		path.pop_back();

	return found;
}

TreeNode *getLastCommonNode(vector<TreeNode *> pV, vector<TreeNode *> qV)
{
	if (pV.empty() && qV.empty())
		return NULL;
	vector<TreeNode *>::iterator pIter = pV.begin(), qIter = qV.begin();

	TreeNode *ret = NULL;
	while (pIter != pV.end() && qIter != qV.end())
	{
		if (*pIter == *qIter)
			ret = *pIter;
		++pIter;
		++qIter;
	}//while
	return ret;

}

TreeNode *getLastCommonParent4(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == NULL)
		return NULL;

	vector<TreeNode *> pV, qV;
	getNodePath(root, p, pV);
	getNodePath(root, q, qV);

	return getLastCommonNode(pV, qV);
}
