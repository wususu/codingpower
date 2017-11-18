#include <iostream>

using namespace std;


int search(int x[], int y[], int ms, int md, int ns, int nd, int k)
{
/**
    cout<<"k: "<<k<<endl;
    cout<<"x: ";
    for(int i=ms;i<=md;i++)
    {
    	cout<<x[i]<<" ";
    }
    cout<<endl<<"y: ";
    for(int i=ns;i<=nd;i++)
    {
    	cout<<y[i]<<" ";
    }
    cout<<endl;
*/
    if(ms>md)
    {
        return y[ns + k -1];
    }
    if(ns>nd)
    {
        return x[ms + k -1];
    }
    int m_mid = ms + (md-ms)/2;
    int n_mid = ns + (nd-ns)/2;
    int h_len = m_mid - ms + n_mid - ns +2;

    if(x[m_mid] >= y[n_mid])
    {
        if(k >= h_len)
        {
            return search(x, y, ms, md, n_mid+1, nd, k-(n_mid-ns+1));
        }
        else
        {
            return search(x, y, ms, m_mid-1,ns, nd, k);
        }
    }
    else
    {
        if(k >= h_len)
        {
            return search(x, y, m_mid+1, md, ns, nd, k-(m_mid-ms+1));
        }
        else
        {
            return search(x, y, ms, md, ns, n_mid-1, k);
        }
    }

}

int main()
{
    int m,n,k;
    cin>>m;
    cin>>n;
    cin>>k;
    int x[m],y[n];
    for(int i=0;i<m;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }
    cout<<search(x, y,0, m-1,0, n-1,k);
    return 0;
}

/**
两个有序数中找第k小

已知两个已经排好序（非减序）的序列X和Y，其中X的长度为m，Y长度为n，
现在请你用分治算法，找出X和Y的第k小的数，算法时间复杂度为O(max{logm, logn})。

此题请勿采用将序列X和Y合并找第k小的O(m+n)的一般方法，要充分利用X和Y已经排好序的这一特性。
8/

/**
将序列X和Y都均分2段，即取X序列中间位置为 xMid (xMid = xBeg+(xEnd-xBeg)/2)，也同理取序列Y中间位置为yMid。
比较X[xMid]和Y[yMid]的大小，此时记录X左段和Y左段元素个数合计为halfLen，即halfLen = xMid-xBeg+yMid-yBeg+2。

1. 当X[xMid] < Y[yMid]时，在合并的数组中，原X[xBeg...xMid]所有元素一定在Y[yMid]的左侧，
   （1） 若k < halfLen，则此时第k大的元素一定不会大于Y[yMid]这个元素，
         故以后没有必要搜索 Y[yMid...yEnd]这些元素，可弃Y后半段数据。
         此时只需递归的对X序列+Y序列的前半段，去搜索第k小的数。

   （2） 若k >= halfLen，则此时第k大的元素一定不会小于X[xMid]这个元素，
         故以后没有必要搜索 X[xBeg...xMid]这些元素，可弃X前半段数据。
         此时只需递归的对X序列的后半段+Y序列，去搜索第 k-(xMid-xBeg+1）小的数
2. X[xMid] >= Y[yMid]同理

*/


