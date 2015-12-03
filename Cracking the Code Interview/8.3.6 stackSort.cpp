/*
* 面试题8.3.6 对栈实现升序排序。
* 最多只能使用一个额外的栈存放临时数据，但是不得将元素复制到别的数据结构中（如数组）。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution{
public:
	stack<int> stackSort(stack<int> s)
	{
		if (s.empty())
			return s;

		stack<int> ret;
		while (!s.empty())
		{
			int tmp = s.top();
			s.pop();

			//找到tmp在ret栈中应该插入的位置
			while (!ret.empty() && ret.top() > tmp)
			{
				s.push(ret.top());
				ret.pop();
			}//while
			ret.push(tmp);
		}//while
		return ret;			
	}
};

int main()
{
	Solution s;

	stack<int> st;
	st.push(3);
	st.push(4);
	st.push(2);
	st.push(1);

	stack<int> ret = s.stackSort(st);
	while (!ret.empty())
	{
		cout << ret.top() << "\t";
		ret.pop();
	}//while
	cout << endl;

	system("pause");
	return 0;
}