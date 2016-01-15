/*

生成窗口最大值数组
有一个整型数组arr和一个大小为w的窗口，从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时，生成的窗口最大值数组为[5,5,5,4,6,7]
如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。
*/

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>

using namespace std;

vector<int> getMaxWindow(vector<int> arr, int w)
{
	if (arr.empty() || w < 1 || arr.size() < w)
		return vector<int>();

	deque<int> qmax;
	vector<int> ret(arr.size() - w + 1, 0);
	int idx = 0 , len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		while (!qmax.empty() && arr[qmax.back()] <= arr[i])
		{
			qmax.pop_back();
		}//while
		qmax.push_back(i);
		if (qmax.front() == i - w)
		{
			qmax.pop_front();
		}//if

		if (i >= w - 1)
		{
			ret[idx++] = arr[qmax.front()];
		}//if
	}//for
	return ret;
}

//int main()
//{
//	vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7 };
//	vector<int> maxWindow = getMaxWindow(v, 3);
//
//	for (unsigned i = 0; i < maxWindow.size(); ++i)
//	{
//		cout << maxWindow[i] << "\t";
//	}//for
//	cout << endl;
//
//	system("pause");
//	return 0;
//}