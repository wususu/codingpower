#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n;
    int v[n+1],k[n+1];
    v[0] = k[0] =0;
    // 面值
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    // 张数
    for(int i=1; i<=n; i++)
    {
        cin>>k[i];
    }
    cin>>m;
    unsigned int d[n+1][m+1],c[n+1][m+1];
    // 初始化分法数组
    for(int i=0; i<=m; i++)
    {
        d[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        d[i][0] = 1;
    }
    for(int i=1; i<=m; i++)
    {
        if(i%v[1] == 0 && i/v[1] <= k[1])
        {
            d[1][i] = 1;
        }
        else 
        {
            d[1][i] = 0;
        }
    }
    // 初始化最少张数数组
    for(int i=0; i<=n; i++)
    {
        c[i][0] = 0;
    }
    for(int i=1; i<=m; i++)
    {
        if (i%v[1] == 0 && i/v[1] <= k[1])
        {
            c[1][i] = i/v[1];
        }
        else
        {
            c[1][i] = INT_MAX;
        }

    }

    // dp
    for(int j=2; j<=n; j++)
    {
        for(int i=1; i<=m; i++)
        {
            c[j][i] = INT_MAX;
            int t = min(i/v[j], k[j]);
            for(int x=0; x<=t; x++)
            {
                int temp = x+c[j-1][i-x*v[j]];
                c[j][i] = temp < c[j][i]? temp: c[j][i];  
            }

            // 当前金额与纸币面值的倍数
            int times = i/v[j];
            // 前一种金额的组合总数
            d[j][i] = d[j-1][i];
            // 倍数受该纸币的张数限制
            times = times > k[j] ? k[j] : times;
            for(int x=1;x<=times; x++)
            {
                d[j][i] += d[j-1][i-x*v[j]];
            }
        }
    }

    cout<<d[n][m]<<endl;
    if(d[n][m] == 0)
    {
        cout<<"no possible"<<endl;
    }else{
        cout<<c[n][m]<<endl;
    }
        
//DEBUG

    // cout<<"  ";
    // for(int i=0;i<=m;i++)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<v[i]<<" ";
    //     for(int j=0;j<=m;j++)
    //         cout<<d[i][j]<<" ";    
    //     cout<<endl;
    // }
    //         cout<<endl;


    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1; j<=m; j++)
    //     {
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"k: "<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<k[i]<<" ";
    // }
    // cout<<endl;

    //     cout<<"v: "<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;


}

// 8595 钱币组合问题
/**
 * 设有n种不同的钱币各若干，可用这n种钱币产生许多不同的面值。
如给定面值7分，有1分3张，2分3张，5分1张，能组成给定面值7分的方法有如下4种：
3个1分+2个2分；   5个；
1个1分+3个2分；   4个；
2个1分+1个5分；   3个；
1个2分+1个5分；   2个。

上面4种方案的最少张数为2个。

你的编程任务：给定面值m，和n种不同面值钱币及其张数，
（1） 求给定面值m能有多少种不同的构成方法数。
（2） 求给定面值m最少要多少张。



输入格式
第1行有1个正整数n(1<=n<=50)，表示有n种不同的钱币。
第2行有n个数，分别表示每种钱币的面值v[1]...v[n](0<=v[i]<=100,1<=i<=n)。
第3行有n个数，分别表示每种钱币的张数k[1]...k[n](0<=k[i]<=100,1<=i<=n)。
第4行有1个数，表示给定的面值m (1<=m<=20000)。
*/

/**
 * 
d[i,0] = 1,  if 1<=i<=n
d[1,j] = 1,  if j%v[1]=0 && j/v[1]<=k[1];
d[1,j] = 0,  if j%v[1]!=0 || j/v[1]>k[1] || j<0;

if i>1 && j1 && v[i]<=j<2*v[i]
d[i,j] = d[i-1,j] + d[i-1,j-v[i]]

if i>1 && 2*v[i]<=j<3*v[i]
d[i,j] = d[i-1,j] + d[i-1,j-v[i]] + d[i-1,j-2*v[i]]

......

if i>1 && k[i]*v[i]<=j<=m
d[i,j] = d[i-1,j] + d[i-1,j-1*v[i]] + d[i-1,j-2*v[i]] + ... + d[i-1,j-k[i]*v[i]]


t = min{ (int)(j/v[i]), k[i] }，表示第i种钱币最多加入的张数。
c[i][j] = min{ p+c[i-1][j-p*v[i]] | p from 0 to t }，这里p表示第i种币值选入的张数，
                                                         t表示第i种币值最多选入的张数。
//这里要注意，要保证 j-p*v[i]>=0 才有意义，对可能的越界（无论是左边越界还是右边越界），都要仔细审查。

初始条件：
c[i][0]=0, 1<=i<=n
c[1][j]=int(j/v[1]),   if j%v[1]==0 && j/v[1]<=k[1]
c[1][j]=MAXINT,        if j%v[1]!=0 || j/v[1]>k[1] 
*/
