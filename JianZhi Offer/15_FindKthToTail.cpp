/* 
 * 题目：链表中倒数第k个结点
 * 输入一个链表，输出该链表中倒数第k个结点。
 */

#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead || k <= 0)
			return NULL;

		int len = 0;
		ListNode *p = pListHead;
		while (p)
		{
			++len;
			p = p->next;
		}//while

		if (k > len)
			return NULL;

		//求正序编号
		k = len - k + 1;
		p = pListHead;
		int i = 1;
		while (p && i < k)
		{
			p = p->next;
			++i;
		}
		return p;
	}
};

ListNode *insert(ListNode *head, int val)
{
	if (head == NULL)
	{
		head = new ListNode(val);
		return head;
	}

	ListNode *p = head;
	while (p && p->next)
	{
		p = p->next;
	}

	ListNode *q = new ListNode(val);
	p->next = q;

	return head;
}

int main()
{
	ListNode *head = NULL;

	for (int i = 0; i < 5; ++i)
		head = insert(head, i);

	Solution s;
	ListNode *r = s.FindKthToTail(head , 2);

	

	system("pause");
	return 0;
}