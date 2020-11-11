#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;

int y[maxn];
int x[maxn];

int main(){
    int n;
    int ans1=0,ans2=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    int mid=y[n/2+1];
    for (int i=1;i<=n;i++){
        ans1+=abs(y[i]-mid);
    }
    for (int i=1;i<=n;i++)      //将各个士兵分配到每个x轴上的点
        x[i]-=i;
    sort(x+1,x+1+n);
    mid=x[n/2+1];
    for (int i=1;i<=n;i++)      //这里可以看到，|X0-k|+|（X1-1）-k|+ …… +|（Xn-1-（n-1））-k|，也是求中位数
        ans2+=abs(x[i]-mid);
    printf("%d\n",ans1+ans2);
    return 0;
}