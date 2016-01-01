/************************************************************************/
/*
描述
题目描述
1、对输入的字符串进行加解密，并输出。
2加密方法为：
当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
其他字符不做变化。
3、解密方法为加密的逆过程。

接口描述：
实现接口，每个接口实现1个基本操作：
void Encrypt (char aucPassword[], char aucResult[])：在该函数中实现字符串加密并输出
说明：
1、字符串以\0结尾。
2、字符串最长100个字符。

int unEncrypt (char result[], char password[])：在该函数中实现字符串解密并输出
说明：
1、字符串以\0结尾。
2、字符串最长100个字符。
知识点	字符串
运行时间限制	10M
内存限制	128
输入
输入说明
输入一串要加密的密码
输入一串加过密的密码
输出
输出说明
输出加密后的字符
输出解密后的字符
样例输入	abcdefg BCDEFGH
样例输出	BCDEFGH abcdefg
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*加密函数*/
void Encrypt(char aucPassword[], char aucResult[])
{
	int len = strlen(aucPassword);
	for (int i = 0; i < len; ++i)
	{
		char c = aucPassword[i];
		if (c >= '0' && c <= '9')
		{
			if (c == '9')
				aucResult[i] = '0';
			else
				aucResult[i] = c + 1;
		}//if
		else if (c >= 'A' && c <= 'Z')
		{
			if (c == 'Z')
				aucResult[i] = 'a';
			else
				aucResult[i] = c - 'A' + 'b';
		}//elif
		else if (c >= 'a' && c <= 'z')
		{
			if (c == 'z')
				aucResult[i] = 'A';
			else
				aucResult[i] = c - 'a' + 'B';
		}//elif
		else
			aucResult[i] = c;
	}//for
	aucResult[len] = '\0';
}

/*解密函数*/
void unEncrypt(char result[], char password[])
{
	int len = strlen(result);
	for (int i = 0; i < len; ++i)
	{
		char c = result[i];
		if (c >= '0' && c <= '9')
		{
			if (c == '0')
				password[i] = '9';
			else
				password[i] = c - 1;
		}//if
		else if (c >= 'A' && c <= 'Z')
		{
			if (c == 'A')
				password[i] = 'z';
			else
				password[i] = c - 'B' + 'a';
		}//elif
		else if (c >= 'a' && c <= 'z')
		{
			if (c == 'a')
				password[i] = 'Z';
			else
				password[i] = c - 'b' + 'A';
		}//elif
		else
			password[i] = c;
	}//for
	password[len] = '\0';
}

int main()
{
	char str[100], password[100];
	
	/*给定输入*/
	cin >> str;
	cin >> password;
	char strRet[128], pwdRet[128];
	Encrypt(str, strRet);
	unEncrypt(password, pwdRet);
	
	/*输出加密解密后的结果*/
	cout << strRet << endl;
	cout << pwdRet << endl;

	system("pause");
	return 0;
}