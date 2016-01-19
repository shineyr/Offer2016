/*
题目：删除链表的中间节点和a/b处的节点
给定链表的头节点head，实现删除链表的中间节点的函数；
进阶：
给定链表的头结点head，整数a和b，实现删除位于a/b处节点的函数；
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

/*移除中间节点*/
ListNode *removeMidNode(ListNode *head)
{
	if (!head || !head->next)
		return head;
	else if (!head->next->next)
	{
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}
	else{
		ListNode *pre = head, *cur = head->next->next;
		/*长度每增加2个节点，则要移除的节点后移一位*/
		while (cur->next && cur->next->next)
		{
			pre = pre->next;
			cur = cur->next->next;
		}//while
		ListNode *tmp = pre->next;
		pre->next = pre->next->next;
		delete tmp;
		return head;
	}//else
}

/*移除a/b处节点，（1）求长度；（2）取len * a / b上限；*/
ListNode *removeByRatio(ListNode *head, int a, int b)
{
	if (!head || a <= 0 || a > b)
		return head;

	int len = 0;
	ListNode *p = head;
	while (p)
	{
		++len;
		p = p->next;
	}//while

	/*ceil函数取上限*/
	int idx = (int)ceil((double)(len * a) / (double)b);
	if (idx == 1)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else{
		p = head;
		while (--idx > 1)
		{
			p = p->next;
		}//while
		/*此时p为要删除节点的前驱*/
		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;
	}//else
	return head;
}
int main()
{
	ListNode *head = NULL;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 5);
	head = insert(head, 7);
	head = insert(head, 8);
	display(head);

	head = removeMidNode(head);

	display(head);

	head = removeByRatio(head, 2, 7);

	display(head);

	system("pause");
	return 0;
}