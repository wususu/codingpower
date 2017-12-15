#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

bool cmp_n(int a, int b)
{
    return a<b;
}

int main()
{
    int n, k, m, x=0, y=0, max=0, min=0;

    cin>>n;
    cin>>k;

    int a[n], a2[n+k];
    int b[n], c[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i] = c[i] = 0;
    }

    sort(a, a+n, cmp);
    for(int i=0;i<n;i++)
    {
        a2[n-i-1] = a[i];
    }
    m = n;
    while(m > 0)
    {
        b[x++] = a[0] + a[1];
        a[0] = b[x-1];
        a[1] = 0;
        sort(a, a+m, cmp);
        m--;
    }

    while (n % (k - 1) != 1)
    {
        a2[n]=0;
        n++;
    }
    sort(a2, a2+n, cmp_n);

    m = n;

    while(m>1)
    {
        if(m>=k)
        {
            for(int i=0;i<k;i++)
            {
                // cout<<a2[i]<<" ";
                c[y] += a2[i];
                a2[i] = INT_MAX;
            }
            // cout<<endl;
            a2[0] = c[y];
            
            sort(a2, a2+m, cmp_n);
            y++;
            m = m - k + 1;
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                // cout<<a2[i]<<" ";
                c[y] += a2[i];
                a2[i] = INT_MAX;
            }
            // cout<<endl;
            a2[0] = c[y]; 
            sort(a2, a2+m, cmp_n);            
            y++;
            m = 1;
        }
    }
    c[y] = a2[0];


    for(int i=0; i<y; i++)
    {
        min += c[i];
        // cout<<c[i]<<" ";
    }
    cout<<min<<" ";


    for(int i=0; i< x-1; i++)
    {

        max += b[i];
    }
    cout<<max<<endl;
}

// 11079 可移动的石子合并
/**
 * 
 * 
11079 可以移动的石子合并（优先做）
时间限制:1000MS  内存限制:1000K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
有n堆石子形成一行(a1,a2,…,an，ai为第i堆石子个数)，现要将石子合并成一堆，规定每次可
选择至少2堆最多k堆移出然后合并，每次合并的分值为新堆的石子数。

若干次合并后，石子最后肯定被合并为一堆，得分为每次合并的分值之和。

现在求解将这n堆石子合并成一堆的最低得分和最高得分。



输入格式
两行。第一行n和k。
第二行a1 a2 … an，每个ai(1<=i<=n)表示第i堆石子的个数，n<=200，2<=k<=n。


输出格式
仅一行，为石子合并的最低得分和最高得分，中间空格相连。


输入样例
7 3
45 13 12 16 9 5 22


输出样例
199 593
 **/

 // 每次取2个最大堆合并即可获得最高分
 // 每次取k个最小合并即可取得最小分(要保证最后一次合并也是k份, 所以要补零)