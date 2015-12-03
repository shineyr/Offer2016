/*
* 面试题8.3.5用两个栈实现一个队列。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class MyQueue{
public:
	void push(int val)
	{
		inStack.push(val);
	}

	int pop()
	{
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				int val = inStack.top();
				outStack.push(val);
				inStack.pop();
			}//while


		}//if
		int val = outStack.top();
		outStack.pop();
		return val;

	}

	int front()
	{
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				int val = inStack.top();
				outStack.push(val);
				inStack.pop();
			}//while
		}//if
		else
		{
			int val = outStack.top();
			return val;
		}//else
	}

	bool empty()
	{
		return inStack.empty() && outStack.empty();
	}
private:
	stack<int> inStack;
	stack<int> outStack;
};

int main()
{
	MyQueue mq;
	mq.push(1);
	mq.push(2);
	cout << mq.pop() << endl;
	mq.push(3);
	cout << mq.pop() << endl;

	cout << mq.pop() << endl;

	system("pause");
	return 0;
}