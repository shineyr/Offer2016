/************************************************************************
描述	
计算字符串最后一个单词的长度，单词以空格隔开。
知识点	字符串,循环
运行时间限制	0M
内存限制	0
输入	
一行字符串，长度小于128。
输出	
整数N，最后一个单词的长度。
样例输入	hello world
样例输出	5
**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin , str))
	{
		if (str == "")
			cout << 0 << endl;
		else{
			int len = strlen(str.c_str()), i;
			for (i = len - 1; str[i] != ' ' && i>0; i--)
				;
			if (i == 0)
				cout << len;
			else
			cout << len - (i+1) << endl;
		}//else
	
	}//while
	system("pause");
	return 0;
}