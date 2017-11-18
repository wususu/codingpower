#include <iostream>

using namespace std;


void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int find_same(char list[],int a,int i)
{
    for(int j=a; j<i; j++)
    {
        if(list[j] == list[i])
            return 1;
    }
    return 0;
}

int perm(char list[], int a, int b)
{
    int count = 0;
    if(a == b)
    {
        for(int i=0;i<=b;i++)
        {
            cout<<list[i];
        }
        cout<<endl;
        return 1;
    }
    else
    {
        for(int i=a; i<=b; i++)
        {
            if(find_same(list, a, i))
                continue;
            swap(list[i], list[a]);
            count += perm(list, a+1, b);
            swap(list[i], list[a]);
        }
    }
    return count;
}


int main()
{
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<perm(a,0,n-1)<<endl;
    return 0;
}


/**
有重复元素的排列问题

设集合R={r1,r2,...,rn}是要进行排列的n个元素，其中r1,r2,...,rn可能相同。
试着设计一个算法，列出R的所有不同排列。
即，给定n以及待排的n个可能重复的元素。计算输出n个元素的所有不同排列。



输入格式
第1行是元素个数n，1<=n<=15。接下来的1行是待排列的n个元素，元素中间不要加空格。


输出格式
程序运行结束时，将计算输出n个元素的所有不同排列。最后1行中的数是排列总数。

（说明：
此题，所有计算出的排列原本是无所谓顺序的。但为了容易评判，输出结果必须唯一！
现做约定：所有排列的输出顺序如课本例2-4的程序段的输出顺序，区别仅是这道题是含
重复元素。）


输入样例
4
aacc


输出样例
aacc
acac
acca
caac
caca
ccaa
6
*/

