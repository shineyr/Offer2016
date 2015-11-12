/*
 * 面试题35：第一个只出现一次的字符位置
 * 描述：在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。
 * 若为空串，返回-1。位置索引从0开始。
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
	//方法一：二次遍历
	int FirstNotRepeatingChar1(string str) {
		if (str.empty())
			return -1;

		int size = str.length();
		if (size == 1)
			return 0;
		
		vector<int> visited(size,0);

		for (int i = 0; i < size; ++i)
		{
			if (visited[i] == 1)
				continue;
			//标记为已访问
			visited[i] = 1;
			//向后查找
			int j;
			for (j = i + 1; j < size; ++j)
			{
				if (visited[j] == 1)
					continue;
				if (str[j] == str[i])
					break;
			}
			//找到第一个只出现一次的字符
			if (j == size)
			{
				return i;
			}//if
			else{
				//说明该字符是重复字符，将所有的该字符都标记为访问过
				for (j = i + 1; j < size; ++j)
				{
					if (str[j] == str[i])
						visited[j] = 1;
				}//for
			}
		}//for
		return -1;
	}

	//方法二：利用哈希
	int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;

		int size = str.length();
		if (size == 1)
			return 0;

		const int MAX_LENGTH = 256;
		vector<int> hashTable(MAX_LENGTH, 0);

		string::iterator iter = str.begin();
		while (iter != str.end())
			++hashTable[*(iter++)];

		iter = str.begin();
		while (iter != str.end())
		{
			if (hashTable[*iter] == 1)
				return iter - str.begin();
			++iter;
		}
		return -1;
	}
};

int main()
{
	string str = "Hello , Hey , I am a good student";

	Solution s;

	cout << s.FirstNotRepeatingChar(str) << endl;

	system("pause");
	return 0;
}
