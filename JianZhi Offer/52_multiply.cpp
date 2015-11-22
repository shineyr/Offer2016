/*
 * 面试题52：构建乘积数组
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.empty())
			return vector<int>();
		
		int n = A.size();
		//第一步，每个元素位置i求得A[0]*A[1]*...*A[i-1]
		vector<int> ret(n, 1);
		ret[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			ret[i] = ret[i - 1] * A[i - 1];
		}//for

		//第二步，ret[i] *= A[i+1]*...A[n-1]
		int tmp = 1;
		for (int j = n - 2; j >= 0; --j)
		{
			tmp *= A[j + 1];
			ret[j] *= tmp;
		}//for

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> A = { 1, 2, 3, 4, 5, 6 };
	vector<int> B = s.multiply(A);

	for (unsigned i = 0; i < B.size(); ++i)
	{
		cout << B[i] << "\t";
	}//for
	system("pause");
	return 0;
}