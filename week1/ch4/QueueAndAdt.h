#pragma once
#ifndef  _Queue_h
struct QueueRecord;
typedef struct QueueRecord* Queue;// Node 类型指针的别名
int   IsEmpty(Queue S);
int   IsFull(Queue S);
Queue CreatQueue(int MaxElements);
void  DisposeQueue(Queue S);
void  MakeEmpty(Queue S);
void  Enqueue(int x, Queue S);
int   Front(Queue Q);
void  Dequeue(Queue Q);
int   FrontAndqueue(Queue Q);
#endif // ! _Stack_h
