#include "Polynomial.h"
#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// ϰ��3.6-3.7.1
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
//����ʽ��ϵ���ݼ�����
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
			//Res��ָ�������i�����
			insertPolyminal(Res, P1->Next->Coefficient, P1->Next->Exponent);
			//��res��ָ�������i+1�����
			P1->Next = P1->Next->Next;
		}
		else if (P1->Next->Exponent < P2->Next->Exponent||P1->Next==NULL)
		{
			//Res��ָ�������һ�����
			//Res->Next->Coefficient = P2->Next->Coefficient;//Res ������ NextΪ0��
			//Res->Next->Exponent = P2->Next->Exponent;
			insertPolyminal(Res,P2->Next->Coefficient,P2->Next->Exponent);
			P2->Next = P2->Next->Next;
			//��res��ָ������ڶ������
		}
		else
		{
			insertPolyminal(Res, P2->Next->Coefficient+P1->Next->Coefficient, P2->Exponent);
			P1->Next = P1->Next->Next;
			P2->Next = P2->Next->Next;
		}

	}
}
////����ʽ��ϵ���ݼ����� M^2+M^2
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
			//˼·�� ˫ָ�� ������������Ļ� ����Ҫfindprv ������ �ᵼ���㷨���Ӷ�ΪN3.
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
	//Polyminal temp = P;//ָ�븳ֵ�����ǿ�¡�� ��temp����Ҳ�ᵼ��Pָ�벻������ƶ�
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
	PrintPolyminal(N1);//PrintPolyminal��ʹN1.Next==NULL
	insertPolyminal(N2, 1, 5);
	PrintPolyminal(N2);
	insertPolyminal(N3, 0, 0);
	AddPolyminal(N1->Head, N2->Head, N3);
	PrintPolyminal(N3);
}