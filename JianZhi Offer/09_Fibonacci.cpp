/*
* 题目: 斐波那契数列
* 描述:
* 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


class Solution {
public:
	int Fibonacci(int n) {
		//存储斐波那契数列
		vector<int> v(n+1, 0);
		v[0] = 0;
		v[1] = 1;

		for (int i = 2; i <= n; ++i)
			v[i] = v[i - 1] + v[i - 2];

		return v[n];
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.Fibonacci(3) << endl;
//
//	system("pause");
//	return 0;
//}