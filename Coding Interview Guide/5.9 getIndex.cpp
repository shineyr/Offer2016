/*
5.9 在有序但含有空格的数组中查找字符串
题目：
给定一个字符串数组strs[]，在strs中有些位置为null，但在不为null的位置上，
其字符串是按字典顺序由小到大依次出现的。再给定一个字符串str，请返回str在
strs中出现的最左的位置。
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int getIndex(vector<string> strs, string str)
{
	if (strs.empty())
		return -1;
	int lhs = 0, rhs = strs.size() - 1;
	/*存储下标结果*/
	int pos = -1;
	while (lhs <= rhs)
	{
		int mid = (lhs + rhs) / 2;
		if (!strs[mid].empty())
		{
			if (strs[mid] == str)
			{
				pos = mid;
				rhs = mid - 1;
			}//if
			else if (strs[mid] < str)
			{
				lhs = mid + 1;
			}//if
			else
				rhs = mid - 1;
		}//if
		else
		{
			int i = mid;
			while (strs[i].empty() && --i >= lhs)
				;
			if (i < lhs || strs[i] < str)
				lhs = mid + 1;
			else
			{
				pos = strs[i] == str ? i : pos;
				rhs = i - 1;
			}//else
		}//else
	}
	return pos;
}

int main()
{
	vector<string> v = { "a", "a", string(), string(), "a", "b", string(), "c" };

	cout << getIndex(v, "a") << endl;

	system("pause");
	return 0;
}