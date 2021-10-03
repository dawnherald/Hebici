#include <stdio.h>
#include <stdlib.h>
#include "NodeAndAdt.h"
struct  Node
{
	int Element;
	Position Next;

};
int IsEmpty(List L)
{
	return L->Next == NULL;
}
//判断链表L的当前位置P是否为末尾
int IsLast(Position P, List l)
{
	return P->Next == NULL;
}
Position Find(int  x, List l)
{
	Position P = l->Next;
	while (P->Next != NULL && P->Element != x)
	{
		P = P->Next;
	}
	return P;
}
Position FindPrevious(int x, List L)
{

   Position P = L;//可以typedf NOde 别名List作为链表头
	while (P->Next != NULL && P->Element != x)
	{
		P = P->Next;
	}
	return P;
}
void Delete(int x, List L)
{
	Position P, temp;
	P = FindPrevious(x, L);
	if (!IsLast(P,L))
	{
		temp = P->Next;
		P->Next = temp->Next;
		free(temp);
	}

}
//书中实现插入类型并没有确定L和P的位置 
//所以可以使用FindPrevious 找到函数末尾  但是当数值重复时，会改写不争取的位置
void Insert(int x, List L, Position P)
{
	Position temp;
	temp = malloc(sizeof(struct  Node));
	if (temp == NULL)
	{
		FatalError("out of memory");
	}
	temp->Element = x;
	temp->Next = P->Next;
	P->Next = temp;
}
//删除表的正确方法
void DeleteList(List L)
{
	Position P, temp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		temp = P->Next;
		free(P);
		P = temp;
	}
}
/// <summary>
/// 3.2 打印链表
/// </summary>
/// <param name="L"></param>
/// <param name="P"></param>升序链表
void PrintLots(List L, List P)
{
	while (P->Next!=NULL)
	{
		int A = (P->Next->Element);
		int B = 1;
		while (L->Next!=NULL)
		{
			if (A != B)
			{
				B++;
				L->Next = L->Next->Next;
			}
			else
			{
				B++;
				printf("输出第%d个元素为:", B, L->Next->Element);
			}
		}
	}
}
/// <summary>
/// 3.3 单链表 
/// 找到下标为x的链表结点
/// </summary>
void SwapNode(List L,int x)
{
	Position prvP = FindPrevious(x, L);
	Position P =Find(x, L);
	Position NexP = P->Next;
	prvP->Next = NexP;
	P->Next = NexP->Next;
	NexP->Next = P;
}
/// <summary>
/// 基本表操作，写链表的交集.链表已排序，应该从公共最小点开始 复杂度 (N)
/// </summary>
void ListMix(List L1,List L2)
{
	Position Res;
	while (L1->Next != NULL && L2->Next != NULL)
	{
		if (L1->Next->Element > L2->Next->Element)
		{
			L2->Next = L2->Next->Next;
		}
		else if (L1->Next->Element < L2->Next->Element)
		{
			L1->Next = L1->Next->Next;
		}
		else 
		{
			Insert(L1->Element, L1, Res);
		}
	}
}
/// <summary>
/// 已排序链表并集
/// </summary>
/// <param name="L1"></param>
/// <param name="L2"></param>
void ListUnion(List L1, List L2)
{
	Position Res;
	while (L1->Next != NULL && L2->Next != NULL)
	{
		if (L1->Next->Element > L2->Next->Element)
		{
		    Insert(L2->Next->Element,L2,Res);
			L2->Next = L2->Next->Next;
		}
		else if (L1->Next->Element < L2->Next->Element)
		{
			Insert(L1->Next->Element, L1, Res);
			L1->Next = L1->Next->Next;
		}
		else
		{
			L1->Next = L1->Next->Next;
			L2->Next = L2->Next->Next;
			Insert(L1->Next->Element, L1, Res);
		}
	}
}
/// <summary>
/// 3.13反转链表
/// </summary>
/// <param name="L"></param>
void ReverList(List L)
{

}
//思路一： 仅释放链表头
//思路二： 挨个释放指针
List MakeEmpty(List L)
{

}
int main()
{

}

