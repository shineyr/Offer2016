/*
 * 题目: 从尾到头打印链表
 * 描述:
 * 输入一个链表，从尾到头打印链表每个节点的值。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		if (head == NULL)
			return vector<int>();

		vector<int> ret;
		ListNode *p = head;
		while (p)
		{
			ret.push_back(p->val);
			p = p->next;
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};

ListNode *insert(ListNode *head, int val)
{
	if (head == NULL)
	{
		head = new ListNode(val);
		return head;
	}

	ListNode *p = head;
	while (p && p->next)
	{
		p = p->next;
	}

	ListNode *q = new ListNode(val);
	p->next = q;

	return head;
}

//int main()
//{
//	ListNode *head = NULL;
//
//	for (int i = 0; i < 5; ++i)
//		head = insert(head, i);
//
//	Solution s;
//	vector<int> ret = s.printListFromTailToHead(head);
//
//	system("pause");
//	return 0;
//}