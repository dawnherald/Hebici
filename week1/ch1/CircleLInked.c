#include "CircleLinked.h"
#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// 循环列表 解决约瑟夫问题
/// </summary>
struct Node
{
	int size;
	int Num;
	struct Node* Next;
	struct Node* Head;
};
void DeleteNode(List L)
{
	List temp;
	temp = L;
	while (temp->Next!=L)
	{
		temp = temp->Next;
	}
	temp->Next = L->Next;
	free(L);
}
void Josephus(List L, int nums)
{
	struct Node* temp;
	temp = L->Next;
	int j = temp->size;
	while (j!= 1)
	{
		
		for (int i = 0; i < nums; i++)
		{
			temp = temp->Next;
		}
		DeleteNode(temp);
		j--;
	}

}
List creatList()
{
	List temp;
	temp = malloc(sizeof(struct Node));
	temp->Num = 0;
	temp->Next = temp;
	temp->Head = temp;
	temp->size = 0;

	return temp;
}
//头插入
void insert(List P,int x)
{
	List temp;
	temp = malloc(sizeof(struct Node));
	//构成循环链表
	temp->Next = P->Head->Next;//并没有形成环形链表 依然是 第一个 为 NULL
	P->Next = temp;
	temp->Num = x;
	(P->size)++;
}
//修补insert缺陷 形成环形链表
void  setCircle(List P)
{
	struct Node* temp;
	temp = P->Next;
	int i = P->size;
	while (i>1)
	{
		temp = temp->Next;
		i--;
	}
	temp->Next = P->Head->Next;
}
void PrintList(List P)
{
	struct Node* temp;
	temp = P->Next;
	int i = P->size;
	while (i)
	{
		printf("%d  ", temp->Num);
		temp = temp->Next;
		i--;
	}

}
int main()
{
	struct Node* N;
	N = creatList();
	insert(N, 1);
	insert(N, 2);
	setCircle(N);
	PrintList(N);
	Josephus(N, 1);
	PrintList(N);
}