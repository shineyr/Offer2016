/*
面试题13 在O(1)的时间删除链表节点
题目：给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间删除该节点。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}

	bool operator==(ListNode *node)
	{
		return this->val == node->val;
	}

	bool operator!=(ListNode *node)
	{
		return !(this == node);
	}
};

void deleteNode(ListNode **head, ListNode *node)
{
	if (!head || !node)
		return ;
	/*若要删除的目的节点不是尾节点*/
	else if (node->next != NULL)
	{
		ListNode *tmp = node->next;
		node->val = node->next->val;

		node->next = node->next->next;
		delete tmp;
		tmp = NULL;
	}//elif
	/*若要删除尾节点且链表中只有一个节点*/
	else if (*head == node)
	{
		delete *head;
		*head = NULL;
	}
	/*删除单纯的尾节点，首先顺序遍历，找到尾节点的前驱*/
	else{
		ListNode *p = *head;
		while (p->next != node)
		{
			p = p->next;
		}//while

		p->next = NULL;
		delete node;
		node = NULL;
	}//else
}

void insert(ListNode **head, ListNode *node)
{
	if (node == NULL)
		return;
	else if (head == NULL || (*head) == NULL)
	{
		*head = node;
		return;
	}//elif
	else{
		ListNode *p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}//else
}

void display(ListNode *head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = NULL;
	
	ListNode *p = new ListNode(2);
	insert(&head, p);

	ListNode *q = new ListNode(3);
	insert(&head, q);

	ListNode *r = new ListNode(4);
	insert(&head, r);


	display(head);

	deleteNode(&head,q);

	display(head);

	/*此时r指针已被删除掉，其值赋给了q*/
	deleteNode(&head,q);

	display(head);

	deleteNode(&head, p);

	display(head);

	system("pause");
	return 0;

}