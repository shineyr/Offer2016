/*
给定两个有序链表的头指针head1和head2，打印两个链表的公共部分。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

void printCommonList(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL || head2 == NULL)
		return;

	ListNode *p = head1, *q = head2;
	while (p && q)
	{
		if (p->val < q->val)
		{
			p = p->next;
		}//if
		else if (p->val > q->val)
		{
			q = q->next;
		}//elif
		else{
			cout << p->val << "\t";
			p = p->next;
			q = q->next;
		}//else
	}//while
}

