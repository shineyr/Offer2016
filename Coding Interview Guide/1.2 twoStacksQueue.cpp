/*
题目：编写一个类，用两个栈实现队列，支持队列的基本操作
注意：
	1. 如果stackPush要往stackPop中压入数据，那么必须一次性把stackPush中的数据全部压入；
	2. 如果stackPop不为空，stackPush绝对不能向stackPop中压入数据
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <cassert>

using namespace std;

class MyQueue{
private:
	stack<int> stackPush;
	stack<int> stackPop;

public:
	MyQueue(){}

	void push(int val)
	{
		stackPush.push(val);
	}

	void pop()
	{
		assert(!(stackPush.empty() && stackPop.empty()));
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}//while
		}
		else
		{
			stackPop.pop();
		}
	}

	int top()
	{
		assert(!(stackPush.empty() && stackPop.empty()));
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}//while
		}
		return stackPop.top();
	}
};

int main()
{
	MyQueue mq;

	mq.push(1);
	mq.push(2);
	cout << mq.top() << endl;
	mq.pop();

	cout << mq.top() << endl;

	mq.push(3);
	mq.push(4);
	cout << mq.top() << endl;
	mq.pop();

	cout << mq.top() << endl;
	system("pause");
	return 0;
}