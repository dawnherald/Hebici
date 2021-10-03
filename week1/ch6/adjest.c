#include "stdio.h"
#include "stdlib.h"
void swap(int a[], int i, int b)
{
	int temp = a[i];
	a[i] = a[b];
	a[b] = a[temp];
}
void selfadject(int a[],int nums,int size)
{
	for (int i = 0; i < size; i++)
	{
		if (nums = a[i])
		{
			swap(a, 0, i);
		}
	}

}

void randarray(int a[],int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 50 - 0;
	}
}
int main()
{
	const int size = 100;
	int a[100] = { 0 };
	randarray(a, 100);
	selfadject(a, 10, 100);
	printf("%d", a[0]);
}