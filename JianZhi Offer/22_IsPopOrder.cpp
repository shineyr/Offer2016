/*
 * 栈的压入、弹出序列
 * 题目描述
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//错误情况
		if (pushV.size() != popV.size() || pushV.empty() || popV.empty())
			return false;

		bool ret = false;
		//求元素序列个数
		int len = pushV.size();
		vector<int>::iterator pNextPush = pushV.begin(),
			pNextPop = popV.begin();

		stack<int> s;

		while (pNextPop != popV.end())
		{
			while (s.empty() || s.top() != *pNextPop)
			{
				if (pNextPush == pushV.end())
					break;

				s.push(*pNextPush);
				pNextPush++;
			}
			if (s.top() != *pNextPop)
				break;
			s.pop();
			pNextPop++;
		}//while
		if (s.empty() && pNextPop == popV.end())
			ret = true;
		return ret;
	}
};

//int main()
//{
//	vector<int> pushV = { 1, 2, 3, 4, 5 }, popV = { 4, 5, 3, 1, 2 };
//	Solution s;
//	cout << s.IsPopOrder(pushV, popV) << endl;
//
//	system("pause");
//	return 0;
//}