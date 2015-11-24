/*
 * 8.1.1 实现一个算法，确定一个字符串中的所有字符是否全都不同，不允许使用额外的数据结构。
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	/*利用哈希的思想，保存每个字符,ASCII字符集只有256个不同的字符，最大申请空间仅仅为 256B*/
	bool isUniqueChars(const string &str)
	{
		if (str.empty())
			return true;
		else if (str.length() > 256)
			return false;

		int MAX_SIZE = 256;
		vector<int> exist(MAX_SIZE, 0);
	
		int len = str.length();
		for (int i = 0; i < len; ++i)
		{
			if (exist[str[i]] == 1)
				return false;
			exist[str[i]] = 1;
		}
		return true;
	}
};

/*
 * 方法（2）：将字符串中的每一个字符与其余字符进行比较，时间复杂度T(n)=O(n^2)，空间复杂度为S(n)=O(1)
 * 方法（3）：若允许修改字符串内容，在O(nlogn)时间内对字符串排序，然后线性检查其中有无相邻字符完全相同；注：很多排序算法会占用额外空间！
 */
int main()
{
	Solution s;
	cout << s.isUniqueChars("very") << endl;
	cout << s.isUniqueChars("good") << endl;

	system("pause");
	return 0;
}