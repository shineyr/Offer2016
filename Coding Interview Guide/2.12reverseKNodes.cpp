/*
2.12 将链表的每k个节点之间逆序
题目：给定一个单链表的头节点，实现一个调整单链表的函数，使得每k个节点之间逆序。
如果最后不够K个节点一组，则不调整最后几个节点。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

/*方法一，借助辅助空间结构栈*/
ListNode *reverseKNodes(ListNode *head, int k)
{
	if (k < 2)
		return head;

	stack<ListNode *> ls;
	ListNode *p = head;
	ListNode *newHead = NULL, *newNext = newHead;
	int count = 0;
	while (p)
	{
		ListNode *r = p->next;
		ls.push(p);
		++count;

		if (count == k)
		{
			while (!ls.empty())
			{
				ListNode *tmp = ls.top();
				ls.pop();
				if (newHead == NULL)
				{
					newHead = tmp;
					newNext = newHead;
				}//if
				else
				{
					newNext->next = tmp;
					newNext = tmp;
				}//else
			}//while
			/*暂时链接到后继*/
			count = 0;
			newNext->next = r;
		}//if

		p = r;
	}//while

	return newHead;
}

ListNode *insert(ListNode *head, int x)
{
	ListNode *node = new ListNode(x);
	if (head == NULL)
	{
		head = node;
	}//if
	else{
		ListNode *p = head;
		while (p->next)
			p = p->next;
		p->next = node;
	}//else
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
int main()
{
	ListNode *head = NULL;
	for (int i = 1; i <= 8; ++i)
		head = insert(head, i);

	display(head);

	head = reverseKNodes(head, 3);
	display(head);

	system("pause");
	return 0;
}