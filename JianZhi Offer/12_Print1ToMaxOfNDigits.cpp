/*
面试题 12: 打印1到最大的n位数

题目： 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印1/2/3一直到999.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

bool Increment(string &number)
{
	bool isOverFlow = false;
	int carry = 0, len = number.size();
	for (int i = len - 1; i >= 0; --i)
	{
		int nSum = (number[i] - '0') + carry;
		/*个位+1*/
		if (i == len - 1)
			nSum += 1;

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverFlow = true;
			}//if
			else {
				carry = 1;
				nSum -= 10;
				number[i] = nSum + '0';
			}//else
		}
		else {
			number[i] = nSum + '0';
			break;
		}
	}//for
	return isOverFlow;
}

void printNumber(string number)
{
	int len = number.size(), idx = 0;
	while (number[idx] == '0')
	{
		++idx;
		continue;
	}//while
	while (idx < len)
		cout << number[idx++];
	cout << endl;
}

/*方法一：转换为打印字符串*/
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;

	string number(n, '0');
	while (!Increment(number))
	{
		printNumber(number);
	}//while
}

void Print1ToMaxOfNDigitsRecursively(string &number, int idx)
{
	int len = number.size();
	if (idx == len - 1)
	{
		printNumber(number);
		return;
	}//if

	for (int i = 0; i < 10; ++i)
	{
		number[idx + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, idx + 1);
	}//for
}
/*方法二：递归解决*/
void Print1ToMaxOfNDigits2(int n)
{
	if (n <= 0)
		return;
	string number(n, '0');

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, 0);
	}
}

/*方法三：动态规划*/
vector<int> Print1ToMaxOfNDigits3(int n)
{
	if (n <= 0)
	{
		return vector<int>();
	}//if
	else if (n == 1)
	{
		vector<int> ret = { 1,2,3,4,5,6,7,8,9 };
		return ret;
	}
	else {
		   vector<int> ret = { 1,2,3,4,5,6,7,8,9 };
		   vector<int> lastRet = Print1ToMaxOfNDigits3(n - 1);
		   for (auto iter = lastRet.begin(); iter != lastRet.end(); ++iter)
		   {
			   for (int i = 0; i < 10; ++i)
			   {
				   ret.push_back(*iter * 10 + i);
			   }
			   
		   }//for

		   return ret;
	}
}
int main()
{
	Print1ToMaxOfNDigits2(3);

	vector<int> ret = Print1ToMaxOfNDigits3(3);
	system("pause");
	return 0;
}