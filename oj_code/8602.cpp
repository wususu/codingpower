#include <iostream>
#include <stdlib.h>

using namespace std;

class Posi
{
public:
    int left;
    int right;
};

bool cmp(Posi a, Posi b)
{
    return a.right <= b.right;
}

int main()
{
    int n, count=1;
    cin>>n;
    Posi arr[n], temp, k;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].left;
        cin>>arr[i].right;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i].right > arr[j].right)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }



    k = arr[0];
    for(int i=1;i<n;i++)
    {
        if(k.right <= arr[i].left)
        {
            k = arr[i];
            count++;
        }
    }

    cout<<n-count<<endl;
    return 0;
}
// 8602 区间相交问题

/**
 * Description
给定x轴上n个闭区间，去掉尽可能少的闭区间，使剩下的闭区间都不相交。
注意：这里，若区间与另一区间之间仅有端点是相同的，不算做区间相交。例如，[1，2]和[2，3]算是不相交区间。 


输入格式
第一行一个正整数n(n<=50)，表示闭区间数。接下来n行中，每行2个整数，表示闭区间的2个整数端点。


输出格式
输出去掉的最少的闭区间数。


输入样例
3
10 20
10 15
12 15


输出样例
2
 * 
 **/

 // 因为去掉最少的区间一定是覆盖范围最大的,先算出最多的不相交的个数
 //先按右区间的大小排序,再依次记录不相交的区间个数,剩下的就是覆盖较大的区间