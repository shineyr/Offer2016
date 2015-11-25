/*
 * 面试题8.1.4 编写程序，将字符串中的空格全部替换为%20。假定字符串末尾有足够的空间存放新增字符，并且知道字符串的真实长度。 
 */
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	void replaceSpaces(char *str, int len)
	{
		if (len <= 0)
			return;

		//求出空格的个数
		int count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ')
				++count;
		}

		//计算新长度
		int newlen = len + 2 * count;
		str[newlen] = '\0';
		for (int i = len - 1; i >= 0; --i)
		{
			if (str[i] == ' ')
			{
				str[newlen - 1] = '0';
				str[newlen - 2] = '2';
				str[newlen - 3] = '%';
				newlen -= 3;
			}
			else{
				str[newlen - 1] = str[i];
				newlen -= 1;
			}//else
		}//for
		return;
	}
};

int main()
{
	Solution s;
	//声明的必须是字符串变量
	char str[] = "I am a good student!";

	//下面str2是字符串常量
	char *str2 = "I am a good student!";
	s.replaceSpaces(str , 21);

	cout << str << endl;

	system("pause");
	return 0;
}