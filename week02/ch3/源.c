#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// stuct Node*  p  = List L  P只是留够指向L指针的空间
/// p =malloc  则是创建新的单元
/// p = l ,不会影响l的地址变化。
/// </summary>
struct Node
{
	int Element;
	int Flags;
	int FlagNums;
	struct Node* Next;
};
typedef struct Node* List;
void insertList( List Q)
{
	int x = 0;
	List temp, L;
	L = Q;
	
	while (x != 9999)
	{   temp = malloc(sizeof(struct Node));
	    printf("请输入数值");
	    scanf_s("%d", x);
		L->Next = temp;
		temp->Element = x;
		temp->Flags = 0;
		L = temp;
	}
}
int main()
{
	struct Node* L;
	L = malloc(sizeof(struct Node));
	insertList(L);
}