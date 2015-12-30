/************************************************************************/
/*
描述
Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小
（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过C语言解决。

知识点	字符串
运行时间限制	0M
内存限制	0
输入
Lily使用的图片包括"A"到"Z"、"a"到"z"、"0"到"9"。输入字母或数字个数不超过1024。

输出
Lily的所有图片按照从小到大的顺序输出

样例输入	Ihave1nose2hands10fingers
样例输出	0112Iaadeeefghhinnnorsssv
*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*定义输入字符串，不超过1024，初始长度1025*/
	char str[1025];
	int i, j, len;
	char c;

	/*从控制台输入*/
	gets_s(str);
	len = strlen(str);

	/*根据ASCII码值，对字符串插入排序*/
	for (i = 1; i<len; ++i)
	{
		c = str[i];
		j = i - 1; 
		while (j >= 0 && str[j] > c)
		{		
			str[j + 1] = str[j];
			--j;
		}//while
		str[j + 1] = c;
	}//for
	printf("%s\n", str);
	system("pause");
}