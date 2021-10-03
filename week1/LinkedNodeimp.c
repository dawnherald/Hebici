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
//�ж�����L�ĵ�ǰλ��P�Ƿ�Ϊĩβ
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

   Position P = L;//����typedf NOde ����List��Ϊ����ͷ
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
//����ʵ�ֲ������Ͳ�û��ȷ��L��P��λ�� 
//���Կ���ʹ��FindPrevious �ҵ�����ĩβ  ���ǵ���ֵ�ظ�ʱ�����д����ȡ��λ��
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
//ɾ�������ȷ����
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
/// 3.2 ��ӡ����
/// </summary>
/// <param name="L"></param>
/// <param name="P"></param>��������
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
				printf("�����%d��Ԫ��Ϊ:", B, L->Next->Element);
			}
		}
	}
}
/// <summary>
/// 3.3 ������ 
/// �ҵ��±�Ϊx��������
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
/// �����������д����Ľ���.����������Ӧ�ôӹ�����С�㿪ʼ ���Ӷ� (N)
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
/// ������������
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
/// 3.13��ת����
/// </summary>
/// <param name="L"></param>
void ReverList(List L)
{

}
//˼·һ�� ���ͷ�����ͷ
//˼·���� �����ͷ�ָ��
List MakeEmpty(List L)
{

}
int main()
{

}

