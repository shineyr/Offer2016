/*****************************************************************************************************
描述	
计算最少出列多少位同学，使得剩下的同学排成合唱队形
说明：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。 
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   
则他们的身高满足存在i（1<=i<=K）使得Ti<T2<......<Ti-1<Ti>Ti+1>......>TK。 
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。 

知识点	循环
运行时间限制	0M
内存限制	0
输入	
整数N
一行整数，空格隔开，N位同学身高

输出	
最少需要几位同学出列
样例输入	8 186 186 150 200 160 130 197 200
样例输出	4
**************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void GetLeftList(const int *vh, int n , int *lv);
void GetRightList(const int *vh, int n ,int *rv);
int main()
{
	int n , height;
	//其中vh存储整体身高序列，lv存储左起最长上升子序列，rv存储右起最长上升子序列
	int vh[500] = {0}, lv[500] = {0}, rv[500] = {0};
	cin >> n;
	//如果人数小于等于2个，那么需要0人出队
	if (n <= 2)
		cout << 0 << endl;
	else{
		for (int i = 0; i < n; i++)
		{
			cin >> height;
			vh[i] = height;
		}//for

		//求出左起升序序列
		GetLeftList(vh, n , lv);
		GetRightList(vh, n , rv);

		int tmp = 0, index;
		for (int i = 0; i < n; i++)
		if (tmp < lv[i] + rv[i])
		{
			tmp = lv[i] + rv[i];
			index = i;
		}

		cout << n - lv[index] - rv[index] + 1 << endl;
	}//else
	system("pause");
	return 0;
}

void GetLeftList(const int *vh, int n, int *lv)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		lv[i] = 1;
		for (j = 0; j < i; j++)
		if (vh[i]>vh[j] && lv[i] < (lv[j] + 1))
			lv[i] = lv[j] + 1;
	}
}

void GetRightList(const int *vh, int n, int *rv)
{
	int i, j, k;
	for (i = n - 1; i >= 0; i--)
	{
		rv[i] = 1;
		for (j = n - 1; j >i; j--)
		if (vh[i]>vh[j] && rv[i] < (rv[j] + 1))
			rv[i] = rv[j] + 1;
	}
}