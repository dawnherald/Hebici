#include "stdio.h"
#include "stdlib.h"
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int mediam(int A[],int Left,int Right)
{
	int center = (Left + Right) / 2;
	if (A[Left] > A[center])
	{
		swap(&A[Left], &A[center]);
	}
	if(A[Left]>A[Right])
	{
		swap(&A[Left], &A[Right]);
	}
	if (A[center] > A[Right])
	{
		swap(&A[center], &A[Right]);
	}
	//����ŦԪ�ŵ��������һ�ˣ���Ӧ��Ϊright?
	swap(&A[center], &A[Right - 1]);
	return A[Right - 1];
}
void QSort(int A[], int Left, int Right)
{
	int i, j;
	//��ŦԪ
	int med= mediam(A,Left,Right);
	//
	i = Left, j = Right;
	for(;;)
	{
		while (A[++i]< med) {}
		while (A[--j] > med) {}
		if (i < j)
		{
			swap(&A[i], &A[j]);
		}
		else
		{
			break;
		}
	}
	swap(&A[i], &A[Right - 1]);//����ֵ����
	//��Ե���� i-1 �� i+1�綨
	QSort(A, Left, i - 1);
	QSort(A, i + 1, Right);
}
void QuicSort(int A[],int N)
{
	QSort(A, 0, N - 1);
}
void PrintArray(int A[],int N)
{
	for (int i = 0; i < N; i++)
	{
		printf(" %d ", A[i]);
	}
}
int main()
{
	int A[10] = { 10,99,156,123,42,13,45,89,4,1 };
	QuicSort(A, 10);
	PrintArray(A,10);
}