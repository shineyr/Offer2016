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

//定义包裹类
class PartialSum{
public:
	ListNode *sum = NULL;
	int carry = 0;
};

class Solution{
public:
	/* 进阶：数位是正向存放,链表相加实现！方法一：可以利用头插法，将链表反转，然后调用上面函数实现；
	* 下面使用另外一种方法实现：
	*/
	ListNode *addLists2(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL)
			return head2;
		else if (head2 == NULL)
			return head1;

		//求两个链表的长度
		int len1 = 0, len2 = 0;
		ListNode *p = head1, *q = head2;
		while (p)
		{
			++len1;
			p = p->next;
		}//while

		while (q)
		{
			++len2;
			q = q->next;
		}//while

		//用0元素节点填充较短链表的首部
		if (len1 < len2)
		{
			head1 = padList(head1, len2 - len1);
		}
		else{
			head2 = padList(head2, len1 - len2);
		}//else
		
		//对两个链表求和
		PartialSum *sum = addListHelper(head1, head2);

		//如果有进位则插入链表首部，若无进位则直接返回
		if (sum->carry == 0)
			return sum->sum;
		else{
			ListNode *result = insertBefore(sum->sum, sum->carry);
			return result;
		}//else
		
	}

	PartialSum *addListHelper(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL && head2 == NULL)
		{
			PartialSum *sum = new PartialSum();
			return sum;
		}

		//对较小数字递归求和
		PartialSum *sum = addListHelper(head1->next, head2->next);

		//将进位和当前数据相加
		int val = sum->carry + head1->val + head2->val;

		//插入当前求和结果
		ListNode *full_result = insertBefore(sum->sum, val % 10);

		//返回求和结果和进位值
		sum->sum = full_result;
		sum->carry = val / 10;

		return sum;
	}

	//插入元素节点到链表首部
	ListNode *insertBefore(ListNode *head, int data)
	{
		ListNode *node = new ListNode(data);
		node->next = head;
		head = node;

		return head;
	}
	//在链表head的首部，添加len个值为0的节点
	ListNode* padList(ListNode *head, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			ListNode *node = new ListNode(0);
			if (head == NULL)
				head = node;
			else{
				node->next = head;
				head = node;
			}
		}//for
		return head;
	}
};

int main()
{
	ListNode *head1 = NULL, *head2 = NULL, *head = NULL;

	head1 = insert(head1, 6);
	head1 = insert(head1, 1);
	head1 = insert(head1, 7);

	display(head1);
	head2 = insert(head2, 2);
	head2 = insert(head2, 9);
	head2 = insert(head2, 5);

	display(head2);

	Solution s;
	head = s.addLists2(head1, head2);

	display(head);

	system("pause");
	return 0;
}