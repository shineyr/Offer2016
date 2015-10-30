/*
* 题目：合并两个排序的链表
* 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1)
			return pHead2;
		else if (!pHead2)
			return pHead1;

		ListNode *rHead = NULL , *r = rHead, *p = pHead1, *q = pHead2;
		if (pHead1->val < pHead2->val)
		{
			rHead = pHead1;
			p = pHead1->next;
		}
		else{
			rHead = pHead2;
			q = pHead2->next;
		}//else
		r = rHead;
		while (p && q)
		{
			if (p->val <= q->val)
			{
				r->next = p;
				r = r->next;
				p = p->next;
			}
			else{
				r->next = q;
				r = r->next;
				q = q->next;
			}//else
		}//while

		while (p)
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}

		while (q)
		{
			r->next = q;
			r = r->next;
			q = q->next;
		}

		return rHead;
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
//	ListNode *head1 = NULL , *head2 = NULL;
//
//	for (int i = 1; i < 5; ++i)
//	{
//		head1 = insert(head1, i);
//		head2 = insert(head2, i + 1);
//	}//for
//
//	Solution s;
//	ListNode *head = s.Merge(head1 , head2);
//
//
//
//	system("pause");
//	return 0;
//}