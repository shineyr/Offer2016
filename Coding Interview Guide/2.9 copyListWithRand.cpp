/*
复制含随机指针节点的链表
一个特殊的链表节点类描述：
struct ListNode{
	int val;
	ListNode *next;
	ListNode *rand;
	ListNode(int v):val(v),next(NULL),rand(NULL){}
其中rand指针可能指向链表中的任意节点，也可能指向null

给定一个由ListNode节点类型组成的无环单链表的头节点head，实现函数完成整个
链表中所有结构的复制，并返回复制的新链表的头节点。

进阶：不适用额外的数据结构，只有有限几个变量，且在时间复杂度为O(N)内完成原问题；
*/

#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode *rand;
	ListNode(int v) :val(v), next(NULL), rand(NULL){}
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

/*方法一：借助map辅助数据结构*/
ListNode *copyListWithRand1(ListNode *head)
{
	if (!head)
		return head;

	map<ListNode *, ListNode*> nodeMap;
	ListNode *p = head;
	while (p)
	{
		nodeMap[p] = new ListNode(p->val);
		p = p->next;
	}//while

	/*设置连接关系*/
	for (auto iter = nodeMap.begin(); iter != nodeMap.end(); ++iter)
	{
		iter->second->next = nodeMap[iter->first->next];
		
		iter->second->rand = iter->first->rand ? nodeMap[iter->first->rand] : NULL;
	}//for
	return nodeMap[head];
}

/*方法二：不借助数据结构*/
ListNode *copyListWithRand2(ListNode *head)
{
	if (!head)
		return head;
	ListNode *p = head;
	while (p)
	{
		ListNode *r = p->next;
		ListNode *node = new ListNode(p->val);
		/*将复制链表插入当前访问节点和其后继节点之间*/
		node->next = r;
		p->next = node;

		p = r;
	}//while

	p = head;
	ListNode *q = head->next, *rHead = q;
	while (p && q)
	{
		/*保存下一个元链表节点*/
		ListNode *rp = q->next;
		/*保存下一个复制节点*/
		ListNode *rq = rp ? rp->next : NULL;
		
		q->next = rq;
		if (p->rand)
			q->rand = p->rand->next;
		else
			q->rand = NULL;
		p->next = rp;

		p = rp;
		q = rq;
	}//while
	return rHead;
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 9);
	head = insert(head, 0);
	head = insert(head, 4);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 1);

	display(head);

	ListNode *rHead = copyListWithRand1(head);
	display(rHead);

	ListNode *rHead2 = copyListWithRand2(head);
	display(rHead2);

	system("pause");
	return 0;
}