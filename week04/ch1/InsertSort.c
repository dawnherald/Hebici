#include "stdio.h"
#include "stdlib.h"
int* RandIntArray(int Size,int left,int right)
{
	int i = 0;
	int* temp = calloc(Size,sizeof(int));
	while ((Size--) > 0)
	{
		temp[i] = rand() % right - left;
		i++;
	}
	return temp;
}
void Swap(int* AArray, int* BArray)
{
	printf("%d", AArray);
	int* temp = malloc(sizeof(int));
	temp[0] = *(AArray);
	*(AArray) = *(BArray);
	*(BArray) = temp[0];
	
}
void InsertSort(int *Array , int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j > 0 && j < length; j--)
		{
			int temp = Array[j];
			if (Array[j] < Array[j - 1])
			{
				Array[j] = Array[j - 1];
				Array[j - 1] = temp;
			}
		}
	}
}
void printArray(int* Array, int length)
{

	for (int i = 0; i < length; i++)
	{
		printf("%d ",Array[i]);
	}
}
//对比树上的实现方法
void Insertion(int A[], int N)
{
	int j, P;
	int Tmp;
	for (P = 1; P < N; P++)
	{
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
	

}
int main()
{
	int i = 10;
	int* A =calloc(i,sizeof(int)) ;
	A = RandIntArray(10, 0, 100);
	printArray(A, 10);
	printf("\n");
	InsertSort(A, 10);
	printf("\n");
	printArray(A,10);
}