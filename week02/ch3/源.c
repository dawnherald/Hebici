#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// stuct Node*  p  = List L  Pֻ������ָ��Lָ��Ŀռ�
/// p =malloc  ���Ǵ����µĵ�Ԫ
/// p = l ,����Ӱ��l�ĵ�ַ�仯��
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
	    printf("��������ֵ");
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