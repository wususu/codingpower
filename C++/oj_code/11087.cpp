#include <iostream>

using namespace std;

void swap(int a[], int p, int q)
{
    int temp;
    temp = a[p];
    a[p] = a[q];
    a[q] = temp;
}

int merge_inversion(int a[], int l, int m, int h)
{
    int count = 0,b[h-l+2];
    int j = m+1, i=l, k=0;
    while(i<=m&&j<=h)
    {
        if(a[i] > a[j])
        {
            count += m-i+1;
            b[k++] = a[j++];
        }
        else
        {
            b[k++] = a[i++];
        }
    }
    while(i<=m)
    {
        b[k++] = a[i++];
    }
    while(j<=h)
    {
        b[k++] = a[j++];
    }
    for(i=h;i>=l;i--)
    {
        a[i] = b[--k];
    }
    return count;
}
int count_inversion(int a[], int low, int hight)
{
    int count = 0,temp,middle;
    if(hight-low == 1)
    {
        if(a[hight] < a[low])
        {
            swap(a, hight, low);
            return 1;
        }
        return 0;

    }
    if(low < hight)
    {
        middle = low + (hight - low)/2;
        count += count_inversion(a, low, middle);
        count += count_inversion(a, middle+1, hight);
        count += merge_inversion(a, low, middle, hight);
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<count_inversion(a, 0, n-1)<<endl;
    return 0;
}

/**
*
统计逆序对:

Description
设a[0…n-1]是一个包含n个数的数组，若在i<j的情况下，有a[i]>a[j]，则称(i, j)为a数组的一个逆序对（inversion）。
比如 <2,3,8,6,1> 有5个逆序对。请采用类似“合并排序算法”的分治思路以O(nlogn)的效率来实现逆序对的统计。

一个n个元素序列的逆序对个数由三部分构成：
（1）它的左半部分逆序对的个数，（2）加上右半部分逆序对的个数，（3）再加上左半部分元素大于右半部分元素的数量。
其中前两部分（1）和（2）由递归来实现。要保证算法最后效率O(nlogn)，第三部分（3）应该如何实现？

此题请勿采用O(n^2)的简单枚举算法来实现。

并思考如下问题：
（1）怎样的数组含有最多的逆序对？最多的又是多少个呢？
（2）插入排序的运行时间和数组中逆序对的个数有关系吗？什么关系？
*/

/**
*
确定n个元素的逆序对数目在最坏情况O(nlogn)的算法，可以考虑仿归并排序中的分治算法：一个序列的逆序对
个数由三部分构成：
（1）它的左半部分逆序对的个数，
（2）加上右半部分逆序对的个数，
（3）再加上左半部分元素大于右半部分元素的数量。
	在(1)(2)中分段排序,则(3)得到的两段数据都是有序的,实现O(n),再将两段数据排序,覆盖原数组
其中（1）和（2）由递归来实现，（3）计算后加入。

*/
