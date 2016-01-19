/*
题目：反转部分单向链表
要求：
	给定一个单向链表的头结点head，以及两个整数from和to，在单向链表上把第from
	个节点到第to个节点这一部分进行反转
	如：
	1->2->3->4->5->null  from = 2, to = 4 反转后
	1->4->3->2->5->null
	再如：
	1->2->3->null  from = 1, to = 3 反转后
	3->2->1->null
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}
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


/*反转部分单向链表*/
ListNode *reversePartList(ListNode *head, int from , int to)
{
	if (!head || from < 1 || from >= to)
		return head;
	ListNode *pre = head, *p = head, *tmpHead = NULL, *tmpEnd = NULL;
	int idx = 1;
	while (idx < from)
	{
		pre = p;
		p = p->next;
		++idx;
	}//while


	if (idx == 1)
	{
		head = NULL;
	}//if
	else{
		while (idx <= to && p)
		{
			ListNode *r = p->next;
			if (!head)
			{
				head = p;
				head->next = NULL;				
			}//if
			else if (idx == from)
			{
				/*反转部分的头和尾*/
				tmpHead = p;
				tmpEnd = p;
				tmpHead->next = NULL;
			}
			else{
				p->next = tmpHead;		
				tmpHead = p;
				pre->next = tmpHead;
			}//else
			p = r;
			++idx;
		}//while
	}//else
	tmpEnd->next = p;
	return head;
}


int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = reversePartList(head, 2, 4);
	display(head);

	
	system("pause");
	return 0;
}