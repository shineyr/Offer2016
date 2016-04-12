/*
2.13 删除无序单链表中值重复出现的节点

题目
给定一个无序单链表的头结点head，删除其中值重复出现的节点。
方法一：如果链表长度为N，时间复杂度为O(N)
方法二：额外空间复杂度为O(1)
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

/*方法一：利用哈希的思想，额外空间复杂度为O(n)*/
ListNode *removeRep1(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	unordered_set<int> us;
	us.insert(head->val);

	ListNode *pre = head,*p = pre->next;
	while (p)
	{
		if (us.find(p->val) != us.end())
		{
			ListNode *tmp = p;
			pre->next = p->next;
			p = p->next;
			delete tmp;
			tmp = NULL;
		}//if
		else
		{
			us.insert(p->val);
			pre = pre->next;
			p = p->next;
		}//else
	}//while

	return head;
}

/*方法二：空间复杂度为O(1)*/
ListNode *removeRep2(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *p = head;
	while (p)
	{
		/*p节点后值为p->val的节点全部删除*/
		ListNode *pre = p,*q = p->next;
		while (pre && q)
		{
			if (q->val == p->val)
			{
				ListNode *tmp = q;
				q = q->next;
				pre->next = q;

				delete tmp;
				tmp = NULL;
			}//if
			else
			{
				pre = pre->next;
				q = q->next;
			}//else
		}//while
		p = p->next;
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

	head = removeRep2(head);
	display(head);

	deleteNodes(head);
	system("pause");
	return 0;
}
