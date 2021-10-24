#include "stdio.h"
#include "stdlib.h"
int* RandIntArray(int Size, int left, int right)
{
	int i = 0;
	int* temp = calloc(Size, sizeof(int));
	while ((Size--) > 0)
	{
		temp[i] = rand() % right - left;
		i++;
	}
	return temp;
}
void ShellSort(int* Array, int Length)
{
	int gap, temp, j;
	//增量缩小排序
	//gap 的选取值会影响算法快慢
	for (gap = Length /2;gap>=1;gap/=2 )
		//将gap——gap+n上的元素放到 i - N*gap上。
		for (int i = gap; i < Length; i++)
		{
			temp = Array[i];
			for ( j = i; i > 0; j -= gap)
			{
				if (temp < Array[j-gap])
				{
					Array[j] = Array[j - gap];
				}
				else
				{
					break;
				}
			}
			Array[j] = temp;
		}
}
void printArray(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}
int main()
{
	int i = 10;
	int* A = calloc(i, sizeof(int));
	A = RandIntArray(10, 0, 100);
	printArray(A, 10);
	printf("\n");
	ShellSort(A, 10);
	printf("\n");
	printArray(A, 10);
}