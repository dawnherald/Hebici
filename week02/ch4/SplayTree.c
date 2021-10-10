#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// ��չ��Find���̵�չ������
/// ɾ�����̲���
/// </summary>
struct SplayTreeNode
{
	int Elmement;
	int Height;
	//������ָ����
	struct SplayTreeNode* Left;
	struct SplayTreeNode* right;
};
//�����ָ��
typedef struct SplayTreeNode* SplayTree;
typedef struct SplayTreeNode Splay;
//���ؽ��߶�
int Height(SplayTree S)
{
	if (S != NULL)
	{
		return S->Height;
	}
	else
	{
		return 0;
	}
}
//��ʼ�����
SplayTree initial(int x)
{
	SplayTree Head = malloc(sizeof(Splay));
	Head->Elmement = x;
	Head->Left = NULL;
	Head->right = NULL;
	
	return Head;
}
int MAX(int a, int b)
{
	return (a > b) ? a : b;
}
SplayTree FindMax(SplayTree B)
{
	if (B != NULL)
	{
		return FindMax(B->right);
	}
	else
	{
		printf("ָ�����");
		exit(0);
	}
}
SplayTree FindMin(SplayTree B)
{
	if (B->Left != NULL)
	{
		return FindMin(B->Left);
	}
	else
	{
		return B;
	}
}
SplayTree SingleRotateLeft(SplayTree A)
{
	SplayTree temp;
	temp = A->Left;
	A->Left = temp->right;
	temp->right = A;
	temp->Height = MAX( (Height(temp->right)), Height(temp->right)) + 1;
	A->Height = MAX(Height(A->right), Height(A->right)) + 1;
	return temp;

}
SplayTree SingleRotateRight(SplayTree A)
{

	SplayTree temp = A->right;
	A->right = temp->Left;
	temp->Left = A;
	temp->Height = MAX(Height(temp->right), Height(temp->right)) + 1;
	A->Height = MAX(Height(A->right), Height(A->right)) + 1;
	return temp;

}
SplayTree DoubleRotateLeft(SplayTree A)
{
	A->Left = SingleRotateRight(A->Left);
	return SingleRotateLeft(A);
}
SplayTree DoubleRotateRight(SplayTree A)
{
	A->right = SingleRotateLeft(A->right);
	return SingleRotateRight(A);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//��չ���Ĳ��� չ������
SplayTree oneTypeLeft(SplayTree B)
{
	SplayTree paremt = B->Left;
	SplayTree son = paremt->Left;
	B->Left = paremt->right;
	paremt->right = B;
	paremt->Left = son->right;
	son->right = B;
	return son;

}
SplayTree ZtypeLeft(SplayTree B)
{
	return DoubleRotateLeft(B);
}
SplayTree onteTypeRight(SplayTree B)
{
	SplayTree paremt = B->right;
	SplayTree son = paremt->right;
	B->right = paremt->right;
	paremt->Left = B;
	paremt->right = son->right;
	son->Left = B;
	return son;
}
SplayTree ZtypeRight(SplayTree B)
{
	return DoubleRotateRight(B);
}
/// <summary>
/// ��չ���ķ������̣������ʵĽ�㷵�ص���
/// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>
SplayTree Find(SplayTree B, int x)
{
	//�жϽ���Ƿ��ڸ��ڵ�����Ҷ���
	if (B->Left->Elmement == x)
	{
		B = SingleRotateLeft(B);
	}
	else if (B->right->Elmement == x)
	{
		B = SingleRotateRight(B);
	}
	else 
	{
		//���ڵ���������û��Ŀ��ڵ�
		//�ж���һ�����Ķ��ӽ������Ŀ����
		//��û�У��ٸ��ݴ�С����������������
		/*if (B->Elmement > x)
		{
			B = Find(B->right, x);
			if (B->Left->Left->Elmement == x)
			{
				B = oneTypeLeft(B);
			}
			else if (B->Left->right->Elmement == x)
			{
				B = ZtypeLeft(B);
			}
		}else if(B->Elmement<x)
		{
			B = Find(B->Left, x);

		}*/
		if (B->Left->Left->Elmement == x)
		{
			B = oneTypeLeft(B);
		}
		else if (B->Left->right->Elmement == x)
		{
			B = ZtypeLeft(B);
		}
		else if(B->right->right->Elmement==x)
		{
			B = onteTypeRight(B);
		}
		else if (B->right->Left->Elmement==x)
		{
			B = ZtypeRight(B);
		}
		else
		{
			if (B->Elmement > x)
			{
				B->Left=Find(B->Left, x);
			}
			else if (B->Elmement < x)
			{
				B->right = Find(B->right, x);
			}
		}
	}
	return B;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/// <summary>
/// ��д���Һ���
/// 
/// 1. �Ե����� ���ҵ�Ŀ��ڵ� Ŀ��ڵ���ӽڵ� Ŀ����ĸ��ڵ�
/// 2. ��չ���̿���ͨ�����ҵ���ת���
/// /// /// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>

int MyCompare(int a, int b)
{
	return (a > b) ? -1:1;
}

//��չ
SplayTree SpalyMethod(SplayTree B, int x)
{
	if (B == NULL)
	{
		return NULL;
	}
	else
	{
		if (B->Elmement > x)
		{
			B->Left=SpalyMethod(B->Left, x);
			B = SingleRotateLeft(B);
		}
		else if (B->Elmement < x)
		{
			B->right = SpalyMethod(B->right, x);
			B = SingleRotateRight(B);
		}
		else
		{
			return B;
		}
	}
	return B;
}

SplayTree search(SplayTree B, int x,int root)
{
	if (B == NULL)
	{
		return NULL;
	}
	int compareResult = MyCompare(B->Elmement, x);
	//�жϲ�����������������
	if (compareResult > 0)
	{
		return search(B->Left, x,root);
	}
	else if (compareResult < 0)
	{
		return search(B->right, x,root);
	}
	else
	{
		//�ҵ�Ŀ��ʱ��������չ
		//��ʱ�ݹ��ҵ�Ŀ��Ӧ��Ϊ���ڵ㡣
		//��������Ϊ���ڵ�

		root= SpalyMethod( B , x);
		return B;
	}



}
SplayTree insert(SplayTree B, int x)
{
	if (B == NULL)
	{
		B = initial(x);
	}
	else
	{
		if (B->Elmement > x)
		{
			B->Left = insert(B->Left, x);
			//��������������ı䣬���ֻ��Ҫ�ж���������ȥ��������ò��
			if (Height(B->Left) - Height(B->right) == 2)
			{
				if (x < B->Left->Elmement)
				{
					B = SingleRotateLeft(B);
				}
				else
				{
					B = DoubleRotateLeft(B);
				}
			}
		}

		else if (B->Elmement < x)
		{
			B->right = insert(B->right, x);
			//��������������ı䣬���ֻ��Ҫ�ж���������ȥ��������ò��
			if (Height(B->right) - Height(B->Left) == 2)
			{
				if (B->right->Elmement)
				{
					B = SingleRotateRight(B);
				}
				else
				{
					B = DoubleRotateRight(B);
				}
			}
		}
	}
	B->Height = MAX(Height(B->Left), Height(B->right)) + 1;
	return B;

}

void lefprint(SplayTree A)
{
	if (A != NULL)
	{
		lefprint(A->Left);
		printf("%d", A->Elmement);
		lefprint(A->right);

	}
}
void rightprint(SplayTree A)
{
	if (A != NULL)
	{

		lefprint(A->right);
		printf("%d", A->Elmement);
		lefprint(A->Left);
	}
}

int main()
{
	SplayTree A1 = initial(5);
	insert(A1, 4);
	insert(A1, 6);
	insert(A1, 7);
	insert(A1, 0);
	printf("������ĸ߶�:\n");
	printf("%d\n", A1->Height);
	printf("ǰ�����:\n");
	lefprint(A1);
	printf("\n");
	printf("���������\n");
	rightprint(A1);
	printf("\n��չ���������̣�");
	Find(A1, 4);
	printf("\n���ĸ��ڵ�Ӧ��Ϊ4��%d\n", A1->Elmement);
	SplayTree root = A1;
	printf("��д��������");
	search(A1, 11,root);
	printf("%d", A1->Elmement);
	printf("%d", root->Elmement);
	printf("ǰ�����:\n");
	lefprint(A1);
}