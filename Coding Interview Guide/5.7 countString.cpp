/*
5.7 字符串的统计字符串

题目：给定一个字符串str，返回str的统计字符串。例如，“aaabbadddffc”
的统计字符串为a3b2a1d3f2c1

补充题目：给定一个字符串的统计字符串cstr，再给定一个整数index，返回cstr所代表
的原始字符串的第index个字符。
例如a_1_b_100所代表的原始字符串上第0个字符为'a'，第50个字符为'b'
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*基本题目*/
string countStr(const string str)
{
	if (str.empty())
		return NULL;

	string res;
	res += str[0];
	int len = str.length(), count = 1;
	for (int i = 1; i < len; ++i)
	{
		if (str[i] == str[i - 1])
			++count;
		else{
			char c = count + '0';
			res = res + '_' + c + '_' + str[i];
			count = 1;
		}//else
	}//for
	char c = count + '0';
	res = res + '_' + c;

	return res;
}

/*扩充题目*/
char getChar(const string str, int idx)
{
	if (str.empty())
		return '\0';

	/*求给定统计字符串的长度，判断是否越界*/
	int len = str.length();
	if (idx < 0 || idx >= len)
		return '\0';

	/*flag代表当前字符状态，为true代表为字母，为false代表为统计数字*/
	bool flag = true;
	/*count记录源串的当前字符个数*/
	int sum = 0, count = 0;
	char pre = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '_')
		{
			flag = !flag;
			continue;
		}//if
		/*当前是字母*/
		else if (flag)
		{
			sum += count;
			if (sum > idx)
				return pre;
			else{
				/*保存当前字符*/
				pre = str[i];
				count = 0;
			}//else
		}//elif
		else{
			/*更新当前字符的统计数量*/
			count = count * 10 + str[i] - '0';
		}//else
	}//for

	if (sum + count > idx)
		return pre;
	return 0;
}

//int main()
//{
//	cout << countStr("aaabbadddffc") << endl;
//
//	cout << getChar("a_3_b_2_a_1_d_3_f_2_c_1", 6) << endl;
//	system("pause");
//	return 0;
//}