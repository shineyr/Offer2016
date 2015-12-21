/*
* 面试题8.9.6 实现一种算法，打印n对括号的全部有效组合。
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
	/*方法一，递归解决，已得到n-1对括号的合法组合，遍历每一个合法组合
	 * （1）在第一个左括号之后插入一对括号
	 * （2）在第二个左括号之后插入一对括号
	 * （3）在字符串开头插入一对括号
	 */
	vector<string> generateParens(int n)
	{
		unordered_set<string> us;
		if (0 == n)
			us.insert("");
		else
		{
			vector<string> tmp = generateParens(n - 1);
			auto iter = tmp.begin();
			for (; iter != tmp.end(); ++iter)
			{
				/*查找n-1个左括号*/
				int len = (*iter).length();
				for (int i = 0; i < len; ++i)
				{
					if ((*iter)[i] == '(')
					{
						/*在i之后添加一对括号*/
						string str = (*iter).substr(0, i + 1) + "()" + (*iter).substr(i + 1, len - i - 1);
						us.insert(str);
					}//if
				}//for
				/*在字符串开头插入（）*/
				string str = "()" + (*iter);
				us.insert(str);
			}//for	
		}//else
		return vector<string>(us.begin(), us.end());
	}
};

int main()
{
	Solution s;
	vector<string> ret = s.generateParens(3);
	
	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for

	system("pause");
	return 0;
}