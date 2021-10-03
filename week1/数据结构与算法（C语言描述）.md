# 数据结构与算法（C语言描述）

# 目标：

9.8

第一章“引论”，了解本书学习内容，注重递归简论以及书上给的例题，如打印一个整数等；

第二章“算法分析”，注重看一下如何分析算法的时间复杂度，以及书上的例题如最大子序列和等等。

## 第一章：

### 问题：

1.递归的时间和空间花费如何计算？按照向基准路线执行？和函数调用自身产生的循环？

编译出现无法找到标识符：

### 1.1递归

递归类似数学的条件函数，将不同的方程式按照不同的域分开。但是递归具有重要的特点，有一个确定条件的确定值。

### 1.2递归的基本原则

基准情形：基本且确定的值。递归函数最终都调用基准情节

问题：不恰当的条件设置，会无法抵达到基准情形 eg：1-3。

不断推进：递归函数要最终能到达他的基准情形。

设计法则：递归函数对于内存空间必须时可行的，不能溢出，可以执行的。

合成效益：递归函数必须保证递归后要比循环结构更快，同时尽可能避免大部分重复工作。

### 1.3选择问题：

### 1.4输出一个整形数值理解

输出整型函数中，基准情况 时 printDigit(N%10)，当形参小于10直接输出。推进则是使用递归（num/10）。输入的整数除10，整数从左往右一次取出，取到小数。

### 练习：

1.2

没有使用递归

```c
#include <stdio.h>
#include <stdlib.h>
#define max 112 //基于ASCII码字母和rend函数随机产升需要猜的字母
#define min 65
char retchatater()
{
	int num = rand()%(max - min) + min;
	char a = num;
	return   a ;
}
int main ( void )
{
	char res =retchatater();
	char toguess;
	while(true)
	{
		
		printf("请输入你猜的英文字母（区分大小写）");
		scanf("%c",&toguess);
		if(res==toguess)
		{
			printf("猜对了");
		    break;}
		else
		{
			printf("猜错了");
		    continue;
		}

	}

}
```

使用递归：

问题： scanf的形参地址和其赋值相同时，无法成功。猜测scanf函数对形参地址的影响。

```c
char togess= scanf("%c",&togess); 
```

```c
#include <stdio.h>
#include <stdlib.h>
#define max 112 //基于ASCII码字母和rend函数随机产升需要猜的字母
#define min 65
void retchatater()
{
	int a =1;
	char cha;
	char togess;
	if(a==1)
	{
	int num = rand()%(max - min) + min;
	cha = num;
	a++;
	}
	printf("请输入你猜的英文字母。");
	scanf("%c",&togess);
	//char togess= scanf("%c",&togess); //编译后，无法答对
	printf("你输入的字母：%c",&togess);
	if( togess== cha)
	{
		printf("恭喜你猜对了");
	}
	else
	{
		printf("猜错了，再猜一次");
		retchatater();
	}
}
int main ( void )
{
	
	retchatater();
}

```

1.3 输出任意实数

```


```



## 第二章：

### 问题：

1. 循环时的界限有时候难以估摸
2. 最大子序列求和算法四为何成立？  猜测 ++ --  +-形式有关。
3. 如果能够准确书写出准基情况 和 推进递归
4. 对数的算法评估，基本靠判断问题规模的大小，具体的不会分析。

### 1.算法评估

算法的评估时在不同输入规模下相对增长率。

O ：评估算法增长率的上界

Θ ：算法增长率的中间值

 Ω：算法增长率的下界

通常，使用O来评估算法的效益。O判断只关注最大项，忽略了实数等等。

最大子序列和：四种不同算法仅仅在输入规模0~100以内就产生差异。算法以O来评估，往往简单快捷。

### 2.计算时间的确认

计算时间默认每条语句执行时间单位相同，忽略命名等等，将时间加起来，取最高项。

有四种常见情况：

循环  关注语句和迭代次数。

嵌套循环

顺序语句 关注最大花费

if/else语句 判断时间+最大花费

**分析后，很容易判断递归是否符合合成效益。**

分析时，主要关注循环语句部分

### 3.最大子序列求和

算法一：三个循环

第一个循环 从数组左端开始

第二个循环 从数组I结点向右循环

第三个循环 则从两端中间的式子进行计算

算法二： 对算法一优化 从算法中第二个循环就对式子计算，从i到N

