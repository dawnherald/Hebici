#include "HeapStack.h"
#include "stdio.h"
#include "stdlib.h"
#define  Mindata -999;
typedef struct HeapStack* PriorityQueue;
struct HeapStack
{
	int Capacity;
	int Size;
	int* Elements;
};
int  FindMin(PriorityQueue P)
{
	return P->Elements[1];
}
int  IsEmpty(PriorityQueue P)
{
	return P->Size == 0;
}
int  IsFull(PriorityQueue P);
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue temp;
	if (MaxElements < 10)
	{
		printf("�����С����");
		exit(0);
	}
	temp = malloc(sizeof(struct HeapStack));
	if (temp == NULL)
	{
		printf("�������Сʧ��");
		exit(0);
	}
	temp->Elements = calloc(MaxElements + 1, sizeof(int));
	temp->Capacity = MaxElements;
	temp->Size = 0;
	temp->Elements[0] = Mindata;
	return temp;
}
void Destory(PriorityQueue P);
void MakeEmpty(PriorityQueue P);
void Insert(int x, PriorityQueue P)
{
	int i=0;
	if (IsFull(P))
	{
		printf("��������");
		exit(0);
	}
	for (int i = ++(P->Size); P->Elements[i / 2] > x; i /= 2)
	{
		P->Elements[i] = P->Elements[i / 2];
	}
	P->Elements[i] = x;
}
int  DeleteMin(PriorityQueue P)
{
	int LastElment = P->Elements[P->Size--];
	int i, child;
	int MinElement = P->Elements[1];
	for (i = 1; i * 2 < P->Size; i = child)
	{
		child = i * 2;
		if (child != P->Size && P->Elements[child + 1] < P->Elements[child])
		{
			//�����������ƶ���������,����Сֵ��һ��
			child++;
		}
		if (LastElment > P->Elements[child])
		{
			P->Elements[i] = P->Elements[child];
		}
		else
		{//��ֹ���
			break;
		}
	}
	P->Elements[i] = LastElment;
	return MinElement;
}

int main()
{
	PriorityQueue Q = Initialize(25);
	printf("��������\n");
	for (int i = 0; i < 10; i++)
	{
		Insert(i, Q);
	}

}