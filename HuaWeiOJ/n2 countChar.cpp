/*
题目描述
写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
输入一个有字母和数字以及空格组成的字符串，和一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

输入例子:
ABCDEF
A

输出例子:
1
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int countC(string str, char c)
{
	int ret = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (c == str[i])
			++ret;
	}//for
	return ret;
}

//int main()
//{
//	string str; 
//	char c;
//	getline(cin, str);
//	cin >> c;
//	cout << countC(str, c) << endl;
//
//	system("pause");
//	return 0;
//}