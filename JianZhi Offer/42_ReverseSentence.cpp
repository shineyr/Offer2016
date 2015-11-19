/*
 * 题目: 面试题42 反转单词顺序
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 * 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
 * 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	//两次反转的方法
	string ReverseSentence(string str) {
		if (str.empty())
			return str;
		//第一步，反转整个字符串
		reverse(str.begin(), str.end());

		//第二步，反转每个单词
		string::iterator iter,beg = str.begin();

		for (iter = str.begin(); iter != str.end(); ++iter)
		{
			if (*iter == ' ')
			{
				reverse(beg, iter);
				beg = iter + 1;
			}//if
		}//for
		reverse(beg, str.end());
		return str;
	}
};

int main()
{
	Solution s;

	string str = "I am a student.";
	str = s.ReverseSentence(str);
	cout << str << endl;

	system("pause");
	return 0;
}