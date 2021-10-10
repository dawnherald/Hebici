#include "stdio.h"
#include "stdlib.h"
/// <summary>
/// 伸展树Find历程的展开操作
/// 删除历程操作
/// </summary>
struct SplayTreeNode
{
	int Elmement;
	int Height;
	//树结点的指针域
	struct SplayTreeNode* Left;
	struct SplayTreeNode* right;
};
//树结点指针
typedef struct SplayTreeNode* SplayTree;
typedef struct SplayTreeNode Splay;
//返回结点高度
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
//初始化结点
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
		printf("指针溢出");
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
//伸展树的查找 展开历程
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
/// 伸展树的访问历程，将访问的结点返回到根
/// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>
SplayTree Find(SplayTree B, int x)
{
	//判断结点是否在根节点的左右儿子
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
		//根节点左右子树没有目标节点
		//判断下一个结点的儿子结点有无目标结点
		//若没有，再根据大小左子树右子树访问
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
/// 重写查找函数
/// 
/// 1. 自底向上 先找到目标节点 目标节点的子节点 目标结点的父节点
/// 2. 伸展过程可以通过左右单旋转完成
/// /// /// </summary>
/// <param name="B"></param>
/// <param name="x"></param>
/// <returns></returns>

int MyCompare(int a, int b)
{
	return (a > b) ? -1:1;
}

//伸展
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
	//判断查找左子树或右子树
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
		//找到目标时，进行伸展
		//此时递归找到目标应该为父节点。
		//将其设置为根节点

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
			//插入后是左子树改变，因此只需要判断左子树减去右子树搞得差距
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
			//插入后是左子树改变，因此只需要判断左子树减去右子树搞得差距
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
	printf("输出树的高度:\n");
	printf("%d\n", A1->Height);
	printf("前序遍历:\n");
	lefprint(A1);
	printf("\n");
	printf("后序遍历：\n");
	rightprint(A1);
	printf("\n伸展树查找历程：");
	Find(A1, 4);
	printf("\n树的根节点应该为4：%d\n", A1->Elmement);
	SplayTree root = A1;
	printf("重写查找例程");
	search(A1, 11,root);
	printf("%d", A1->Elmement);
	printf("%d", root->Elmement);
	printf("前序遍历:\n");
	lefprint(A1);
}