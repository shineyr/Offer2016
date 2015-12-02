/*
* 面试题8.3.2 设计一个栈，除了push和pop方法，还支持min方法，可返回栈中的最小值。push，pop和min方法时间复杂度均控制在O(1)
* 有两种实现方式：
* （1）增加一个变量保存当前栈中最小元素，push和pop均更新，此时pop的时间复杂度为线性；
* （2）利用一个辅助栈保存每个时刻栈中最小元素，此时，需要额外空间；
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

class StackWithMin{
public:
	void push(int val)
	{		
		if (s.empty() || val < minVal)
			minVal = val;
		s.push(val);
	}

	int top()
	{
		return s.top();
	}

	int minV()
	{
		if (s.empty())
			return INT_MAX;
		return minVal;
	}

	int pop()
	{
		int ret = s.top();
		s.pop();

		//当前栈顶元素即是最小元素，更新最小元素
		if (ret == minVal)
		{
			vector<int> v;
			while (!s.empty())
			{
				v.push_back(s.top());
				s.pop();
			}//while

			//更新最小元素
			int len = v.size();
			minVal = v[0];
			for (int i = 0; i < len; ++i)
			{
				if (v[i] < minVal)
					minVal = v[i];
			}

			//还原栈中元素
			for (int i = 0; i < len; ++i)
			{
				s.push(v[i]);
			}//for
		}
		
		return ret;
	}
private:
	stack<int> s;
	int minVal;
};

class StackWithMin2{
public:
	void push(int val)
	{
		//更新最小元素
		if (nums.empty())
		{		
			minV.push(val);
		}
		else if (nums.top() > val)
		{
			minV.push(val);
		}
		else{
			minV.push(nums.top());
		}
		nums.push(val);
	}

	int pop()
	{
		int ret = nums.top();
		nums.pop();
		minV.pop();
		return ret;
	}

	int top()
	{
		return nums.top();
	}

	int min()
	{
		return minV.top();
	}

private:
	stack<int> nums;
	stack<int> minV;
};

int main()
{
	StackWithMin2 s;

	s.push(2);
	cout << s.min() << endl;
	s.push(1);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;

	system("pause");
	return 0;

}