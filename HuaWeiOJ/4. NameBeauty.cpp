/*
描述
给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。
给出多个名字，计算每个名字最大可能的“漂亮度”。
知识点	字符串
运行时间限制	0M
内存限制	0
输入
整数N，后续N个名字
N个字符串，每个表示一个名字

输出
每个名称可能的最大漂亮程度
样例输入	2 zhangsan lisi
样例输出	192 101
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**/
int cmp(const int &a, const int &b)
{
	if (a > b)
		return 1;
	else
		return 0;
}

/*利用哈希的思想，计算每个字符出现的次数*/
const int N = 256;
int maxBeautyValue(string name)
{
	if (name.empty())
		return 0;

	int ret = 0;
	vector<int> letters(N, 0);
	int len = name.length();
	for (int i = 0; i < len; ++i)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
			++letters[name[i] - 'A' + 'a' - '0'];
		else if (name[i] >= 'a' && name[i] <= 'z')
			++letters[name[i] - '0'];
		else
		{
			cout << "wrong input name!" << endl;
			return -1;
		}
	}//for
	/*根据字符个数降序排列*/
	sort(letters.begin() , letters.end() , cmp);
	for (int i = 0, tmp = 26; i < len; ++i)
	{
		if (letters[i] > 0)
		{
			ret += (letters[i] * tmp);
			--tmp;
		}//if
	}//for
	return ret;
}

int main()
{
	int N;
	cin >> N;
	char name[1024];
	int beautyValue = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		cout << maxBeautyValue(name) << endl;
	}//for

	system("pause");
}