/************************************************************************/
/*
描述
输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数
知识点	循环
运行时间限制	0M
内存限制	0
输入
一个正整数N。(N不大于30000)
输出
不大于N的与7有关的数字个数，例如输入20，与7有关的数字包括7,14,17.
样例输入	20
样例输出	3                                                                    
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAX = 30000;

bool isConnect(int num)
{
	if (num <7 || num > MAX)
		return false;
	else if (num % 7 == 0)
		return true;
	else{
		while (num > 0)
		{
			if (num % 10 == 7)
				return true;
			else
				num /= 10;
		}//while
		return false;
	}

}
int main()
{
	int num;
	cin >> num;
	int count = 0;
	for (int i = 7; i <= num;++i)
		if (isConnect(i))
			++count;
	cout << count << endl;
	system("pause");
	return 0;
}