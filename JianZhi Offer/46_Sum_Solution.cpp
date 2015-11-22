/*
 * 面试题 46 求1+2+3 + ... + n
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Sum{
public:
	Sum(){
		++n;
		sum += n;
	}

	static void clear()
	{
		n = 0;
		sum = 0;
	}

	static int getSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
};

unsigned Sum::n = 0;
unsigned Sum::sum = 0;

class Solution {
public:
	//方法一：利用构造函数求解

	int Sum_Solution(int n) {
		Sum::clear();
		Sum *s = new Sum[n];
		delete[]s;
		s = NULL;

		return Sum::getSum();
	}
};

int main()
{
	Solution s;

	cout << s.Sum_Solution(10) << endl;

	system("pause");
	return 0;
}