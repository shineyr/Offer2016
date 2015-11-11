/*
 * 面试题32 ：整数中1出现的次数（从1到n整数中1出现的次数）
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
 * 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
 * 可以很快的求出任意非负整数区间中1出现的次数。
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 0)
			return 0;

		char strN[50];
		sprintf(strN, "%d", n);
		return NumberOf1(strN);
	}

	int NumberOf1(const char *strN)
	{
		if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
			return 0;

		int first = *strN - '0';

		unsigned int length = static_cast<unsigned int>(strlen(strN));

		if (length == 1 && first == 0)
			return 0;

		if (length == 1 && first > 0)
			return 1;

		//假设strN是21345
		//numFirstDigit 是10000 - 19999中的第一个位中的数目
		int numFirstDigit = 0;
		if (first > 1)
			numFirstDigit = PowerBase10(length - 1);
		else if (first == 1)
			numFirstDigit = atoi(strN + 1) + 1;

		//numOtherDigits是1346 - 21345除了第一位之外的数位中的数目
		int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);

		//numRecursive是1 - 1345中的数目
		int numRecursive = NumberOf1(strN + 1);

		return numFirstDigit + numOtherDigits + numRecursive;
	}

	int PowerBase10(unsigned int n)
	{
		int res = 1;
		for (unsigned int i = 0; i < n; ++i)
			res *= 10;
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1Between1AndN_Solution(21345) << endl;

	system("pause");
	return 0;
}
