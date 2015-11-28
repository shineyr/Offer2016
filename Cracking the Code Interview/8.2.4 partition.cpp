/*
 * 面试题8.2.4 编写代码，以给定值x为基准将链表分割成两部分，
 * 所有小于x的节点排在大于等于x的节点之前。
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

//尾插法
ListNode *insert(ListNode *head, int val)
{
	ListNode *node = new ListNode(val);

	if (head == NULL)
	{
		head = node;
		return head;
	}
	else{
		ListNode *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}//while
		p->next = node;
	}
	return head;
}

void display(ListNode *head)
{
	if (head)
	{
		cout << head->val;
	}
	ListNode *p = head->next;
	while (p)
	{
		cout << "—>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

class Solution{
public:
	/*方法一：建立两个链表，一个链表存放小于x的元素，另一个存放大于x的元素。迭代访问，分离x两端元素！*/
	ListNode *partition(ListNode *node, int x)
	{
		ListNode *lessHead = NULL, *bigHead = NULL;
		ListNode *lessEnd = NULL, *bigEnd = NULL;

		while (node)
		{
			//保存后续节点
			ListNode *rear = node->next;
			node->next = NULL;

			if (node->val < x)
			{
				if (lessHead == NULL)
				{
					lessHead = node;
					lessEnd = lessHead;
				}//if
				else{
					lessEnd->next = node;
					lessEnd = node;
				}//else
			}//if
			else{
				if (bigHead == NULL)
				{
					bigHead = node;
					bigEnd = bigHead;
				}//if
				else{
					bigEnd->next = node;
					bigEnd = node;
				}//else
			}//else
			node = rear;
		}//while

		if (lessHead == NULL)
			return bigHead;

		/*合并*/
		lessEnd->next = bigHead;
		return lessHead;
	}

	/*方法二，同样建立两个链表，但是采用头插法处理原始链表节点元素*/
	ListNode *partition2(ListNode *node, int x)
	{
		ListNode *lessHead = NULL, *bigHead = NULL;
		while (node)
		{
			ListNode *rear = node->next;

			if (node->val < x)
			{
				node->next = lessHead;
				lessHead = node;
			}
			else{
				node->next = bigHead;
				bigHead = node;
			}//else
			node = rear;
		}//while

		if (lessHead == NULL)
			return bigHead;

		/*定位到lessHead的尾部，合并两个链表*/
		ListNode *p = lessHead;
		while (p->next)
		{
			p = p->next;
		}//while
		p->next = bigHead;

		return lessHead;
	}

};

int main()
{
	ListNode *head = NULL;	
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 3);
	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);

	display(head);

	Solution s;
	head = s.partition2(head, 4);
	display(head);
	

	system("pause");
	return 0;
}