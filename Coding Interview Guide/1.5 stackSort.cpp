/*
用一个栈实现另一个栈的排序。
不申请额外的数据结构情况下，借助一个栈实现另一个栈的排序。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

void stackSort(stack<int> &stk)
{
	if (stk.empty())
		return;

	stack<int> help;
	/*将stk中的所有元素，升序存储入help栈中*/
	while (!stk.empty())
	{
		int cur = stk.top();
		stk.pop();
		while (!help.empty() && help.top() < cur)
		{
			stk.push(help.top());
			help.pop();
		}//while
		help.push(cur);
	}//while
	swap(stk,stack<int>());
	while (!help.empty())
	{
		stk.push(help.top());
		help.pop();
	}//while
}

int main()
{
	stack<int> stk;
	stk.push(3);
	stk.push(8);
	stk.push(2);
	stk.push(6);

	stackSort(stk);

	system("pause");
	return 0;

}