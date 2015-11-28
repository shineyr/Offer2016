/*
 * 面试题8.2.6 给定一个有环链表，实现一个算法返回环路的开头结点
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
	//方法一：借助辅助结构，保存未出现
	ListNode *findBegginning(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		unordered_set<int> us;

		ListNode *p = head;
		while (true)
		{
			if (p->next)
			{
				unordered_set<int>::iterator iter = us.find(p->next->val);
				if (iter != us.end())
				{
					ListNode *q = head;
					while (q->val != *iter)
					{
						q = q->next;
					}//while
					return q;
				}
				else{
					us.insert(p->val);
					p = p->next;
				}
			}
			else{
				return NULL;
			}//else
		}//while
	}

	//方法二：快慢指针实现
	/*
	 * (1) 创建两个指针：FastPointer 和 SlowPointer
	 * (2) 慢行指针每走一步，快行指针便走两步；
	 * (3) 两者碰在一起时，改变慢行指针的指向，SlowPointer指向head，快行指针FastPointer不变；
	 * (4) 以相同速度移动SlowPointer和FastPointer，一次一步，然后返回新的碰撞处。
	 */
	ListNode *findBegginning2(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		/*找出碰撞处*/
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;

			/*碰撞*/
			if (slow == fast)
			{
				break;
			}//if
		}//while

		/*错误检查*/
		if (fast == NULL || fast->next == NULL)
		{
			return NULL;
		}//if

		/*改变slow指针*/
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}//while

		/*此时，两者均指向环路起始处*/
		return fast;
	}
};

int main()
{
	ListNode *head = NULL;

	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 3);

	display(head);

	Solution s;
	ListNode *node = s.findBegginning(head);
	if (node)
		cout << node->val << endl;

	system("pause");
	return 0;
}