算法二： 算法一优化。

算法三！！ 优化到nlogn。

### 分治思想：将问题分成同类型的”小问题“，然后采用迭代”治“。那么算法复杂度就是分 和 治 的和。

算法四 ： 复杂度 O（N）。

## 对递归分析！！！ 分析斐波那契数？？？



### 练习：

四个求最大序列算法：

自我实现+算法测试：

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bigON3(const int A[])
{
	clock_t start,end;
    start = clock();
	int length = sizeof(A)/sizeof(A[0]);
	printf("数组的长度是%d\n",&length);
	int thesum,maxsum;
	for(int i =0 ;i<length;i++)
	{
		for(int j =i;j<length;j++)
		{
			for(int a=i;a<j;a++)
			{
				thesum+=A[a];
				//(thesum>maxsum)?(maxsum=thesum): ;
				//C语言三元运算符只能输入表达式？？？
				if(thesum>maxsum)
				{
					maxsum=thesum;
				}
			}
		}
	}
	end = clock(); //结束时，取得结束时间

	printf("算法一运行时间是%f S\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("算法一的最大序列和是%d\n",&maxsum);
}
void bigON2(const int A[])
{
	clock_t start,end;
    start = clock();
	int length = sizeof(A)/sizeof(A[0]);
	printf("数组的长度是%d\n",&length);
	int thesum=0,maxsum=0;
	for(int i =0 ;i<length;i++)
	{
		for(int j =i;j<length;j++)
		{
			
				thesum+=A[j];
				//(thesum>maxsum)?(maxsum=thesum): ;
				//C语言三元运算符只能输入表达式？？？
				if(thesum>maxsum)
				{
					maxsum=thesum;
				}
			
		}
	}
	end = clock(); 
	printf("算法二运行时间是%d\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("算法二最大数值是%d\n",&maxsum);
}
//返回最大值
int biggest(int a, int b)
{
    return a > b ? a : b;
}
int NlogN(const int A[],int left,int right)
{
	clock_t start,end;
    start = clock();
	int leftmax=0,righrmax=0;
	int leftboardmax,rightboardmax;
	int leftsum,rightsum;
	//int left,right,center; 通过读取长度的表达Left right实现失败。
	int center;
	int length = sizeof(A)/sizeof(A[0]);
	//基准情况
	if(left==right)
	{
		return A[left];
	}
	else
	{}
	center=(right+left)/2;
	//为何要从这里递归？
	leftmax=NlogN( A ,left,center);
	righrmax=NlogN(A,center+1,right);
	leftboardmax =0;leftsum=0;
	//递归忽视了边界，导致溢出
	for(int i =0;i<=center;i++)
	{
		leftsum+=A[i];
		if(leftsum>leftboardmax)
		{
			leftboardmax=leftsum;
		}
	}
	rightboardmax =0;rightsum=0;
	for(int i =center+1;i<=length;i++)
	{
		rightsum+=A[i];
		if(rightsum>rightboardmax)
		{
			rightboardmax=rightsum;
		}
	}
	end = clock(); 
	printf("算法三的运行时间是%d\n",(double)(end-start)/CLOCKS_PER_SEC);
	return biggest(leftmax+righrmax,biggest(leftmax,righrmax));

}
void ON(const int A[])
{
	clock_t start,end;
    start = clock();
	int thesum=0,maxsum=0;
	int length = sizeof(A)/sizeof(A[0]);
	printf("数组的长度是%d\n",&length);
	for(int i =0;i<length;i++)
	{
		thesum+=A[i];
		if(thesum>maxsum)
		{
			maxsum = thesum;
		}
		else if(thesum<0)
		{
		thesum=0;
		}
	}
	end = clock(); 
	printf("算法四运行时间是%d\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("算法四的最大序列和是%d\n",&maxsum);
}
int main()
{
	//srand((unsigned)time(null));
	int i =0;
	int test[10];
	printf("开始随机赋值\n");
	while(i<10)
	{
		//test[]={rand()%200-100}; 不能直接输入？？？
		int a =rand()%200-100;
		test[i]=a;
		i++;
	}
	printf("赋值结束\n");
	printf("算法一运行结果\n");
	bigON3(test);
	printf("算法二运行结果\n");
	bigON2(test);
	printf("算法三运行结果\n");
	NlogN(test,0,99);
	printf("算法三最大序列和如上\n");
	printf("算法四运行结果\n");
	ON(test);

}
```

2.7：

```

```



2.19

```

```

2.18



2.7.3



2.13

### 第二周问题：

1.对于迭代中创建数组，可以将数组宏定义来避免反复创建数组。

2.动态分配内存空间为何不能运行？？

3.判断语句中，指针不能和自己比较！！！！

4.仔细确认字符串指针长度和下标的关系。

5.递归方程算法：递归次数*递归每次操作花费

难点：1.准确找到问题的基准情形 2. 不断推进时的指针边界问题

6.对于尾递归，中间递归的过程理解。

1.每个递归都有独立的变量

2.每个递归都要完整的执行一次函数

3.递归执行方向可以理解为一个栈，先push压满，再pop逐个弹出执行。

第三周：

1.算法解决最大序列和时，学过DB思想，但写的时候总会受限于C语言的数组内存申请等原因，没有能够实现成递归

2.再快速排序中，了解排序时分次，每一次只能到达一个合适的地方。

3.二维数组的指针。指针的*p.  *pa[colim]的区别。    *(*(a + i))   *(a[0] + i)等等的区别。

4.指向数组的指针变量作为函数的参数。当为二维数组时，形参为指向变量的指针变量，则为二维数组的列地址，当形参为指向数组名的指针变量，则为二维数组的行地址。

5.指针数组处理字符串内容。 []的优先度比*高，但是指针数组不能同其他数组一样进行自加自减等等。用指数组处理字符串时，数组存储的是字符串的起始地址。因此可以不对指针数组声名长度实现字符串变长。

6.学习了结构体定义，及结构体声名函数。联系了创建指针和指针的删除增加对结构体的运用。

7.算法题一定要注意画图帮助理解，避免总在细节上出错。

## 第三章学习:

### 目标：

- [ ] 抽象ADT
- [x] 对表的有效操作
- [ ] 栈ADT及其递归实现
- [ ] 队列ADT及其再操作系统的应用。

### C语言基础补齐：

1.申请链表的单元时，要malloc从系统调用一个新的单元

2.*//使用typedef 为node结构体取一个别名*

3. typedef struct Node *PtrToNode;// Node 类型指针的别名
   typedef PtrToNode Stack;//地址的别名？？区分！？

   如何区分 PtrToNode 与 Stack的关系。

4. 因为C语言没有类，所以结构体创造的对象，需要ADT也返回结构体类型，才能完成操作。

   

### 知识点：

#### 链表：

1.链表由一些列不咋内存中相连的结构组成

2.每个结构都含有表元素和指向包含该元素后继元的结构的指针。

##### 设计细节：

1.对与表头的插入和删除应该谨慎对待，疏忽会发生表的丢失。所以需要流出一个结点作为表头。

2.删除算法要求记住删除元素前的表元。

##### 常见错误：

1.出现mermory 或者 segmentation冲突多半为指针含有伪地址，通常因为地址初始化失败。

2.如何判断是否使用malloc函数、

   2.1创建一个指向结构的指针并不会创建一个结构，而是给出容纳结构的地址

  2.2malloc则是创建一个新的结构，并返回该结构的指针。需要注意的是malloc(szieof(PtrToNode))只为指针分配空间。而非指针。应当书写为： malloc(szieof(Struct PtrToNode))

##### 桶排序 radix sort：

一般采用多趟桶排序，从低位开始向高位相同数字落入一个桶

关键; 

桶的基数确认？

 基数与N^p-1范围内常数P的关系

#### 栈：

#####   设计细节：

##### 符号平衡：

仅需一次栈遍历，复杂度为N

##### 逆波兰表达式：

1.栈实现科学计算 ， 栈进行一次遍历即可

2.中缀表达式变为后缀表达式：

​    2.1  当遇到数字时，则直接输出

​    2.2当遇到操作符时，依据有优先度push 或 pop 

             1. 遇到右括号 pop直到左括
             2. 遇见有限度高的则弹出 直到剩下有限度低的。

#### 队列：

#### 实现细节：

1.循环数组，当front 或 rear越界时，重新赋值即可

2.要时刻注意队列是否为空，否则一个输出 会导致一个不确定的值

### 课后练习题：



### 遗留问题：

1.链表的游标

2.栈的函数调用

3.