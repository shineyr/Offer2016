/*
5.2 字符串中数字子串的求和

题目：给定一个字符串str，求其中全部数字串所代表的数字之和；
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*字符串中数字子串的求和*/
int subStrSum(string str)
{
	if (str.empty())
		return 0;

	int res = 0, num = 0, cur = 0;
	bool flag = true;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		cur = str[i] - '0';
		if (cur<0 || cur>9)
		{
			res += num;
			num = 0;
			/*更新正负*/
			if (str[i] == '-')
			{
				if (i > 0 && str[i - 1] == '-')
					flag = !flag;
				else
					flag = false;
			}//if
			else{
				flag = true;
			}//else
		}//if
		else{
			num = num * 10 + (flag ? cur : -cur);
		}//else
	}//for

	/*加上最后一个数字子串值，若末尾不是数字子串num=0*/
	res += num;
	return res;
}

int main()
{
	string str = "A-1BC--12";
	cout << subStrSum(str) << endl;

	system("pause");
	return 0;
}