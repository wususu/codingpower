#include <iostream>
#include <string>

using namespace std;


int main()
{
    string a,b,k;
    int count = 0, flag;
    cin>>a;
    cin>>b;
    k = a;
    int a_length = a.length();
    int b_length = b.length();

    int c[a_length+2][b_length+2];
    for(int i=0; i<=a_length;i++)
        c[i][0] = 0;

    for(int i=0; i<=b_length;i++)
        c[0][i] = 0;

    for(int i=0;i<a_length; i++){
        for(int j=0;j<b_length;j++){
            if(a[i] == b[j]){
                c[i+1][j+1] = c[i][j] + 1;
                if(c[i+1][j+1]>count)
                {
                    count = c[i+1][j+1];
                    flag = i-count+1;
                }
            }
            else
            {
                c[i+1][j+1] = 0;
            }
        }
    }
    // for(int i=0;i<=a_length;i++){
    //     cout<<a[i]<<"  ";
    //     for(int j=0; j<=b_length; j++){
    //         cout<<c[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<count<<endl;
    cout<<k.substr(flag, count)<<endl;

    return 0;
}

/**
 * 11077 最长公共子字符串
 * 求两个输入序列的最长的公共子字符串的长度。子字符串中的所有字符在源字符串中必须相邻。
 * 如字符串：21232523311324和字符串312123223445，他们的最长公共子字符串为21232，长度为5。
 **/
/**
 *建立二维数组存储路径
 * */
