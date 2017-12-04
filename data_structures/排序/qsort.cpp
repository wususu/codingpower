#include <iostream>

using namespace std;

void qsort(int L[], int l, int h)
{
        std::cout<<l<<" "<<h<<std::endl;

    int k;
    int low = l, hight = h;
    if(low < hight)
    {
        k = L[low];
        while(low<hight)
        {
            while(low<hight && L[hight] >= k)
                hight--;
            L[low] = L[hight];

            while(low<hight && L[low] <= k)
                low++;
            L[hight] = L[low];
        }
        L[low] = k;
        qsort(L, l, low-1);
        qsort(L, low+1, h);
    }
}


int main()
{
    int L[13] = {1,2, 8, 9, 10, 11, 15, 13, 3, 5, 6, 7, 14};

    for(int i=0;i<13;i++)
    {
        cout<<L[i]<<" ";
    }
    cout<<endl;

    qsort(L, 0, 12); 
    for(int i=0;i<13;i++)
    {
        cout<<L[i]<<" ";
    }
    cout<<endl;

}