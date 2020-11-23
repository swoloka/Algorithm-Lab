#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
int a[1001];
int main()
{
    int t;
    scanf("%d", &t);
    // cin>> t;
    while (t--) {
        int n, i, j, m, ans = 0;
        scanf("%d", &n);
        // cin>>n;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            // cin>>a[i];
        }
        // sort(a + 1, a + 1 + n);
        m = n;
        while (m > 0) {             //一直做循环直到只有1、2或3个人，再直接退出循环
            if (m >= 4) {           //四个人的话，就先时间最少的两个人过去
                if (a[m] + a[m - 1] + (a[1] << 1) > a[2] + a[1] + a[m] + a[2]) {
                    ans += a[2] + a[1] + a[m] + a[2];
                } else {
                    ans += a[m] + a[m - 1] + (a[1] << 1);
                }
                m -= 2;
            } else if (m == 3) {
                ans += a[m] + a[1] + a[2];
                m = 0;
            } else if (m == 2) {
                ans += a[m];
                m = 0;
            } else if (m == 1) {
                ans += a[m];
                m = 0;
            }
        }
        printf("%d\n", ans);
        // cout<<ans<<endl;
    }
}

// #include <stdio.h>
// int main()
// {
//         int t[1001],T,j,i,n,sum;
//         scanf("%d",&T);
//         for(i=0;i<T;i++)
//         {
//                 scanf("%d",&n);
//                 for(j=0;j<n;j++)
//                         scanf("%d",&t[j]);
//                 sum=0;
//                 while(n>3)
//                 {
//                         if((t[0]+t[0]+t[n-2]+t[n-1])>(t[0]+t[n-1]+t[1]+t[1])) sum+=2*t[1]+t[n-1]+t[0];
//                         else sum+=2*t[0]+t[n-2]+t[n-1];
//                         n=n-2;
//                 }
//                 if(n==3) sum+=t[0]+t[1]+t[2];
//                 if(n==2) sum+=t[1];
//                 if(n==1) sum+=t[0];
//                 printf("%d\n",sum);
//         }
//         return 0;
// }