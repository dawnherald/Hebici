#include "stdio.h"
#include "stdlib.h"
struct BinaryTreeNode
{
	int Elmement;
	//������ָ����
	struct BinaryTreeNode* Left;
	struct BinaryTreeNode* right;
};
//�����ָ��
typedef struct BinaryTreeNode* BinaryNode;
typedef struct BinaryTreeNode Binary;
BinaryNode initial(int x)
{
	BinaryNode Head = malloc(sizeof(Binary));
	Head->Elmement = x;
	Head->Left = NULL;
	Head->right = NULL;
	return Head;
}
BinaryNode Find(BinaryNode B,int x)
{
	if (B != NULL)
	{
		if (x < B->Elmement)
		{
			return Find(B->Left,x);
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
BinaryNode FindMin(BinaryNode B)
{
	if (B == NULL)
	{
	}
	else if (B->Left == NULL)
	{
		return B;
	}
	else
	{
		return FindMin(B->Left);
	}
}
BinaryNode FindMax(BinaryNode B)
{
	if (B == NULL)
	{
	}
	else if (B->right == NULL)
	{
		return B;
	}
	else
	{
		return FindMin(B->right);
	}
}
BinaryNode insert(BinaryNode B, int x)
{
	if (B == NULL)
	{
		 B = initial(x);
	}
	else
	{
		if (x < B->Elmement)
		{
			B->Left=insert(B->Left, x);
		}
		else if(x>B->Elmement)
		{
			B->right=insert(B->right, x);
		}
		else
		{
			;
		}
	}
	return B;
}

BinaryNode DeleteBinar(BinaryNode B,int x)
{
	if (B==NULL)
	{
		printf("��㲻���ڣ�������");
	}
	else
	{

		if (x < B->Elmement)
		{
			B->Left=DeleteBinar(B->Left, x);
		}
		else if (x > B->Elmement)
		{
			B->right=DeleteBinar(B->right, x);
		}
		else
		{
			if (B->Left != NULL && B->right != NULL)
			{
				BinaryNode temp = FindMin(B->right);
				B->Elmement = temp->Elmement;
				B->right = DeleteBinar(B->right,temp->Elmement);
			}
			else 
			{
				if (B->Left == NULL)
				{
					B = B->right;
				}
				else if(B->right=NULL)
				{
					B = B->Left;
				}
				free(B);
			}
		}
	}
	return B;
}
/// <summary>
/// 4.13�� ɾ�����������ӽڵ�ķ�������
/// </summary>
/// <param name="B"></param>


/// <summary>
/// ����һ Tl���������������x ���� �ݹ��ɾ�� x 
/// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>
BinaryNode DeleteTypy1(BinaryNode B, int x)
{
	if (B == NULL)
	{
		printf("��㲻���ڣ�������");
	}
	else
	{

		if (x < B->Elmement)
		{
			B->Left=DeleteTypy1(B->Left, x);
		}
		else if (x > B->Elmement)
		{
			B->right=DeleteBinar(B->right, x);
		}
		else
		{
			if (B->Left != NULL && B->right != NULL)
			{
				BinaryNode temp = FindMax(B->Left);
				B->Elmement = temp->Elmement;
				B->Left = DeleteBinar(B->Left, temp->Elmement);
			}
			//ɾ�������������
			else if (B->right == NULL)
			{
				free(B);
			}
		}
		//�ݹ����������������㲢ɾ��
	}
	return B;
}
/// <summary>
/// ����ʹ��Tl �Ķ������ TR����С������
/// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>
BinaryNode DeleteTypy2(BinaryNode B, int x,int flags)
{
	if (B == NULL)
	{
		printf("��㲻���ڣ�������");
	}
	else
	{

		if (x < B->Elmement)
		{
			B->Left=DeleteTypy2(B->Left, x,flags);
		}
		else if (x > B->Elmement)
		{
			B->right=DeleteTypy2(B->right, x,flags);
		}
		else
		{
			if (B->Left != NULL && B->right != NULL)
			{
				if (flags == 0)
				{
					BinaryNode temp; 
					temp= FindMax(B->Left);
				B->Elmement = temp->Elmement;
					B->Left = DeleteTypy2(B->Left, temp->Elmement,flags);
					flags = 1;
				}
				else
				{
					BinaryNode temp = FindMin(B->right);
					B->Elmement = temp->Elmement;
					B->right = DeleteTypy2(B->right, temp->Elmement,flags);
					flags = 0;
				}
				
			}
			else
			{
				if (B->Left == NULL)
				{
					B = B->right;
				}
				else if (B->right = NULL)
				{
					B = B->Left;
				}
				free(B);
			}
			}
		//�ݹ����������������㲢ɾ��
	}
	return B;
}
/// <summary>
/// ���ɾ�������ӽڵ�
/// </summary>
/// <param name="B"></param>
/// 
BinaryNode DeleteTypy3(BinaryNode B, int x)
{
	if (B == NULL)
	{
		printf("��㲻���ڣ�������");
	}
	else
	{
		int flags = rand() % 1 - 0;
		if (B->Elmement < x)
		{
			B->right=DeleteTypy3(B->right, x);
		}
		else if( B->Elmement>x)
		{
			B->Left=DeleteTypy3(B->Left, x);
		}
		else
		{
			if (B->Left != NULL && B->right != NULL)
			{
				if (flags == 0)
				{
					BinaryNode temp = FindMax(B->Left);
					B->Elmement = temp->Elmement;
					B->Left = DeleteTypy3(B->Left, x);
				}else if(flags ==1)
				{
					BinaryNode temp = FindMin(B->right);
					B->Elmement = temp->Elmement;
					B->right = DeleteTypy3(B->right, x);
				}
			}
			else
			{
				if (B->Left == NULL)
				{
					B = B->right;
				}
				else if (B->right = NULL)
				{
					B = B->Left;
				}
				free(B);
			}
		}
	}
}
void printBinaryTree(BinaryNode B)
{
	if (B != NULL)
	{
	;
		printBinaryTree(B->Left);
		printf("%d ", B->Elmement);
		printBinaryTree(B->right);
		
	}
}
/// <summary>
/// 4.28 ��д��Ч�ʺ��� ͨ�����ĸ��ڵ��������ȫ��Ԫ��
/// </summary>
/// <param name="B"></param>
//�ڵ�ĸ���
int  countPoint(BinaryNode B)
{
	int j = 0;
	if (B != NULL)
	{
		j++;
		j+= countPoint(B->Left);
		j+= countPoint(B->right);
	}
	return j;

}
//��Ҷ�ĸ���
int  countLeave(BinaryNode B)
{
	int i = 0;

	if (B->Left != NULL&&B->right!=NULL)
	{
		i+=countLeave(B->Left);
		i+=countLeave(B->right);
	}
	else if(B->Left==NULL&&B->right==NULL)
	{
		return i + 1;
	}
	else if (B->Left != NULL)
	{
		i += countLeave(B->Left);
	}
	else if (B->right != NULL)
	{
		i += (countLeave(B->right));
	}
}
//���ڵ�ĸ���
int countFullPoint(BinaryNode B )
{
	int i = 0;
	if (B->Left != NULL && B->right != NULL)
	{
		i++;
		i += countFullPoint(B->Left);
		i += countFullPoint(B->right);
	}
	else if (B->Left == NULL && B->right == NULL)
	{
		return 0;
	}else if(B->Left!=NULL)
	{
		i+=countFullPoint(B->Left);
	}
	else if(B->right!=NULL)
	{
		i += countFullPoint(B->right);
	}

}
/// <summary>
/// �������1-n�Ķ��������
/// </summary>
/// <param name="left"></param>
/// <param name="right"></param>
/// <returns></returns>
BinaryNode RandBinaryTree(BinaryNode root,int left,int right)
{
	int middle = (left + right) / 2;
	
	if (root == NULL)
	{
		BinaryNode temp = initial(middle);
		root = temp;
	}
	if (left !=  right)
	{
	root->Left = RandBinaryTree(root->Left, left, middle);
	root->right = RandBinaryTree(root->right, middle, right);
	}
	return root;

}

int main()
{
	printf("������:\n");
	BinaryNode N1 = initial(5);
	for (int i = 0; i < 20; i++)
	{
		insert(N1, rand() % 20 - 0);
	}
	printBinaryTree(N1);
	printf("\n");
	printf("ɾ�����̣�\n");
	DeleteBinar(N1, 11);
	printBinaryTree(N1);
	printf("\n");
	printf("�κ��13�⣺\n");
	printf("��һ��ɾ����ʽ\n");
	insert(N1, 11);
	DeleteTypy1(N1, 11);
	printBinaryTree(N1);
	printf("\n");
	printf("�ڶ���ɾ����ʽ\n");
	insert(N1, 11);
	DeleteTypy2(N1, 11,0);
	printBinaryTree(N1);
	printf("\n");
	printf("������ɾ����ʽ\n");
	insert(N1, 11);
	DeleteTypy3(N1, 11);
	printBinaryTree(N1);
	printf("\n���ĸ���\n");
	printf("%d",countPoint(N1));
	printf("\nҶ�ӽ��ĸ���\n");
	printf("%d", countLeave(N1));
	printf("\n�����ĸ���\n");
	printf("%d", countFullPoint(N1));
	printf("\n�������1-100�Ķ���������\n");
	BinaryNode B1 = initial(0);
	B1 = RandBinaryTree(B1,1,99);
	printBinaryTree(B1);
}