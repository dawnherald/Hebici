#ifndef _BinHeap_H
struct HeapStack;
typedef struct HeapStack* PriorityQueue;
PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue P);
void MakeEmpty(PriorityQueue P);
void Insert(int x, PriorityQueue P);
int  DeleteMin(PriorityQueue P);
int  FindMin(PriorityQueue P);
int  IsEmpty(PriorityQueue P);
int  IsFull(PriorityQueue P);
#endif // !_BinHeap_H

