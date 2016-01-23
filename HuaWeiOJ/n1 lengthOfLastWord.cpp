/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。

输入描述:
一行字符串。

输出描述:
整数N，最后一个单词的长度。

输入例子:
hello world

输出例子:
5
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int lengthOfLastWord(string str)
{
	int length = str.length();
	int pos = str.find_last_of(" ");
	return length - pos - 1;
}

//int main()
//{
//	string str;
//	while (getline(std::cin, str))
//	{
//		cout << lengthOfLastWord(str) << endl;
//	}//while
//
//	system("pause");
//	return 0;
//}