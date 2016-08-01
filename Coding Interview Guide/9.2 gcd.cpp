/*面试题9.2 一行代码求两个数的最大公约数*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*递归*/
int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n,m%n);
}

/*非递归*/
int gcd2(int m, int n)
{
	while (n)
	{
		m = n;
		n = m%n;
	}//while

	return m;
}

int main()
{
	cout << gcd(6, 0) << endl;
	cout << gcd2(6, 0) << endl;

	system("pause");
	return 0;
}
}