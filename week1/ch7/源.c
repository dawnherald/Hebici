#include <stdio.h>
#include <stdlib.h>
#include "StackAndADT.h"
struct  Node
{
	int Element;
	PtrToNode Next;
};
int   IsEmpty(Stack S)
{
	return S->Next == NULL;
}
Stack CreatStact(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)
	{
		printf("Out Of Space!");
	}
	S->Next = NULL;
	return S;

}
void  DisposeStack(Stack S)
{
	

}
void  MakeEmpty(Stack S);
//ѹ��ջ�� ����һ������ʱ������ͨ��creat��ý��
void  Push(int x, Stack S)
{
	PtrToNode P;
	P = malloc(sizeof(struct Node));
	if (S == NULL)
	{
		printf("Get space filed");
	}
	P->Element = x;
	P->Next = S->Next;//P.next = NULL
	S->Next = P;//��֤S�����ڱ�ͷ

}
int   Top(Stack S)
{
	if (S == NULL)
	{
		printf("No data in Stack");
	}
	else
	{
		return S->Next->Element;//����������ջ��ͷ���
	}
}
void  Pop(Stack S)
{
	PtrToNode P;
	if (S == NULL)
	{
		printf("No data in Stack");
	}
	else
	{
		P = S->Next->Next;
		printf("%d",S->Next->Element);
		free(S->Next);
		S->Next = P;
		/*
		* ����ʵ��
		* P = S.NExtl
		* S.next =s.net.next
		* free(0)
		*/
	}
}
int main()
{
	struct Node *p1;
	p1 = CreatStact();
	printf(p1);
	Push(10,p1);
	Pop(p1);
	

	
}