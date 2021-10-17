#include "leftHeap.h"
#include "stdio.h"
#include "stdlib.h"
struct TreeNode
{
	int Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};
PriorityQueue Initialize(void)
{
	PriorityQueue temp = malloc(sizeof(struct TreeNode));
	temp->Element = 0;
	temp->Left = NULL;
	temp->Right = NULL;
	temp->Npl = 0;
	return temp;
}
int  FindMin(PriorityQueue P);
int  IsEmpty(PriorityQueue P);
#define Insert(X,H) (H=Insert1(X,H));
void SwapChildren(PriorityQueue P)
{
	PriorityQueue temp = P->Right;
	P->Right = P->Left;
	P->Left = temp;
	P->Npl = P->Right->Npl + 1;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
	{
		return H2;
	}
	if (H2 == NULL)
	{
		return H1;
	}
	if (H1->Element < H2->Element)
	{//�ϴ�����С�����������Ƚ�
		return Merge1(H1, H2);
	}
	else
	{
		return Merge1(H2, H1);
	}
}
//P1Ϊ��С��
static PriorityQueue Merge1(PriorityQueue P1, PriorityQueue P2)
{
	if (P1->Left == NULL)//���϶�Ϊ����Ϊ���ڵ㣬��������Ȼ·��Ϊ0	
	{
		P1->Left = P2;
		return P1;
	}
	else
	{
		P1->Right = Merge(P1->Right, P2);
		//Ϊʲôÿ�ζ���Ҫ������ȶԻ���� ������ɺ���Σ�
		//�ݹ���⣬�ӵײ��������·�����Ľ���
		if (P1->Left->Npl < P1->Right->Npl)
		{
			SwapChildren(P1);
		}
	}
	return P1;
}
PriorityQueue Insert1(int x, PriorityQueue P)
{
	PriorityQueue SingleNode = malloc(sizeof(struct TreeNode));
	SingleNode->Element = x;
	SingleNode->Npl = 0;
	SingleNode->Left = SingleNode->Right = NULL;
	P = Merge(SingleNode, P);
	return P;
}
PriorityQueue DeleteMin1(PriorityQueue P)
{
	PriorityQueue LeftHeap = P->Left, RightHeap = P->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
int main()
{

}