#include <iostream>
#include <stdlib.h>
using namespace std;


int cmp ( const void *a , const void *b )
{ return *(int *)a - *(int *)b; }

int main()
{
    int n, x=0, count=0, pre = 0, le = 8;
    cin>>n;

    int h[n+1];
    for(int i=0; i<n; i++)
    {/
        cin>>h[i];
    }
    qsort(h,n, sizeof(h[0]), cmp);


    count++;
    for(int i=1 ;i<n; i++)
    {
        pre = h[i] - h[i-1];
        if(pre <= le)
        {
            le -= pre;
            continue;
        }
        else
        {
            count++;
            le = 8;
        }
    }
    cout<<count<<endl;
    return 0;
}

// 17103 基站建设
/**
 * 
 * Description
一条很长的乡村公路（我们可以想象这条公路是一条长线段，有一个西端点和一个东端点），公路旁稀疏的分布着一些房子。
我们把公路的西端点固定在坐标0上，东端点为某远处。
假设这些房子的居民都使用蜂窝移动电话，现在需要把移动电话基站放在这条路旁的某些点上，使得每个房子都在其中一个
基站4公里之内。

注意：房子和基站都建立在公路旁而不远离公路，即可以认为房子和基站都是公路直线上的点。

给出一个有效算法，使得用尽可能少的基站来实现这个目标。



输入格式
第一行，房子的数量n （n<=100000）
第二行，房子分布的位置：h1 h2 ... hn


输出格式
最少的基站数量，所有房子都能覆盖在某个基站之下（基站的有效距离为4公里）。


输入样例
6
1 12 8 3 4 15


输出样例
2
**/