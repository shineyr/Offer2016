/*
* 面试题8.9.6 实现一种算法，打印n对括号的全部有效组合。
*/

#include <iostream>
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
	vector<string> generateParens1(int n)
	{
		unordered_set<string> us;
		if (0 == n)
			us.insert("");
		else
		{
			vector<string> tmp = generateParens1(n - 1);
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
	/*
	* 方法二：从头开始构造字符串，从而避免出现重复。在这个过程中，逐一加入左括号或者右括号，只要字符串依然有效！
	* 判断有效：（1）只要左括号还没用完，就可以插入左括号；（2）只有合法，也就是右括号个数小于等于左括号就可以插入右括号。
	*/
	vector<string> generateParens(int n)
	{
		vector<string> ret;
		string str(2*n,' ');
		addParen(ret, n, n, str, 0);

		return ret;
	}
	void addParen(vector<string> &ret, int leftRem, int rightRem, string str, int count)
	{
		//如果可添加左括号数小于0 或者可添加右括号数小于左括号说明目前构造的字符串非法
		if (leftRem < 0 || rightRem < leftRem)
			return;

		/*无括号可添加，得到一个合法组合*/
		if (leftRem == 0 && rightRem == 0)
		{
			ret.push_back(str);
		}//else
		else{
			/*还有左括号可用，加入一个左括号*/
			if (leftRem > 0)
			{
				str[count] = '(';
				addParen(ret, leftRem - 1, rightRem, str, count + 1);
			}//if
			/*若字符串有效，加入一个右括号*/
			if (rightRem > leftRem)
			{
				str[count] = ')';
				addParen(ret, leftRem, rightRem - 1, str, count + 1);
			}//if
		}//else
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