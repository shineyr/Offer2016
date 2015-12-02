/*
* 面试题8.3.3 设想有一堆盘子，堆太高可能会倒下。因此在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。
* 请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时，新建一个栈。此外，push和pop函数
* 应该与普通栈相同。
* 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

const int MAXSIZE = 2;

class SetOfStacks{
public:
	void push(int val)
	{
		//压入最后一个非空栈
		if (stacks.empty())
		{
			stack<int> s;
			s.push(val);
			stacks.push_back(s);
		}
		else{
			//找到最后一个非空栈
			int idx = stacks.size() - 1;
			while (idx != 0 && stacks[idx].empty())
			{
				--idx;
			}
			//模拟最后一个栈满
			if (stacks[idx].size() == MAXSIZE)
			{
				//判断是否需要新栈
				if (idx == stacks.size() - 1)
				{
					stack<int> s;
					s.push(val);
					stacks.push_back(s);
				}
				//不需要新栈
				else{
					stacks[idx + 1].push(val);
				}
				
			}
			else{
				stacks[idx].push(val);
			}
		}
	}

	void pop()
	{
		//找到最后一个非空栈
		int i = 0;
		while (i < stacks.size() && !stacks[i].empty())
		{
			++i;
		}
		stacks[i - 1].pop();
	}

	int top()
	{
		//找到最后一个非空栈
		int i = 0;
		while (i < stacks.size() && !stacks[i].empty())
		{
			++i;
		}
		return stacks[i - 1].top();
	}
private:
	vector<stack<int> > stacks;
};

int main()
{
	SetOfStacks stacks;

	for (int i = 0; i < 4; ++i)
		stacks.push(i);
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.push(5);
	cout << stacks.top() << endl;

	stacks.push(6);
	cout << stacks.top() << endl;

	system("pause");
	return 0;



}