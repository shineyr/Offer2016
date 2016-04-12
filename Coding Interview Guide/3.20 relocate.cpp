/*
2.20 按照左右半区的方式重新组合链表
题目
给定一个单链表的头部节点head，链表长度为N，如果N为偶数，那么前N/2个节点算作左半区，
后N/2个节点算作右半区；如果N为奇数，那么前N/2个节点算作左半区，后N/2+1个节点算作右半区；
左半区从左到右依次是L1->L2->...右半区从左到右依次是R1->R2->R3->...，请将链表调整为
L1->R1->L2->R2->...的形式。
*/

#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

ListNode *relocate(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	/*利用快慢指针，找到前半部分的尾，后半部分的头*/
	ListNode *lEnd = head, *rHead = head->next;
	while (rHead->next && rHead->next->next)
	{
		lEnd = lEnd->next;
		rHead = rHead->next->next;
	}//while

	/*右半区的头结点*/
	rHead = lEnd->next;
	/*左半区的尾节点*/
	lEnd->next = NULL;
	

	/*合并*/
	ListNode *lp = head, *rp = rHead, *rNext=NULL;
	while (lp->next)
	{
		rNext = rp->next;
		rp->next = lp->next;
		lp->next = rp;

		lp = rp->next;
		rp = rNext;
	}//while
	lp->next = rNext;

	return head;
}

ListNode *insert(ListNode *head, int val)
{
	ListNode *node = new ListNode(val);
	if (head == NULL)
	{
		head = node;
		return head;
	}//if

	ListNode *p = head;
	while (p->next)
		p = p->next;
	p->next = node;
	return head;
}

void display(ListNode *head)
{
	if (head == NULL)
		return;

	cout << head->val;
	ListNode *p = head->next;
	while (p)
	{
		cout << "—>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

void deleteNodes(ListNode *head)
{
	if (head == NULL)
		return;

	while (head)
	{
		ListNode *p = head;
		head = head->next;
		delete p;
		p = NULL;
	}//while
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);

	display(head);

	head = relocate(head);
	display(head);

	deleteNodes(head);
	system("pause");
	return 0;
}