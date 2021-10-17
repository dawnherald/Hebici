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
	{//较大根与较小根的左子树比较
		return Merge1(H1, H2);
	}
	else
	{
		return Merge1(H2, H1);
	}
}
//P1为较小根
static PriorityQueue Merge1(PriorityQueue P1, PriorityQueue P2)
{
	if (P1->Left == NULL)//左氏堆为空则为单节点，右子树必然路径为0	
	{
		P1->Left = P2;
		return P1;
	}
	else
	{
		P1->Right = Merge(P1->Right, P2);
		//为什么每次都需要根据深度对换结点 插入完成后如何？
		//递归理解，从底层向上完成路径长的矫正
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