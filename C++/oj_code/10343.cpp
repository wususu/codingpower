#include <iostream>

using namespace std;

int cache[30] = {0};

int diverse(int n)
{
    int sum = 0;

    if(n==2 || n==3)
    {
//        cout<<"end -- 1"<<endl;
        return 1;
    }
    if(cache[n] != 0)
    {
        sum = cache[n];
    }
    else
    {
        for(int i=2; i<n; i++)
        {
            sum += diverse(i) * diverse(n-i+1);
        }
        cache[n] = sum;
    }
//    cout<<"sum = "<<sum<<" | n = "<<n<<endl;
    return sum;

}


int main()
{
    int n;
    cin>>n;
    if(n < 3)
    {
    	cout<<"No answer"<<endl;
    	return 0;
    }
    cout<<diverse(n)<<endl;

    return 0;
}

/**
10343 凸多边形的划分

Description
问题描述：一个正凸N边形，可以用N-3条互不相交的对角线将正N边形分成N-2个三角形。
现在要求读入N边形的N（N≤20），输出不同划分方法的总数（要求解的是划分方法数，而不需要输出各种划分法）。

这里，注意：
（1）顶点编号，认为顶点皆不相同，因此不允许认为将凸N边形转置视为相同划分。
（2）若输出是“No answer”，请注意大小写和无标点。

输入输出举例：
输入: N＝3，            输出：1
输入: N＝5，		输出：5
输入: N＝2，		输出：No answer
输入: N＝6，		输出：14
输入: N＝8，		输出：132

例如：
当N＝5时，共有5种分法。
*/


/**
把一个正凸N边形的各个顶点按照顺时针分别编上1，2，……，N。
顶点1，顶点N和顶点I（I∈[2, N-1]）能够构成一个三角形S。
这样凸N边形就被分成三部分：一个三角形S、一个I边形和一个N+1-I边形（I, N+1-I∈[2, N-1]）。
因此，凸N边形分为三角形总数Total(N)等于I边形的分法总数乘以N+1-I边形的分法总数之积，还要
在I分别取2，3，……，N－1时都累加起来。

递推公式如下：
Total(N) = sum{ Total(I)*Total(N+1-I) | for I=2 to N-1}   if N>=4
Total(2) = Total(3) = 1

注意： 2点的多边形视为蜕化的多边形，定义其Total(2)=1，是为递推公式推导用。
但按题目意思当N=2时输出无解。
*/
