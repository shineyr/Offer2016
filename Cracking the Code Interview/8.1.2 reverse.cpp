/*
* 8.1.2 反转一个null结尾的字符串
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	//方法一：使用指针
	void reverse(char *str){
		if (str == NULL)
			return;

		//找出字符串末尾
		char *end = str;
		if (str)
		{
			while (*end != '\0')
				++end;
		}
		//回退一个字符最后一个为null
		--end;
		
		/*从字符串首尾开始交换，直到两个指针相遇*/
		while (str < end)
		{
			char tmp = *str;
			*str++ = *end;
			*end-- = tmp;

		}//while
		return;
	}

	//方法二：使用变量
	void reverse2(char *str)
	{
		if (str == NULL)
			return;

		int len = 0;
		while (str[len] != '\0')
			++len;

		/*从首尾交换*/
		int lhs = 0, rhs = len - 1;
		while (lhs < rhs)
		{
			char tmp = str[lhs];
			str[lhs++] = str[rhs];
			str[rhs--] = tmp;
		}//while
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
	s.reverse2(str);

	cout << str << endl;

	system("pause");
	return 0;
}