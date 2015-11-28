/*
 * 面试题8.2.7 编写一个函数，检查链表是否为回文。
 */


#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
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
	//方法一：借助辅助数组保存元素，直接判断数组是否为回文序列
	bool isPalindrome1(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		vector<int> v;
		ListNode *p = head;
		while (p)
		{
			v.push_back(p->val);
			p = p->next;
		}//while

		int lhs = 0, rhs = v.size() - 1;
		while (lhs < rhs)
		{
			if (v[lhs++] != v[rhs--])
				return false;
		}//while

		return true;
	}

	//方法二：反转原始链表，对比新链表与原始链表是否相同
	bool isPalindrome2(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		ListNode *rHead = NULL;
		ListNode *p = head;
		while (p)
		{
			ListNode *node = new ListNode(p->val);
			node->next = rHead;
			rHead = node;

			p = p->next;
		}//while

		p = head;
		ListNode *q = rHead;
		while (p && q)
		{
			if (p->val != q->val)
				return false;
			p = p->next;
			q = q->next;
		}//while
		return true;
	}
	
	//方法三：迭代法，要探测链表的前半部分是否为后半部分反转而成，只需要将前半部分链表反转；利用栈实现。
	bool isPalindrome2(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		ListNode *slow = head, *fast = head;
		stack<int> st;
		/*将链表的前半部分入栈，当fast指针（移动速度为慢速指针的两倍）到达链表尾部时，慢速指针到达中间位置*/
		while (slow && fast->next)
		{
			st.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}//while

		//当为奇数个元素时，跳过中间元素
		if (fast)
		{
			slow = slow->next;
		}//if

		while (slow)
		{
			if (slow->val != st.top())
				return false;
			slow = slow->next;
			st.pop();
		}//while

		return true;
	}


};

int main()
{
	ListNode *head = NULL;

	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);
	for (int i = 3; i > 0; --i)
		head = insert(head, i);

	display(head);

	Solution s;
	cout << s.isPalindrome1(head) << endl;
	cout << s.isPalindrome2(head) << endl;

	system("pause");
	return 0;
}