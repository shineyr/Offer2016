/*
2.14 在单链表中删除指定值的节点

题目
给定一个链表的头节点head和一个整数num，请实现函数将值为num的节点全部删除。
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

ListNode *removeValueNode(ListNode *head, int val)
{
	if (head == NULL)
		return head;

	while (head && head->val == val)
	{
		ListNode *tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;
	}//while

	ListNode *pre = head;
	while (pre && pre->next)
	{
		ListNode *p = pre->next;
		if (p && p->val == val)
		{
			ListNode *tmp = p;
			p = p->next;
			pre->next = p;

			delete tmp;
			tmp = NULL;
		}//if
		else{
			pre = pre->next;
			p = p->next;
		}//else
	}//while

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
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 4);
	head = insert(head, 2);
	head = insert(head, 1);

	display(head);

	head = removeValueNode(head, 1);
	display(head);

	deleteNodes(head);
	system("pause");
	return 0;
}
