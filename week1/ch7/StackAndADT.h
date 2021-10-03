#pragma once
#ifndef  _Stack_h
struct Node;
typedef struct Node *PtrToNode;// Node 类型指针的别名
typedef PtrToNode Stack;//地址的别名？？区分！？

int   IsEmpty(Stack S);
Stack CreatStact(void);
void  DisposeStack(Stack S);
void  MakeEmpty(Stack S);
void  Push(int x,Stack S);
int   Top(Stack S);
void  Pop(Stack S);
#endif // ! _Stack_h
