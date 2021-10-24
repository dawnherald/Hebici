#include "stdio.h"
#include "stdlib.h"
void AdjustDown(int * a, size_t n, int parent)//向下调整
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        //找到最大的孩子
        if ((child + 1 < n) && (a[child + 1] > a[child]))
        {
            ++child;
        }
        //进行调整
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
void HeapSort(int * a, size_t n)//堆排序，升序，建大堆
{
    assert(a);
    for (int i = (n - 2) / 2; i >= 0; i--)//i定义为int ,不能定义为size_t,否则死循环，
    {                       //n为元素个数，不是最后一个元素的下表，所以用（n-2）/2
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);//从堆顶开始向下调整，因为有一半已经有序
        --end;
    }
}
int main()
{
}