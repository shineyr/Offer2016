/*
题目：将单链表按某值划分成左边小、中间相等右边大的形式

给定一个单向链表的头节点head，以及一个整数pivot。实现一个调整链表的函数，
将链表调整为左部分都是小于pivot的节点，中间部分都是值等于pivot的节点，
右部分都是值大于pivot的节点。

进阶：
保持左中右三个部分内部节点的相对顺序不变；
*/

#include <iostream>
#include <cstdlib>
#include <vector>

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


/*交换下标a、b处的节点*/
void swap(vector<ListNode *> &nodes, int a, int b)
{
	ListNode *tmp = nodes[a];
	nodes[a] = nodes[b];
	nodes[b] = tmp;
}

/*对节点集合根据pivot进行划分排序*/
void sortPartition(vector<ListNode *> &nodes, int pivot)
{
	if (nodes.empty())
		return;

	int small = -1, big = nodes.size(), idx = 0;
	while (idx != big)
	{
		if (nodes[idx]->val < pivot)
			swap(nodes, ++small, idx++);
		else if (nodes[idx]->val == pivot)
			++idx;
		else
			swap(nodes, --big, idx);
	}//while
}
/*普通要求：解法1，借助辅助结构*/
ListNode *listPartition1(ListNode *head, int pivot)
{
	if (!head)
		return head;
	/*将所有节点存储到vector中*/
	vector<ListNode*> nodes;
	ListNode *p = head;
	while (p)
	{
		nodes.push_back(p);
		p = p->next;
	}//while

	sortPartition(nodes, pivot);

	/*重新链接所有节点*/
	for (int i = 1; i != nodes.size();++i)
	{
		nodes[i - 1]->next = nodes[i];
	}//for
	nodes[nodes.size() - 1]->next = NULL;

	return nodes[0];
}

/*进阶要求：对所有节点依次划分进三个链表，small equal big*/
ListNode *listPartition2(ListNode *head, int pivot)
{
	if (!head)
		return head;

	ListNode *sH = NULL, *sT = NULL;
	ListNode *eH = NULL, *eT = NULL;
	ListNode *bH = NULL, *bT = NULL;

	ListNode *p = head, *r = NULL;
	while (p)
	{
		/*保存下一个节点*/
		r = p->next;
		if (p->val < pivot)
		{
			if (sH == NULL)
			{
				sH = p;
				sT = sH;
				sT->next = NULL;			
			}//if
			else
			{
				sT->next = p;
				sT = p;
				sT->next = NULL;
			}//else
		}//if
		else if (p->val == pivot)
		{
			if (eH == NULL)
			{
				eH = p;
				eT = eH;
				eT->next = NULL;			
			}//if
			else{
				eT->next = p;
				eT = p;
				eT->next = NULL;
			}//else
		}//elif
		else{
			if (bH == NULL)
			{
				bH = p;
				bT = bH;
				bT->next = NULL;
			}//if
			else{
				bT->next = p;
				bT = p;
				bT->next = NULL;
			}//else
		}//else
		p = r;
	}//while

	/*链接三个链表*/
	if (sT)
	{
		sT->next = eH;
		eT = eT == NULL ? sT : eT;
	}//if
	if (eT)
	{
		eT->next = bH;
	}//if

	return sH != NULL ? sH : eH != NULL ? eH : bH;
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
	head = listPartition1(head, 4);
	display(head);

	head = insert(head, 9);
	head = insert(head, 0);
	head = insert(head, 4);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 1);

	display(head);
	head = listPartition2(head, 4);
	display(head);

	system("pause");
	return 0;
}