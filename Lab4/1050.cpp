#include<iostream>
#include<cstring>

using namespace std;

// int MaxSub(int a[],int n){      //求最大子数组函数，思路源自leetcode
//     int sum = 0;
//     int max = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (a[i] + a[i-1] > a[i])
//         {
//             a[i] += a[i-1];
//         }
//         if(a[i] > max)
//             max = a[i];
//     }
//     return max;
// }

int MaxSub(int a[],int n)
{
    int i,max=0,b=0;
    for(i=0;i<n;i++)
    {
        if(b > 0)
            b += a[i];
        else
            b = a[i];
        if(b > max)
            max = b;
    }
    return max;
}

int main(){
    int n,i,j,k,maxMatrix,maxsubarr;
    int dp[101][101],arr[101];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>dp[i][j];
        maxMatrix = 0;
        for(i=0;i<n;i++)
        {
            memset(arr,0,sizeof(arr));
            for(j=i;j<n;j++)
            {
                for(k=0;k<n;k++)
                    arr[k] += dp[j][k];     //将多个行转化为1行，因为此处k[n]只有0～n-1一共n项，每次会把先前的行加到新行
                maxsubarr = MaxSub(arr,n);  //每次合并一行之后都会重新计算数组
                if(maxsubarr > maxMatrix)
                    maxMatrix = maxsubarr;  //这里不断判断最大的sum
            }
        }
        cout<<maxMatrix<<endl;
    }
}