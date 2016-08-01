/*面试题9.3 N!中0的个数*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*普通解求1~N中含有多少个因子5*/
int zeroNum1(int n)
{
	int count = 0;
	for (int i = 5; i <= n; i += 5)
	{
		int tmp = i;
		while (tmp % 5 == 0)
		{
			++count;
			tmp /= 5;
		}//while
	}//for
	return count;
}

/*最优解 count = n/5 + n/(5^2) + n/5^3 + ... + n/5^i  i一直增长，知道5^i > N*/
int zeroNum2(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}//while
	return count;
}
//int main()
//{
//	cout << zeroNum1(6) << endl;
//	cout << zeroNum2(6) << endl;
//
//	system("pause");
//	return 0;
//}