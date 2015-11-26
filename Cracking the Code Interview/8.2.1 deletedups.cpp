/*
 * 8.2.1 编写代码，删除未排序链表中的重复节点
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

class Solution{
public:
	void deleteDups(ListNode *head)
	{
		if (!head)
			return;

		unordered_set<int> us;
		//注意保存前驱节点
		ListNode *p = head , *pre = head;
		while (p)
		{
			if (us.count(p->val) < 1)
			{
				us.insert(p->val);
				pre = p;
			}
			else{
				pre->next = p->next;
			}//else
			p = p->next;
		}//while			
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
	s.deleteDups(head);

	display(head);

	system("pause");
	return 0;

}