/*
题目：分别实现两个函数，一个可以删除单链表中倒数第k个节点，另一个可以删除
双链表中倒数第k个节点；

要求：如果链表长度为N，时间复杂度达到O(N)，额外空间复杂度达到O(1)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}
};

struct DoubleNode{
	int val;
	DoubleNode *prev, *next;
	DoubleNode(int v) :val(v), prev(NULL), next(NULL){}
};

ListNode *insert(ListNode *head, int val)
{
	if (!head)
		head = new ListNode(val);
	else{
		ListNode *p = head;
		while (p->next)
			p = p->next;
		p->next = new ListNode(val);
	}//else
	return head;
}

DoubleNode *insert2(DoubleNode *head, int val)
{
	if (!head)
		head = new DoubleNode(val);
	else{
		DoubleNode *p = head;
		while (p->next)
			p = p->next;
		DoubleNode *node = new DoubleNode(val);
		node->prev = p;
		p->next = node;
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next)
		{
			cout << p->val << "—>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

void display2(DoubleNode *head)
{
	if (!head)
		cout << endl;
	else{
		DoubleNode *p = head;
		while (p->next)
		{
			cout << p->val << "<—>";
			p = p->next;
		}//while
		cout << p->val << endl;
		
	}//else
}
ListNode *removeLastKthNode(ListNode *head, int k)
{
	if (!head || k < 1)
		return head;

	ListNode *p = head;
	while (p)
	{
		--k;
		p = p->next;
	}//while

	/*此时 k 的值变为N-K*/
	if (k == 0)
	{
		p = head;
		head = head->next;
		delete p;
	}//if
	else if(k < 0){
		p = head;
		while (++k != 0)
			p = p->next;
		ListNode *q = p->next;
		p->next = p->next->next;
		delete q;
	}//else
	return head;	
}

DoubleNode *removeLastKthNode2(DoubleNode *head, int k)
{
	if (!head || k < 1)
		return head;
	DoubleNode *p = head;
	while (p)
	{
		--k;
		p = p->next;
	}//while

	if (k == 0)
	{
		p = head;
		head->next->prev = NULL;
		head = head->next;
		delete p;
	}
	else if (k < 0)
	{
		p = head;
		while (++k != 0)
			p = p->next;
		DoubleNode *q = p->next;
		q->next->prev = p;
		p->next = q->next;

		delete q;
	}//else
	return head;
}
int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = removeLastKthNode(head, 5);
	display(head);

	DoubleNode *head2 = NULL;
	for (int i = 0; i < 10; ++i)
		head2 = insert2(head2, i);
	display2(head2);
	head2 = removeLastKthNode2(head2, 5);
	display2(head2);
	system("pause");
	return 0;
}