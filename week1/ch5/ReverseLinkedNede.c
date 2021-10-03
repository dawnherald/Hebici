#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// 复杂度为N的反转链表
/// </summary>
struct  Node
{
	int nums;
	struct Node* Next;
	struct Node* Head;

};
typedef struct Node* List;
//头插法
List creat()
{
	List temp;
	temp = malloc(sizeof(struct Node));
	temp->Next = NULL;
	temp->nums = 0;
	temp->Head = temp;
	return temp;

}
void insertHead(List L,int x)
{
	List temp;
	temp = malloc(sizeof(struct Node));
	//构成循环链表
	temp->Next = L->Next;
	temp->nums = x;
	L->Next = temp; 
	printf("%d", temp->nums);
}
//尾插法
void insertLst(List L,int x)
{/*
	List temp;
	temp = malloc(sizeof(struct Node));
	temp->Next = NULL;
	temp->nums = x;
	L->Next = temp;
	L = temp;
	printf("%d ", x);*/
	List s,temp;
	temp = malloc(sizeof(struct Node));
	s = malloc(sizeof(struct Node));
	temp = L;
	s->nums = x;
	temp->Next = s;
	temp = s;
	temp->Next = NULL;
}
//反转思路： 读取尾插法的数值 通过头插法赋值一个链表
void ReverseLinked(List last)
{
	struct Node* temp;
	//读取尾插法的头结点
	temp = last->Next;
	//头结点怎么保持不变
	struct Node* res;
	res = creat();
	while (temp!=NULL)
	{
		insertHead(res,temp->nums);
		temp = temp->Next;
	}
}
int main()
{
	struct Node * N2,*temp;
	N2 = creat();
	temp = N2->Head;
	for (int i = 0; i < 10; i++)
	{
		insertLst(N2, i);
	}
	ReverseLinked(temp);
}