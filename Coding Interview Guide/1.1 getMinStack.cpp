/*
题目：设计一个有getMin功能的栈 page 1
要求：
	1. pop、push、getMin操作的时间复杂度都是O(1)
	2. 设计的栈类可以使用现成的栈结构
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stack>

using namespace std;

/*方案一*/
class MinStack1{
public:
	void push(int val)
	{
		if (stackMin.empty())
			stackMin.push(val);
		else if (stackMin.top() > val)
			stackMin.push(val);

		stackData.push(val);
	}

	int pop()
	{
		assert(!stackData.empty());

		int ret = stackData.top();
		if (ret == stackMin.top())
			stackMin.pop();

		stackData.pop();

		return ret;
	}

	int getMin()
	{
		assert(!stackMin.empty());
		return stackMin.top();	
	}
private:
	stack<int> stackData;
	stack<int> stackMin;
};
/*方案2*/
class MinStack2{
public:
	void push(int val)
	{
		this->values.push(val);
		/*保存当前栈中的最小元素*/
		if (minVal.empty())
			minVal.push(val);
		else if (val < minVal.top())
			minVal.push(val);
		else
			minVal.push(minVal.top());
	}


	int pop()
	{
		/*验空*/
		assert(!values.empty());
		int ret = values.top();
		values.pop();
		minVal.pop();

		return ret;
	}

	int getMin()
	{
		return minVal.top();
	}

	bool isEmpty()
	{
		return values.empty();
	}

	int top()
	{
		return values.top();
	}
private:	
	/*辅助结构*/
	stack<int> minVal;
	stack<int> values;
};

int main()
{
	MinStack1 stk1;
	MinStack2 stk2;

	for (int i = 8; i > 1; --i)
	{
		stk1.push(i);
		stk2.push(i);
	}//for

	cout << stk1.getMin() << endl;
	cout << stk2.getMin() << endl;

	system("pause");
	return 0;
}