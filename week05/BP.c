#include<stdio.h>
#include<string.h> 
int main()
{
	int n, i, j, max = 0;//max为所用箱子的数目 
	int a[1000];//用来接收物品的
	int b[1005];//即用来描述物品，又用来记录装物品的箱子（看完代码后自然会理解） 
	int pox[10005];//箱子的位置 
	memset(pox, -1, sizeof(pox));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	pox[0] = 0;//将箱子的位置初始化为0，是为了与数组的下标匹配，更方便标记位置 
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] + b[j] <= 100)
			{
				b[j] = b[j] + a[i];//将两个物品放在一个箱子中 
				b[i] = 0;//用于同步物品的信息 
				pox[i] = j;
				break;
			}
			else
			{
				pox[i] = i;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (pox[i] > max)
		{
			max = pox[i];
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", a[i], pox[i] + 1);
	}
	printf("%d", max + 1);
	return 0;
}
