#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int a[102][102],n,m;
int f[102][102];
int dp(int x,int y)
{
    if(f[x][y]) return f[x][y];
    f[x][y]=1;
    if(a[x-1][y]<a[x][y] && x>1) f[x][y]=max(f[x][y],dp(x-1,y)+1);
    if(a[x+1][y]<a[x][y] && x<n) f[x][y]=max(f[x][y],dp(x+1,y)+1);
    if(a[x][y-1]<a[x][y] && y>1) f[x][y]=max(f[x][y],dp(x,y-1)+1);
    if(a[x][y+1]<a[x][y] && y<m) f[x][y]=max(f[x][y],dp(x,y+1)+1);
    return f[x][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=dp(i,j);
            ans=max(f[i][j],ans);
        }
    printf("%d\n",ans);
    return 0;
}



/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn][maxn], f[maxn][maxn];
int R, C;

inline char getc(void)
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	if(p1 == p2){
		p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
		if(p1 == p2) return EOF;
	}
	return *p1++;
}

inline void read(int& x)
{
	x = 0; int f = 1; char ch = getc();
	for(;!(ch>='0' && ch<='9');ch=getc()) if(ch == '-') f = -1;
	for(;(ch>='0' && ch <='9');x=x*10+ch-'0', ch=getc());
	x *= f;
}

inline int dp(int i, int j)
{
	if(f[i][j] > 1) return f[i][j];
	int maxx = 1;
	if(a[i][j] > a[i][j-1] && j-1 >= 0)
		maxx = max(maxx, dp(i, j-1) + 1);
	if(a[i][j] > a[i][j+1] && j+1 < C)
		maxx = max(maxx, dp(i, j+1) + 1);
	if(a[i][j] > a[i-1][j] && i-1 >= 0)
		maxx = max(maxx, dp(i-1, j) + 1);
	if(a[i][j] > a[i+1][j] && i+1 < R)
		maxx = max(maxx, dp(i+1, j) + 1);
	return maxx;
}

int main()
{
	read(R); read(C);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			read(a[i][j]), f[i][j] = 1;
	int maxx = 0;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			maxx = max(maxx, (f[i][j] = dp(i, j)));
	printf("%d\n", maxx);
}

*/