/*
3.4 二叉树的序列化和反序列化 p103
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int strToInt(string str)
{
	if (str.empty())
		return 0;
	int len = str.length(), ret = 0;
	for (int i = 0; i < len; ++i)
	{
		ret = ret*10 + (str[i] - '0');
	}//for

	return ret;
}

string intTostr(int n)
{
	string str = "";
	while (n)
	{
		char c = ((n % 10) + '0');
		str += c;
		n /= 10;
	}//while
	reverse(str.begin(), str.end());
	return str;
}

class Solution {
public:
	/**
	* 先序遍历序列化二叉树
	*/
	string preSerialize(TreeNode *root) {
		// write your code here
		if (root == NULL)
			return "#!";

		/*先序遍历序列化，递归实现*/
		char s[10];
		sprintf(s,"%d",root->val);
		string str = string(s) + "!";
		str += preSerialize(root->left);
		str += preSerialize(root->right);

		return str;
	}

	/**
	* 先序遍历反序列化
	*/
	TreeNode *preDeserialize(string data) {
		// write your code here
		queue<string> vals;

		int beg = 0, i = 0;
		int len = data.length();
		for (; i < len; ++i)
		{
			if (data[i] == '!')
			{
				string str = data.substr(beg, i - beg);
				beg = i + 1;
				vals.push(str);
			}//if
		}//for

		/*保存末尾值*/
		vals.push(data.substr(beg, i - beg));

		return preBuildTree(vals);
	}

	TreeNode *preBuildTree(queue<string> vals)
	{
		string val = vals.front();
		vals.pop();

		if (val == "#")
			return NULL;

		TreeNode *node = new TreeNode(atoi(val.c_str()));
		node->left = preBuildTree(vals);
		node->right = preBuildTree(vals);

		return node;
	}

	/*层序遍历序列化二叉树*/
	string serialize(TreeNode *root)
	{
		if (root == NULL)
			return "";

		string str = intTostr(root->val) + "!";
		
		queue<TreeNode *> nodes;
		nodes.push(root);
		while (!nodes.empty())
		{
			TreeNode *node = nodes.front();
			nodes.pop();

			if (node->left != NULL)
			{
				str = str + intTostr(node->left->val) + "!";
				nodes.push(node->left);
			}
			else {
				str += "#!";
			}//else

			if (node->right != NULL)
			{
				str = str + intTostr(node->right->val) + "!";
				nodes.push(node->right);
			}
			else {
				str += "#!";
			}//else
		}//while

		return str;
	}

	/**
	* 层序遍历反序列化
	*/
	TreeNode *deserialize(string data) {
		// write your code here
		// write your code here
		vector<string> vals;

		int beg = 0, i = 0;
		int len = data.length();
		for (; i < len; ++i)
		{
			if (data[i] == '!')
			{
				string str = data.substr(beg, i - beg);
				beg = i + 1;
				vals.push_back(str);
			}//if
		}//for

		return BFSBuildTree(vals);
	}

	TreeNode *BFSBuildTree(vector<string> vals)
	{
		if (vals.empty())
			return NULL;

		int len = vals.size(), idx = 0;
		string str = vals[idx++];
		TreeNode *root = new TreeNode(strToInt(str));

		queue<TreeNode *> nodes;
		nodes.push(root);
		
		while (!nodes.empty() && idx < len-1)
		{
			TreeNode *node = nodes.front();
			nodes.pop();

			string str = vals[idx++];
			if (str != "#")
			{
				node->left = new TreeNode(strToInt(str));
				nodes.push(node->left);
			}

			str = vals[idx++];
			if (str != "#")
			{
				node->right = new TreeNode(strToInt(str));
				nodes.push(node->right);
			}//if
		}//while

		return root;
	}
};


int main()
{
	Solution s;
	string str = "3!9!20!#!#!15!7!";
	TreeNode *root = s.deserialize(str);

	string ret = s.serialize(root);

	cout << ret << endl;

	getchar();

	return 0;
}