#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// AVL ����CRUD 
/// ʵ���������ֱ���
/// </summary>
struct AvlTreeNode
{
	int Elmement;
	int Height;
	//������ָ����
	struct AvlTreeNode* Left;
	struct AvlTreeNode* right;
};
//�����ָ��
typedef struct AvlTreeNode* AvlTree;
typedef struct AvlTreeNode Avl;
//��ʼ�����
AvlTree initial(int x)
{
	AvlTree Head = malloc(sizeof(Avl));
	Head->Elmement = x;
	Head->Left = NULL;
	Head->right = NULL;
	Head->Height = 0;
	return Head;
}
int MAX(int a,int b)
{
	return (a > b) ? a : b;
}
int Height(AvlTree A)
{
	if (A == NULL)
	{
		return -1;
	}
	else
	{
		return A->Height;
	}
}
AvlTree Find(AvlTree B, int x)
{
	if (B != NULL)
	{
		if (x < B->Elmement)
		{
			return Find(B->Left, x);
		}
		else if (x > B->Elmement)
		{
			return Find(B->right, x);
		}
		else
		{
			return B;
		}
	}
	else
	{
		return NULL;
	}
}
AvlTree FindMin(AvlTree B)
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
AvlTree FindMax(AvlTree B)
{
	if (B->right != NULL)
	{
		return FindMax(B->right);
	}
	else
	{
		return B;
	}
}
AvlTree SingleRotateLeft(AvlTree A)
{
	AvlTree temp;
	temp = A->Left;
	A->Left = temp->right;
	temp->right = A;
	temp->Height = MAX(Height(temp->right), Height(temp->right)) + 1;
	A->Height = MAX(Height(A->right), Height(A->right)) + 1;
	return temp;

}
AvlTree SingleRotateRight(AvlTree A)
{

	AvlTree temp = A->right;
	A->right = temp->Left;
	temp->Left = A;
	temp->Height = MAX(Height(temp->right), Height(temp->right)) + 1;
	A->Height = MAX(Height(A->right), Height(A->right)) + 1;
	return temp;

}
AvlTree DoubleRotateLeft(AvlTree A)
{
	A->Left = SingleRotateRight(A->Left);
	return SingleRotateLeft(A);
}
AvlTree DoubleRotateRight(AvlTree A)
{
	A->right = SingleRotateLeft(A->right);
	return SingleRotateRight(A);
}
AvlTree insert(AvlTree B, int x)
{
	if (B == NULL)
	{
		B = initial(x);
	}
	else
	{
		if (B->Elmement > x)
		{
			B->Left = insert(B->Left,x);
        //��������������ı䣬���ֻ��Ҫ�ж���������ȥ��������ò��
		if (Height(B->Left) - Height(B->right) == 2)
		{
			
			if (x<B->Left->Elmement)
			{
				B = SingleRotateLeft(B);
			}
			else
			{
				B = DoubleRotateLeft(B);
			}
		}
		}
		
		else if(B->Elmement<x)
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
/// <summary>
/// 4.19 Avl����ķǵݹ麯��
/// </summary>
/// <param name="A"></param>
/// <param name="x"></param>
AvlTree UnrecurisonInsert(AvlTree A, int x)
{
	
	//�����һ�����Ϊ���ڵ�ʱ
	if (A == NULL)
	{
		A= initial(x);
	}else
	{
		AvlTree temp = A;
		while (temp->Elmement!=x )
		{
			if (x < temp->Elmement)
			{
				if (temp->Left != NULL)
				{
					temp = temp->Left;
					continue;
				}
				else
				{
					temp->Left = initial(x);
					break;
				}
				
			}
			else if(x>temp->Elmement)
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
					continue;
				}
				else
				{
					temp->right = initial(x);
					break;
				}
			}
		}
	}
}
/// <summary>
/// 4.20 Avl���еķ�����ɾ��
/// ʵ��˼·��
/// </summary>
/// <param name="A"></param>
/// <param name="x"></param>
AvlTree UnLazeDelete(AvlTree A,int x)
{
	if (A->Elmement > x)
	{
		A->Left=UnLazeDelete(A->Left, x);
	}
	else if (A->Elmement < x)
	{
		A->right=UnLazeDelete(A->right, x);
	}
	else
	{
		//��һ����� ɾ�����ΪҶ�ӽ��
		if (A->Left == NULL && A->right == NULL)
		{
			free(A);
		}
		//ɾ�����ֻ�����ӵ����
		else if (A->Left!=NULL&&A->right==NULL)
		{
			A->Elmement = A->Left->Elmement;
			A->Left = NULL;
		}
		else if (A->right!=NULL&&A->Left==NULL)
		{
			A->Elmement = A->right->Elmement;
			A->right = NULL;
		}
		//���Һ��Ӷ��У����ú�̽ڵ����ýڵ㡣
		else if(A->Left!=NULL&&A->right!=NULL)
		{
			AvlTree temp = FindMin(A->right);
			A->Elmement = temp->Elmement;
			A->right = UnLazeDelete(A->right, temp->Elmement);
		}
	}
	return A;
}
void lefprint(AvlTree A)
{
	if (A != NULL)
	{
		lefprint(A->Left);
		printf("%d", A->Elmement);
		lefprint(A->right);
		
	}
}
void rightprint(AvlTree A)
{
	if (A != NULL)
	{
		lefprint(A->right);
		printf("%d", A->Elmement);
		lefprint(A->Left);
	}
}
/// <summary>
/// 4.22
/// </summary>
/// <returns></returns>
/// 
AvlTree FasterDoubleRotateWithLeft(AvlTree A)
{
	AvlTree fater = A->Left;
	AvlTree son = fater->right;
	fater->right = son->Left;
	A->Left = fater->right;
	fater->Left = son;
	fater->right = A;
	A->Height = MAX(Height(A->Left), Height(A->right)) + 1;
	fater->Height = MAX(Height(fater->Left), Height(fater->right)) + 1;
	son->Height = MAX(Height(son->Left), Height(son->right)) + 1;
	return fater;
}

