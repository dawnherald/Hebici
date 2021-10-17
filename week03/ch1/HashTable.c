#include "HastTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct  ListNode
{
	int Element;
	Position Next;
};
typedef struct ListNode* List;
struct  HashTbl
{
	int TableSize;
	List* theLists;//������������ ListNode����ָ���ָ��.
	//List ָ��ListNode  List* ָ��  ָ��ListNode��ָ��
};
int Hash(int Key, int TableSize)
{
	return Key % TableSize;
}
/* Return next prime; assume N >= 10 */
static int
NextPrime(int N)
{
	int i;

	if (N % 2 == 0)
		N++;
	for (; ; N += 2)
	{
		for (i = 3; i * i <= N; i += 2)
			if (N % i == 0)
				goto ContOuter;  /* Sorry about this! */
		return N;
	ContOuter:;
	}
}
HashTable InitializeTable(int Table)
{
	HashTable H;
	if (Table == 0)
	{
		printf("��ʼ����С����");
		exit(0);
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("ɢ�б�����ռ�ʧ��");
		exit(0);
	}
	printf(H);
	//Ϊʲô����Ҫ��Prime
	//��ֱ�Ӹ�ֵTable =10 Table Sizeֵ��Ϊ10
	H->TableSize =  Table;
	printf("%d", H->TableSize);
	H->theLists = calloc(H->TableSize, sizeof(struct ListNode));
	//Ϊɢ�б�������������ռ�
	if (H->theLists == NULL)
	{
		printf("ɢ�б��ڵ���������ռ�ʧ��");
		exit(0);
	}
	for (int i = 0; i < Table; i++)
	{
		H->theLists[i] = malloc(sizeof(struct ListNode));
		if (H->theLists[i] == NULL)
		{
			printf("ɢ�б�����������ڵ���������ռ�ʧ��");
			exit(0);
		}
		else
		{
			H->theLists[i]->Next = NULL;
		}
	}
	return H;
}
void      DestoryTable(HashTable H);
Position  Find(int Key, HashTable H)
{
	Position P;
	List L;//P��LΪͬһ���� ������Ϊ�˷��������ǵ���ɢ�б��е�List������ �������������
	L = H->theLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P!=NULL&&P->Element!=Key)
	{
		P = P->Next;
	}
	return P;
}
//������������������ͷ�巨�Ĳ���
void      Insert(int Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)//����ֵû�б�����
	{
		NewCell = malloc(sizeof(struct ListNode));
		L = H->theLists[Hash(Key, H->TableSize)];
		NewCell = L->Next;
		NewCell->Element = Key;
		L->Next = NewCell;

	}
}
int       Retrieve(Position P)
{
	return P->Element;
}
int main()
{
	printf("ɢ�б����\n");
	HashTable H1 = InitializeTable(10);
	printf("ɢ�б��С%d\n", H1->TableSize);
	HashTable H2= InitializeTable(123);
	printf("ɢ�б��С%d\n", H2->TableSize);
}