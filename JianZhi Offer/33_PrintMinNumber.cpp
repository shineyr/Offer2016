/*
 * 面试题33：把数组排成最小的数
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
 * 则打印出这三个数字能排成的最小数字为321323。
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//自定义比较规则
bool compare(const string &str1, const string &str2)
{
	string s1 = str1 + str2, s2 = str2 + str1;
	return s1 < s2;
}

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return string();

		int size = numbers.size();
		vector<string> str(size, string());
		for (int i = 0; i < size; ++i)
		{
			//将每个整数转换为字符串
			char tmp[21];
			sprintf(tmp, "%d", numbers[i]);
			str[i] = tmp;
		}//for

		sort(str.begin(), str.end(), compare);

		//对于已排序的字符串序列直接连接即是组合成的最小整数
		string ret;
		for (int i = 0; i < size; ++i)
		{
			ret += str[i];
		}//for
		return ret;
	}
};

int main()
{
	vector<int> v = { 3, 32, 321 };
	Solution s;

	cout << s.PrintMinNumber(v) << endl;

	system("pause");
	return 0;
}
