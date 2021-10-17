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
	List* theLists;//创建链表数组 ListNode类型指针的指针.
	//List 指向ListNode  List* 指向  指向ListNode的指针
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
		printf("初始化大小出错");
		exit(0);
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("散列表申请空间失败");
		exit(0);
	}
	printf(H);
	//为什么必须要有Prime
	//当直接赋值Table =10 Table Size值不为10
	H->TableSize =  Table;
	printf("%d", H->TableSize);
	H->theLists = calloc(H->TableSize, sizeof(struct ListNode));
	//为散列表的链表数组分配空间
	if (H->theLists == NULL)
	{
		printf("散列表内的链表申请空间失败");
		exit(0);
	}
	for (int i = 0; i < Table; i++)
	{
		H->theLists[i] = malloc(sizeof(struct ListNode));
		if (H->theLists[i] == NULL)
		{
			printf("散列表的链表数组内的链表申请空间失败");
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
	List L;//P和L为同一类型 仅仅是为了方便区分是调用散列表中的List的数据 还是链表的数据
	L = H->theLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P!=NULL&&P->Element!=Key)
	{
		P = P->Next;
	}
	return P;
}
//基于链表数组中链表头插法的插入
void      Insert(int Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)//输入值没有被发现
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
	printf("散列表测试\n");
	HashTable H1 = InitializeTable(10);
	printf("散列表大小%d\n", H1->TableSize);
	HashTable H2= InitializeTable(123);
	printf("散列表大小%d\n", H2->TableSize);
}