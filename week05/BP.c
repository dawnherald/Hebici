#include<stdio.h>
#include<string.h> 
int main()
{
	int n, i, j, max = 0;//maxΪ�������ӵ���Ŀ 
	int a[1000];//����������Ʒ��
	int b[1005];//������������Ʒ����������¼װ��Ʒ�����ӣ�����������Ȼ����⣩ 
	int pox[10005];//���ӵ�λ�� 
	memset(pox, -1, sizeof(pox));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	pox[0] = 0;//�����ӵ�λ�ó�ʼ��Ϊ0����Ϊ����������±�ƥ�䣬��������λ�� 
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] + b[j] <= 100)
			{
				b[j] = b[j] + a[i];//��������Ʒ����һ�������� 
				b[i] = 0;//����ͬ����Ʒ����Ϣ 
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
