/*
* 面试题8.9.5 编写一个方法确定某字符串的所有排列组合；
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> permutations(string s)
	{
		vector<string> ret = vector<string>();
		if (s.empty())
			return ret;
		int len = s.length();
		if (len == 1)
		{
			ret.push_back(s);
		}//else
		else{
			/*得到除尾字母外的子串的全部排列*/
			vector<string> tmp = permutations(s.substr(0, len - 1));

			auto iter = tmp.begin();
			for (; iter != tmp.end(); ++iter)
			{
				/*每个子串的排列长度为len-1,它有len个空可供尾字母插入*/
				for (int j = 0; j <= len - 1; ++j)
				{
					/*求得插入每个空隙处得到的全串的一个排列*/
					string str = (*iter).substr(0, j) + s[len - 1] + (*iter).substr(j, len - j);
					ret.push_back(str);
				}//for
			}//for
		}//else
		return ret;	
	}
};

int main()
{
	Solution s;
	vector<string> ret = s.permutations("abcd");
	
	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for

	system("pause");
	return 0;
}