#include "stdlib.h"
#include "stdio.h"
#include "QueueAndAdt.h"
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int* Array;

};
int   IsEmpty(Queue S)
{
	return S->Capacity == 0;
}
int   IsFull(Queue S)
{
	return ((S->Rear + 1) % S->Capacity == S->Front);
}
Queue CreatQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements)
	{
		printf("初始化数组大小不正确");
	}
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
	{
		printf("get space filed");
	}
	Q->Array = calloc(MaxElements, sizeof(int));
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
	return Q;
}
void  DisposeQueue(Queue S);
void  MakeEmpty(Queue S)
{
	S->Size  = 0;
	S->Front = 0;
	S->Rear = S->Front;
}
//书中提供的方法 ：
static int Succ(int Value,Queue Q)
{
	if (++Value == Q->Capacity)//局部参数 会导致输出的Value自己啊
		Value = 0;
	return Value;
}
void  Enqueue(int x, Queue S)
{
	if (IsFull(S))
	{
		printf("out of memory");
	}
	else
	{
		S->Size++;
		S->Rear = Succ(S->Rear, S);
		S->Array[S->Rear] = x;
	}
}
int   Front(Queue Q)
{
	return Q->Array[Q->Front];
}
//出列
void  Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("out of memory");
	}
	else
	{
		Q->Size--;
		Q->Array[Q->Front] = 0;
		Q->Front = Succ(Q->Front,Q);
	}
}
int   FrontAndqueue(Queue Q);
int main()
{

}