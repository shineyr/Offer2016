/*
 * 题目： 用两个栈实现队列
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。 
 */

#include <iostream>
#include <cstdlib>
#include <stack>
#include <exception>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}//while
		}

		int ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;

	for (int i = 0; i < 3; ++i)
		s.push(i);

	cout << s.pop() << endl;

	s.push(5);

	cout << s.pop() << endl;

	system("pause"); return 0;
}