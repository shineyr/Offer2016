/************************************************************************/
/* 
题目说明
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

样例输入
5
样例输出
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
接口说明
原型
void GetResult(int Num, char * pResult);
输入参数：
int Num：输入的正整数N
输出参数：
int * pResult：指向存放蛇形矩阵的字符串指针
指针指向的内存区域保证有效
返回值：
void

知识点	数组
运行时间限制	10M
内存限制	128
输入
输入正整数N（N不大于100）

输出
输出一个N行的蛇形矩阵。

样例输入	4
样例输出	1 3 6 10 2 5 9 4 8 7
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


void GetResult(int Num, int *pResult)
{
	vector<vector<int>> ret(Num, vector<int>(Num, 0));
	for (int i = 0, tmp = 1; i < Num; ++i)
	{
		for (int row = i, col = 0; col <= i &&row >= 0; --row, ++col)
		{
			ret[row][col] = tmp;
			++tmp;
		}		
	}//for

	for (int i = 0, k = 0; i < Num; ++i)
	{
		for (int j = 0; j < Num && ret[i][j] != 0; ++j)
		{
			pResult[k++] = ret[i][j];
		}//for
	}//for
}

int main()
{
	int N;
	cin >> N;
	int *ret = new int[(N*(N + 1)) / 2];
	GetResult(N, ret);
	
	/*初始行的起始位置*/
	int beg = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i; ++j)
		{
			if (j == N - i - 1)
			{
				cout << ret[beg + N - i - 1] <<endl;
			}
			else{
				cout << ret[beg + j] << " ";
			}//else			
		}//for
		/*更新下一行起始位置*/
		beg += (N - i);
	}//for
	
	system("pause");
	return 0;
}