/*面试题55 字符流中第一个不重复的字符

题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 256;

char firstAppearingOne(string str)
{

	vector<int> pos(N, -1);
	if (str.empty())
		return '\0';
	int n = str.size();
	for (int i = 0; i < n; ++i)
	{
		/*对于未出现过的元素，保存其出现的位置*/
		if (pos[str[i]] == -1)
			pos[str[i]] = i;
		//对于出现过的元素，其肯定不是仅仅出现一次，将其值设为特殊的-2；
		else
			pos[str[i]] = -2;
	}//for

	int minPos = numeric_limits<int>::max();
	char c;
	for (int i = 0; i < n; ++i)
	{
		if (pos[str[i]] >= 0 && minPos > pos[str[i]])
		{
			c = str[i];
			minPos = pos[str[i]];
		}
	}

	return c;
}

int main()
{
	cout << firstAppearingOne("google") << endl;


	system("pause");
	return 0;
}