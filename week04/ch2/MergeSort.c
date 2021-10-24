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
void Merge(int* A, int left, int mid, int right)
{
	/*int* Temp = calloc(right + 1, sizeof(int));
	int rightlops = mid + 1;
	//Temp的输入的下标如何确定？
	int i = 0;
	//
	printf("%d",rightlops);
	while (left<=mid&&rightlops<=right)
	{
		if (Array[left] < Array[rightlops])
		{
			Temp[i++] = Array[left++];

		}
		else if (Array[left] > Array[rightlops])
		{
			Temp[i++] = Array[rightlops++];

		}
	}//当有一个数组遍历结束
	while (left <= mid)
	{
		Temp[i++] = Array[left++];
	}
	while (rightlops <= right)
	{
		Temp[i++] = Array[rightlops++];
	}
	for (int j = i; j >= 0; j--)
	{
		Array[j] = Temp[j];
	}*/
	int* Temp = calloc(right + 1, sizeof(int));
	int LeftEnd = mid - 1;
	int TmpPos = left;
	int ElementsNum = right - left + 1;
	while (TmpPos <= LeftEnd && mid <= right)
	{
		if (A[TmpPos] <= A[mid])
			Temp[TmpPos++] = A[left++];
		else
			Temp[TmpPos++] = A[mid++];
	}
	while (left <= LeftEnd)
	{
		Temp[TmpPos++] = A[left++];
	}
	while (mid<=right)
	{
		Temp[TmpPos++] = A[mid++];
	}
	for (int i = 0; i < ElementsNum; i++, right--)
	{
		A[right] = Temp[right];
	}
}
void MergeSort(int* Array,int left, int right)
{
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	MergeSort(Array, left, mid );
	MergeSort(Array,mid + 1, right);
	Merge(Array,left,mid+1,right);
}
void PrintArray(int *Array,int N)
{
	for (int i = 0; i < N; i++)
	{
		printf(" %d ",Array[i]);
	}
}
int main()
{
	int* temp = RandIntArray(10, 0, 100); 
	PrintArray(temp, 10);
	MergeSort(temp, 0, 9);
		PrintArray(temp, 10);
	
}