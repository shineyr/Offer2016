/*
 * 面试题8.2.5 给定两个用链表表示的整数，每个节点包含一个数位。这些数位是反向存放的，也就是个位排在链表首部；
 * 编写函数对这两个链表表示的整数求和，并用链表形式返回结果。
 * 
 * 进阶：当数位正向存放时，重新实现一遍。
 */

#include <iostream>
#include <cstdlib>

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
	/* 数位是反向存放,链表相加实现！*/
	ListNode *addLists(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL)
			return head2;
		else if (head2 == NULL)
			return head1;

		int carry = 0;
		
		ListNode *p = head1, *q = head2, *head = NULL;
		while (p && q)
		{
			int tmp1 = p->val, tmp2 = q->val;
			int sum = tmp1 + tmp2 + carry;
			carry = sum / 10;
			int tmp = sum % 10;
			
			head = insert(head, tmp);

			p = p->next;
			q = q->next;
		}//while

		while (p)
		{		
			int sum = p->val + carry;
			carry = sum / 10;
			int tmp = sum % 10;

			head = insert(head, tmp);

			p = p->next;
		}//while

		while (q)
		{
			int sum = q->val + carry;
			carry = sum / 10;
			int tmp = sum % 10;

			head = insert(head, tmp);

			q = q->next;
		}//while

		if (carry)
			insert(head, carry);
		return head;
	}
};

int main()
{
	ListNode *head1 = NULL, *head2 = NULL, *head = NULL;

	head1 = insert(head1, 7);
	head1 = insert(head1, 1);
	head1 = insert(head1, 6);

	display(head1);
	head2 = insert(head2, 5);
	head2 = insert(head2, 9);
	head2 = insert(head2, 2);

	display(head2);

	Solution s;
	head = s.addLists(head1, head2);

	display(head);

	system("pause");
	return 0;
}