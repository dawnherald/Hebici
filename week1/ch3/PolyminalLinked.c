#include "Polynomial.h"
#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// 习题3.6-3.7.1
/// BUG;
/// </summary>
struct  Node
{
	int Coefficient;
	int Exponent;
	Polyminal Next;
	Polyminal Head;
};
Polyminal creatPol()
{
	Polyminal temp;
	temp = malloc(sizeof(struct Node));
	temp->Next = NULL;
	temp->Coefficient = 0;
	temp->Head = temp;
	temp->Exponent = 0;
	return temp;
}
void insertPolyminal(Polyminal P,int Coe,int Exp)
{
	Polyminal temp;
	temp = malloc(sizeof(struct Node));
	temp->Next = P->Next;
	P->Next = temp;
	temp->Coefficient = Coe;
	temp->Exponent = Exp;
}

Polyminal insertPolyminal2(Polyminal P, int Coe, int Exp)
{
	Polyminal temp;
	temp = malloc(sizeof(struct Node));
	temp->Next = P->Next;
	P->Next = temp;
	temp->Coefficient = Coe;
	temp->Exponent = Exp;
	return P;
}
//多项式由系数递减排序
void AddPolyminal(const Polyminal P1, const Polyminal P2, Polyminal Res)
{
	if (P1->Next == NULL || P2->Next == NULL)
	{
		printf("out of memory");
		exit(0);
	}
	while (P1->Next != NULL|| P2->Next != NULL)
	{ 
		if (P1->Next->Exponent > P2->Next->Exponent)
		{
			//Res的指针移向第i个结点
			insertPolyminal(Res, P1->Next->Coefficient, P1->Next->Exponent);
			//将res的指针移向第i+1个结点
			P1->Next = P1->Next->Next;
		}
		else if (P1->Next->Exponent < P2->Next->Exponent||P1->Next==NULL)
		{
			//Res的指针移向第一个结点
			//Res->Next->Coefficient = P2->Next->Coefficient;//Res 创建后 Next为0；
			//Res->Next->Exponent = P2->Next->Exponent;
			insertPolyminal(Res,P2->Next->Coefficient,P2->Next->Exponent);
			P2->Next = P2->Next->Next;
			//将res的指针移向第二个结点
		}
		else
		{
			insertPolyminal(Res, P2->Next->Coefficient+P1->Next->Coefficient, P2->Exponent);
			P1->Next = P1->Next->Next;
			P2->Next = P2->Next->Next;
		}

	}
}
////多项式由系数递减排序 M^2+M^2
void DeclinePolyminal(Polyminal P)
{
	Polyminal temp;
	temp = malloc(sizeof(struct Node));
	temp = P->Next;
	while (P->Next!=NULL)
	{
		while (temp->Next != NULL)
		{
			/// <summary>
			//思路是 双指针 但如果交换结点的话 又需要findprv 这样子 会导致算法复杂度为N3.
			/// </summary>
			/// <param name="P"></param>
			if (P->Next->Exponent == temp->Next->Exponent)
			{

			}
		}
	}
}
void MulPolyminal(const Polyminal P1, const Polyminal P2, Polyminal Res)
{
	for (; P1->Next != NULL; P1->Next = P1->Next->Next)
	{
		for (; P2->Next != NULL; P2->Next = P2->Next->Next)
		{
			 Res = insertPolyminal2(Res, (P1->Next->Coefficient * P2->Next->Coefficient), (P1->Next->Exponent + P1->Next->Exponent));
		}
	}

}
void PrintPolyminal(Polyminal P)//
{
	//Polyminal temp = P;//指针赋值并不是克隆， 对temp操作也会导致P指针不断向后移动
	struct Node* temp;
	temp = P->Next;
	
	while (temp)
	{
		printf("%d*%d  ", temp->Coefficient, temp->Exponent);
		temp= temp->Next;
	}

}
int main()
{
	struct Node* N1,*N2,*N3;
	N1 = creatPol();
	N2 = creatPol();
	N3 = creatPol();
	insertPolyminal(N1, 1, 1);
	PrintPolyminal(N1);//PrintPolyminal会使N1.Next==NULL
	insertPolyminal(N2, 1, 5);
	PrintPolyminal(N2);
	insertPolyminal(N3, 0, 0);
	AddPolyminal(N1->Head, N2->Head, N3);
	PrintPolyminal(N3);
}