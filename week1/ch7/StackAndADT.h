#pragma once
#ifndef  _Stack_h
struct Node;
typedef struct Node *PtrToNode;// Node ����ָ��ı���
typedef PtrToNode Stack;//��ַ�ı����������֣���

int   IsEmpty(Stack S);
Stack CreatStact(void);
void  DisposeStack(Stack S);
void  MakeEmpty(Stack S);
void  Push(int x,Stack S);
int   Top(Stack S);
void  Pop(Stack S);
#endif // ! _Stack_h
