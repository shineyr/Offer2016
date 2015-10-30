/*
 * 包含min函数的栈
 * 题目描述
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution {
public:
	void push(int value) {
		m_data.push(value);

		if (m_min.empty() || m_min.top() > value)
			m_min.push(value);
		else
			m_min.push(m_min.top());

	}
	void pop() {
		m_data.pop();
		m_min.pop();
	}

	int top() {
		return m_data.top();
	}
	int min() {
		return m_min.top();
	}
private:
	stack<int> m_data;	//数据栈
	stack<int> m_min;	//辅助栈，存储当前数据栈中所有元素的最小值
};

//int main()
//{
//	Solution s;
//	s.push(1);
//	cout << s.min() << endl;
//	s.push(3);
//	cout << s.min() << endl;
//	s.push(2);
//	cout << s.min() << endl;
//
//	system("pause");
//	return 0;
//}