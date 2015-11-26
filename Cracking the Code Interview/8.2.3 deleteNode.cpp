/*
 * 面试题8.2.3 删除单链表中的某个节点，假定只能访问该节点。
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	/* 在这个问题中，无法访问链表的首节点，只能访问那个待删除的节点。解法很简单，直接将后继节点的数据复制到
	 * 当前节点，然后删除这个后继节点；但是需要注意的是，如果待删除的节点为链表的尾节点，这个题目无解。
	 * 我们只需要向面试官指明这一点即可。
	 */
	bool deleteNode(ListNode *node)
	{
		if (!node || !node->next)
			return false;

		int tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;

		ListNode *p = node->next;
		node->next = node->next->next;

		delete p;
		p = NULL;
		return true;
	}
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
		cout << head->val ;
	}
	ListNode *p = head->next;
	while (p)
	{
		cout << "—>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 1);
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 3);
	display(head);

	Solution s;
	s.deleteNode(head);

	display(head);

	system("pause");
	return 0;

}