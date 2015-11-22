/*
 * 面试题51：数组中重复的数字
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
 * 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
*/

#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	//方法一：采用哈希的思想，利用STL库的unordered_set
	bool duplicate1(int numbers[], int length, int* duplication) {
		if (length <= 0)
			return false;

		unordered_set<int> us;
		for (int i = 0; i < length; ++i)
		{
			if (us.count(numbers[i]) <= 0)
			{
				us.insert(numbers[i]);
				continue;
			}
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}//for
		return false;
	}

	//方法二：原地排序法
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 0)
			return false;

		for (int i = 0; i < length; ++i)
		{
			if (numbers[i] < 0 || numbers[i] >= length)
				return false;
		}//for

		for (int i = 0; i < length; ++i)
		{
			//不在对应位置则交换
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}//while
		}//for
		return false;

	}
};

int main()
{
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	Solution s;
	int duplication = 0;

	if(s.duplicate(numbers, 7, &duplication))
		cout << duplication << endl;

	system("pause");
	return 0;

}