/// <summary>
/// �����߶�ΪH��Avl��
/// </summary>
/// <param name="H"></param>
/// <returns></returns>
int RandInt(int left,int right)
{
	return rand() % right - left;
}
AvlTree makeRandAvlTree( int H)
{
	if (H > 0)
	{
		AvlTree temp = malloc(sizeof(Avl));
		if (temp == NULL)
		{
			return NULL;
		}
		temp->Left = makeRandAvlTree(H - 1);
		temp->right = makeRandAvlTree(H - 2);
		if (temp->Left == NULL && temp->right == NULL) // ��������һ���ڵ� ���������
			temp->Elmement = rand();
		else if (temp->Left == NULL) // ���������Ϊ�յĻ� ˵������������ ����T.item ҪС��������
			temp->Elmement = RandInt(0, temp->right->Elmement);
		else if (temp->right == NULL)
			temp->Elmement = RandInt(temp->Left->Elmement, RAND_MAX); // ͬ������
		else
			temp->Elmement = RandInt(temp->Left->Elmement, temp->right->Elmement); // �����߽ڵ㶼���ڵ�ʱ��  ��ǰ�ڵ�Ҫ������ڵ����ҽڵ�֮��
		return temp;
	}
}
/// <summary>
/// �������
/// </summary>
/// <returns></returns>
//����AvlTreeNode���͵Ķ���
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	Avl Array;

};
typedef struct QueueRecord* Queue;// Node ����ָ��ı���
static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)//�ֲ����� �ᵼ�������Value�Լ���
		Value = 0;
	return Value;
}
void  Enqueue(AvlTree x, Queue S)
{
	if (IsFull(S))
	{
		printf("out of memory");
	}
	else
	{
		S->Size++;
		S->Rear = Succ(S->Rear, S);
		S->Array[S->Rear] =(AvlTree) x;
	}
}
AvlTree   Front(Queue Q)
{
	return Q->Array[Q->Front];
}
//����
void  Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("out of memory");
	}
	else
	{
		Q->Size--;
		Q->Array[Q->Front] = NULL;
		Q->Front = Succ(Q->Front, Q);
	}
}
/// <summary>
/// �������
/// </summary>
/// <returns></returns>
/// 

int main()
{
	AvlTree A1 = initial(5);
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
	printf("\n�κ��19��\n");
	UnrecurisonInsert(A1, 10);
	lefprint(A1);
	printf("\n4.20:\n");
	UnLazeDelete(A1, 10);
	lefprint(A1);
	printf("\n4.29:\n");
	AvlTree A2=makeRandAvlTree(10);
	lefprint(A2);
}