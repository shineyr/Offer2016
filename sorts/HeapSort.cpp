#include <iostream>
#include <time.h>
#include <cstdlib>
#define N 10
using namespace std;

//声明建大顶堆函数
void BuildMaxHeap(int * array);
//声明堆排序函数
void HeapSort(int * array);
//声明调整为大顶堆函数
void MaxHeapify(int * array, int n);
//返回堆的数据个数
int HeapSize;

void HeapSort(int * array)
{
	BuildMaxHeap(array);
	for (int i = N - 1; i >= 0; i--)//数组中下标从0  -  N-1
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		HeapSize -= 1;
		MaxHeapify(array, 1);//在堆中，堆顶元素下标从1开始
	}
}

void BuildMaxHeap(int * array)
{
	HeapSize = N;
	for (int i = N / 2; i >= 1; i--)//注意i的取值,堆的高度从1  -  N/2
	{
		MaxHeapify(array, i);
	}
}

void MaxHeapify(int * array, int temp)
{
	int largest;//以temp为顶点的子树的堆顶
	int l = 2 * temp;//求以temp为顶点的子树左儿子
	int r = 2 * temp + 1;//求以temp为顶点的子树右儿子

	if (l <= HeapSize && array[l - 1] > array[temp - 1])//首先判断左儿子是否存在，即l<=HeapSize
	{
		largest = l;
	}
	else{
		largest = temp;
	}

	if (r <= HeapSize && array[r - 1] > array[largest - 1])//首先判断右儿子是否存在，即r<=HeapSize
	{
		largest = r;
	}

	if (largest != temp)
	{
		int t = array[temp - 1];
		array[temp - 1] = array[largest - 1];
		array[largest - 1] = t;
		MaxHeapify(array, largest);//调整为大顶堆
	}
}

/*=====================================================================*/
/*堆排序非递归算法，T(n)=O(nlogn) S(n)=O(1)*/

//本函数调整A[idx]使得A[idx...n]构成大顶堆
void HeapAdjust(int *A, int idx, int n)
{
	int tmp = A[idx];
	for (int j = 2 * idx + 1; j < n; j=2*j+1)
	{
		if (j < n - 1 && A[j] < A[j + 1])
		{
			++j;
		}//if

		if(tmp >= A[j])
			break;

		A[idx] = A[j];
		idx = j;
	}//for
	A[idx] = tmp;
}

int *HeapSort2(int *A, int n)
{
	if (n <= 0)
		return A;

	/*从最后一个根节点开始*/
	for (int i = (n-1) / 2; i >= 0; --i)
	{
		HeapAdjust(A, i, n-1);
	}//for

	for (int i = n - 1; i > 0; --i)
	{
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;

		HeapAdjust(A, 0, i - 1);
	}

	return A;
}

//int main()
//{
//	//声明一个待排序数组
//	int array[N];
//	//设置随机化种子，避免每次产生相同的随机数 
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		array[i] = rand() % 101;//数组赋值使用随机函数产生1-100之间的随机数   
//	}
//	cout << "排序前：" << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << array[j] << "  ";
//	}
//	cout << endl << "排序后：" << endl;
//	//调用堆排序函数对该数组进行排序   
//	HeapSort(array);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//
//	/*非递归堆排序*/
//
//	system("pause");
//	//设置随机化种子，避免每次产生相同的随机数 
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		array[i] = rand() % 101;//数组赋值使用随机函数产生1-100之间的随机数   
//	}
//	cout << "排序前：" << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << array[j] << "  ";
//	}
//	cout << endl << "排序后：" << endl;
//	//调用堆排序函数对该数组进行排序   
//	HeapSort2(array,N);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//	return 0;
//}


