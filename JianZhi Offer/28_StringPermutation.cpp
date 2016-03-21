/*
面试题28 字符串的排列

题目：
输入一个字符串，打印出该字符串中字符的所有排列。
*/

#include <iostream>
#include <cstdlib>

using namespace std;


void Permutation(char *pStr, char *pBeg)
{
	/*结束字符*/
	if (*pBeg == '\0')
		cout << pStr << endl;
	else {
		for (char *pCh = pBeg; *pCh != '\0'; ++pCh)
		{
			char tmp = *pCh;
			*pCh = *pBeg;
			*pBeg = tmp;

			Permutation(pStr, pBeg + 1);

			tmp = *pCh;
			*pCh = *pBeg;
			*pBeg = tmp;
		}//for
	}//else
}

/*字符串排列函数*/
void Permutation(char *pStr)
{
	if (pStr == NULL)
		return;

	Permutation(pStr, pStr);
}

int main()
{
	/*定义字符串变量*/
	char str[] = "abc";
	Permutation(str);

	system("pause"); return 0;
}