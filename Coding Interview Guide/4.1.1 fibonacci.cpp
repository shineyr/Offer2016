/*
4.1.1 斐波那契数列问题的递归和动态规划

题目：
给定整数N，返回斐波那契数列的第N项；
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*暴力递归 T(n)=O(2^n)*/
int fibonacci_1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}//elif
	else
	{
		return fibonacci_1(n - 1) + fibonacci_1(n - 2);
	}//else
}

/*空间换时间 T(n)=O(n)*/
int fibonacci_2(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n == 1 || n == 2)
	{
		return 1;
	}//elif
	else{
		int pre = 1, res = 1;
		for (int i = 3; i <= n; ++i)
		{
			int tmp = res;
			res = pre + res;
			pre = tmp;
		}//for
		return res;
	}//else
}

/*矩阵相乘算法*/
vector<vector<int>> multiMatrix(vector<vector<int>> a, vector<vector<int>> b)
{
	if (a.empty() || b.empty())
		return vector<vector<int>>();

	/*保存矩阵相乘结果*/
	vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b[0].size(); ++j)
		{
			for (int k = 0; k < b.size(); ++k)
			{
				res[i][j] += a[i][k] * b[k][j];
			}//for	
		}//for
	}//for

	return res;
}

/*求矩阵的幂的算法*/
vector<vector<int>> matrixPower(vector<vector<int>> matrix, int p)
{
	if (matrix.empty())
		return matrix;

	int row = matrix.size(), col = matrix[0].size();
	vector<vector<int>> res(row, vector<int>(col, 0));
	for (unsigned int i = 0; i < res.size(); ++i)
	{
		res[i][i] = 1;
	}//for

	vector<vector<int>> tmp = matrix;
	for (; p != 0; p >>= 1)
	{
		if ((p & 1) != 0)
		{
			res = multiMatrix(res, tmp);
		}//if
		tmp = multiMatrix(tmp, tmp);
	}//for
	return res;
}
/*矩阵乘法的形式，T(n)=O(logn)*/
int fibonacci_3(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n == 1 || n == 2)
	{
		return 1;
	}//elif
	else{
		vector<vector<int>> base = { { 1, 1 }, { 1, 0 } };
		vector<vector<int>> res = matrixPower(base, n - 2);
		return res[0][0] + res[1][0];
	}//else
}

int main()
{
	cout << fibonacci_1(5) << endl;
	cout << fibonacci_2(5) << endl;
	cout << fibonacci_3(5) << endl;

	system("pause");
	return 0;
}