#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// ���Ӷ�ΪN�ķ�ת����
/// </summary>
struct  Node
{
	int nums;
	struct Node* Next;
	struct Node* Head;

};
typedef struct Node* List;
//ͷ�巨
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
	//����ѭ������
	temp->Next = L->Next;
	temp->nums = x;
	L->Next = temp; 
	printf("%d", temp->nums);
}
//β�巨
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
//��ת˼·�� ��ȡβ�巨����ֵ ͨ��ͷ�巨��ֵһ������
void ReverseLinked(List last)
{
	struct Node* temp;
	//��ȡβ�巨��ͷ���
	temp = last->Next;
	//ͷ�����ô���ֲ���
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