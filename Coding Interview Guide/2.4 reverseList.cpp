/*
题目：反转链表和双向链表
要求：
	如果链表长度为N，时间复杂度要求为O(N)，空间复杂度要求为O(1)
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

/*反转单向链表*/
ListNode *reverseLinkList(ListNode *head)
{
	/*尾插法*/
	ListNode *p = head;
	head = NULL;

	while (p)
	{
		ListNode *r = p->next;
		if (!head)
		{
			head = p;
			head->next = NULL;
		}//if
		else{
			p->next = head;
			head = p;
		}//else
		p = r;
	}//while
	return head;
}

/*反转双向链表*/
DoubleNode *reverseDoubleList(DoubleNode *head)
{
	DoubleNode *p = head;
	head = NULL;
	while (p)
	{
		DoubleNode *r = p->next;
		if (!head)
		{
			head = p;
			head->prev = NULL;
			head->next = NULL;
		}//if
		else{
			p->next = head;
			head->prev = p;
			p->prev = NULL;
			head = p;
		}//else
		p = r;
	}
	return head;
}

int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = reverseLinkList(head);
	display(head);

	DoubleNode *head2 = NULL;
	for (int i = 0; i < 10; ++i)
		head2 = insert2(head2, i);
	display2(head2);
	head2 = reverseDoubleList(head2);
	display2(head2);
	system("pause");
	return 0;
}