/*
约瑟夫环问题：
输入：一个环形链表的头结点head和报数的数值m
返回：最后生存下来的节点，且这个节点自己组成环形单向链表，其它节点都删掉。

进阶：
如果链表节点数为N，想在时间复杂度为O(N)时间完成原问题的要求，如何实现？
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
	{
		head = new ListNode(val);
		head->next = head;
	}
	else{
		ListNode *p = head;
		while (p->next != head)
			p = p->next;
		p->next = new ListNode(val);
		p->next->next = head;
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next != head)
		{
			cout << p->val << "—>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

ListNode *josephCircle(ListNode *head, int m)
{
	if (!head || !head->next || m < 1)
		return head;
	ListNode *last = head;
	/*寻找链表尾节点*/
	while (last->next != head)
		last = last->next;

	/*计数变量*/
	int count = 0;
	while (head != last)
	{
		if (++count == m)
		{
			last->next = head->next;
			count = 0;
		}
		else{
			last = last->next;
		}//else
		head = last->next;
	}//while
	return head;
}

/*求最后存活的节点编号*/
int getLive(int i, int m)
{
	if (i == 1)
		return 1;
	return (getLive(i - 1, m) + m - 1) % i + 1;
}
/*约瑟夫环进阶问题*/
ListNode *josephCircle2(ListNode *head, int m)
{
	if (!head || !head->next || m < 1)
		return head;
	ListNode *node = head->next;
	int len = 1;
	while (node != head)
	{
		++len;
		node = node->next;
	}//while

	int lastLive = getLive(len, m);
	while (--lastLive != 0)
		head = head->next;
	head->next = head;
	return head;
}


int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = josephCircle(head, 3);
	display(head);

	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = josephCircle2(head, 3);
	display(head);

	system("pause");
	return 0;
}