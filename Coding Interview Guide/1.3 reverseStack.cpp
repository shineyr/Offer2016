/*
题目：仅使用递归函数和栈操作逆序一个栈
一个栈依次压入1，2，3，4，5，那么从栈顶到栈底分别为5，4，3，2，1。将这个栈转置后，从栈顶到栈底为
1，2，3，4，5，也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能使用其他数据结构。
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <cassert>

using namespace std;

/*递归函数一：实现将栈底元素返回并移除*/
int getAndRemoveLastElement(stack<int> &stk)
{
	assert(!stk.empty());
	int ret = stk.top();
	stk.pop();
	if (stk.empty())
		return ret;
	else
	{
		int last = getAndRemoveLastElement(stk);
		stk.push(ret);
		return last;
	}//else
}

/*递归函数二：逆序一个栈*/
void reverse(stack<int> &stk)
{
	if (stk.empty())
		return;
	int i = getAndRemoveLastElement(stk);
	reverse(stk);
	stk.push(i);
}

int main()
{
	stack<int> stk;
	for (int i = 1; i <= 5; ++i)
		stk.push(i);

	while (!stk.empty())
	{
		cout << stk.top() << "\t";
		stk.pop();
	}//while
	cout << endl;
	system("pause");
	return 0;
}