/*
 * 题目：面试题42 左旋转字符串
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
 * 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
 * 请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
 * 要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty() || n == 0)
			return str;

		n %= str.size();

		string::iterator beg = str.begin();
		reverse(beg, beg + n);
		reverse(beg + n, str.end());
		reverse(beg, str.end());

		return str;
	}
};

int main()
{
	Solution s;

	string str = "abcdefg";
	str = s.LeftRotateString(str, 2);
	cout << str << endl;

	system("pause");
	return 0;
}