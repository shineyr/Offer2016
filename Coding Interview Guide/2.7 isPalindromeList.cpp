/*
判断一个链表是否为回文结构；
进阶：
如果链表长度为N，时间复杂度为O(N),额外空间复杂度达到O(1)
*/


#include <iostream>
#include <cstdlib>
#include <stack>
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

/*采用辅助栈存储链表所有节点*/
bool isPalindrom1(ListNode *head)
{
	if (!head)
		return false;
	stack<int> stk;
	ListNode *p = head;
	while (p)
	{
		stk.push(p->val);
		p = p->next;
	}//while

	p = head;
	while (!stk.empty() && p)
	{
		if (stk.top() != p->val)
			return false;
		stk.pop();
		p = p->next;
	}//while
	return true;
}

/*方法二：采用辅助栈存储链表的右半部分*/
bool isPalindrom2(ListNode *head)
{
	if (!head)
		return true;
	stack<int> stk;

	ListNode *slow = head->next, *fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}//while
	
	/*此时fast指向右半部分第一个节点*/
	while (fast)
	{
		stk.push(fast->val);
		fast = fast->next;
	}//while

	slow = head;
	while (!stk.empty())
	{
		if (stk.top() != slow->val)
			return false;
	}//while
	return true;
}

/*方法三：不借助辅助结构，对链表本身右半部分反转，然后比较*/
bool isPalindrom3(ListNode *head)
{
	if (!head)
		return false;
	ListNode *n1 = head, *n2 = head;
	while (n2->next &&n2->next->next)
	{
		n1 = n1->next;
		n2 = n2->next;
	}//while
	n2 = n1->next; /*此时q指向右半部分第一个节点*/
	/*左半部分链空*/
	n1->next = NULL;
	ListNode *n3 = NULL;
	while (n2)
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}//while
	n3 = n1;
	n2 = head;
	bool ret = true;
	while (n1 &&n2)
	{
		if (n1->val != n2->val)
		{
			ret = false;
			break;
		}//if
		n1 = n1->next;
		n2 = n2->next;
	}//while

	n1 = n3->next;
	n3->next = NULL;
	while (n1)
	{
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}//while
	return ret;
}