/*
两个链表相交的一系列问题
在本题中，单链表可能有环，也可能无环。给定两个单链表的头结点head1和head2，这两个链表
可能相交，也可能不相交。实现一个函数，如果两个链表相交，请返回相交的第一个节点，如果
不相交，返回null即可。
要求：
如果链表1的长度为N，链表2的长度为M，则时间复杂度请达到O(N+M)，空间复杂度请达到O(1)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
	int value;
	Node *next;

	Node(int val) :value(val), next(NULL){}
};

/*查找单链表的入环节点，若无则返回NULL*/
Node *getLoopNode(Node *head)
{
	if (!head || head->next == NULL || head->next->next == NULL)
		return NULL;

	Node *slow = head->next;
	Node *fast = head->next->next;

	while (slow != fast)
	{
		if (fast->next == NULL || fast->next->next == NULL)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
	}//while

	/*slow与fast相交，此时将fast重新指向head节点*/
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}//while
	return slow;
}

/*查找无环链表的相交节点，无交点则返回NULL*/
Node *getNoLoopIntersectNode(Node *head1, Node *head2)
{
	if (!head1 || !head2)
		return NULL;

	Node *p = head1, *q = head2;
	int len1 = 0, len2 = 0, len = 0;

	while (p)
	{
		++len1;
		p = p->next;
	}//while

	while (q)
	{
		++len2;
		q = q->next;
	}//while

	/*链表1长度大于链表2*/
	if (len1 > len2)
	{
		p = head1;
		q = head2;
		len = len1 - len2;
	}
	else{
		p = head2;
		q = head1;
		len = len2 - len1;
	}//else

	while (len > 0)
	{
		p = p->next;
		--len;
	}//while

	while (p != q)
	{
		p = p->next;
		q = q->next;
	}//while
	return p;
}

/*查找两个有环链表的相交节点*/
Node *getLoopIntersectNode(Node *head1, Node *loop1, Node *head2, Node *loop2)
{
	Node *cur1 = NULL, *cur2 = NULL;
	if (loop1 == loop2)
	{
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1 != loop1)
		{
			++n;
			cur1 = cur1->next;
		}//while

		while (cur2 != loop2)
		{
			--n;
			cur2 = cur2->next;
		}//while

		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;

		n = n > 0 ? n : -n;
		while (n > 0)
		{
			cur1 = cur1->next;
			--n;
		}//while
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}//while
		return cur1;
	}//if
	else{
		cur1 = loop1->next;
		while (cur1 != loop1)
		{
			if (cur1 == loop2)
			{
				return loop1;
			}//if
			cur1 = cur1->next;
		}//while
		return NULL;
	}
}

/*查找交叉节点主函数*/
Node *getIntersectNode(Node *head1, Node *head2)
{
	/*两个空链表相交节点为空*/
	if (!head1 && !head2)
		return NULL;

	Node *loop1 = getLoopNode(head1);
	Node *loop2 = getLoopNode(head2);

	if (loop1 == NULL && loop2 == NULL)
		return getNoLoopIntersectNode(head1, head2);
	else if (loop1 != NULL && loop2 != NULL)
		return getLoopIntersectNode(head1, loop1, head2, loop2);
	else
		return NULL;
}

int main()
{

}