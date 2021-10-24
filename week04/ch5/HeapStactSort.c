#include "stdio.h"
#include "stdlib.h"
void AdjustDown(int * a, size_t n, int parent)//���µ���
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        //�ҵ����ĺ���
        if ((child + 1 < n) && (a[child + 1] > a[child]))
        {
            ++child;
        }
        //���е���
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int * a, size_t n)//���������򣬽����
{
    assert(a);
    for (int i = (n - 2) / 2; i >= 0; i--)//i����Ϊint ,���ܶ���Ϊsize_t,������ѭ����
    {                       //nΪԪ�ظ������������һ��Ԫ�ص��±������ã�n-2��/2
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);//�ӶѶ���ʼ���µ�������Ϊ��һ���Ѿ�����
        --end;
    }
}
int main()
{
}