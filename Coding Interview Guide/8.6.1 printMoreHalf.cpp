/*
题目：8.5.1 在数组中找到出现次数大于一般的数；
要求：给定一个整型数组arr，打印其中出现次数大于一半的数，
如果没有这样的数，打印提示信息；	
*/

#include <iostream>
#include <cstdlib>

using namespace std;
void printMoreHalf(int arr[] , int N)
{
	if(N <= 0)
		cout<<"The array is empty!"<<endl;
	int cand = arr[N-1],times=0;
	for(int i=0;i<N;++i)
	{
		if (0 == times)
		{
			cand = arr[i];
			times = 1;
		}
		else if(arr[i] == cand)
			++times;
		else
			--times;
	}//for
	
	int count = 0;
	for(int i=0;i<N;++i)
	{
		if(arr[i] == cand)
			++count;
	}//for
	if(count <= N/2)
		cout<<"There is not number!"<<endl;
	else
		cout<<cand<<endl;
}

//int main()
//{
//	int arr[] = {1,2,3,4,4,4,4,4,5};
//	
//	printMoreHalf(arr,9);
//	
//	system("pause");
//	return 0;
//}