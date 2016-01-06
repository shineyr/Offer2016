/************************************************************************/
/* 
描述
有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。现在，修改过的那个单词死于字母表的下面，如下所示：
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。
请实现下述接口，通过指定的密匙和明文得到密文。
详细描述：
接口说明
原型：
voidencrypt(char * key,char * data,char * encrypt);
输入参数：
char * key：密匙
char * data：明文
输出参数：
char * encrypt：密文
返回值：
void

知识点	字符串
运行时间限制	10M
内存限制	128
输入
先输入key和要加密的字符串
输出
返回加密后的字符串
样例输入	nihao ni
样例输出	le
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

void encrypt(char *key, char *data, char *encrypt)
{
	unordered_set<int> levels;
	int idx = 0;
	while (levels.size() < 26 && key[idx] != '\0')
	{
		/*以大写的方式存储秘钥*/
		if (key[idx] >= 'a' && key[idx] <= 'z')
		{
			key[idx] = key[idx] - 'a' + 'A';
		}//if

		if (levels.find(key[idx]) != levels.end())
		{
			++idx;
			continue;
		}
		else
		{
			levels.insert(key[idx]);
			++idx;
		}//else
	}//while

	idx = 0;
	while (levels.size() < 26 && idx < 26)
	{
		if (levels.find('A' + idx) != levels.end() || levels.find('a' + idx) != levels.end())
		{
			++idx;
			continue;
		}//if
		else
		{
			levels.insert('A' + idx);
			++idx;
		}//else
	}//while

	vector<char> tmpLevels(levels.begin(), levels.end());
	for (int i = 0; data[i] != '\0'; ++i)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			encrypt[i] = tmpLevels[data[i] - 'A'];
		}
		else{
			encrypt[i] = tmpLevels[data[i] - 'a'] - 'A' + 'a';
		}//else
	}//for
	encrypt[strlen(data)] = '\0';
}

//int main()
//{
//	char key[10000], data[10000], ret[10000];
//	
//	cin >> key;
//	cin >> data;
//	
//	/*加密*/
//	encrypt(key, data, ret);
//
//	cout << ret << endl;
//
//	system("pause");
//	return 0;
//}