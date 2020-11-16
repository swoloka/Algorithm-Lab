#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define M 2009
#define INF 0x3f3f3f3f
struct edge
{
    int to,w;
};
bool inq[M];
vector <edge> g[M];
int dis[M];
int n,m;
void spfa(int s)
{
    for(int i = 1;i <= n;i++)
    {
        dis[i] = INF;
        inq[i] = false;
    }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while(!q.empty())
    {
        s = q.front();
        inq[s] = false;
        q.pop();
        for(int i = 0;i < g[s].size();i++)
        {
            int v = g[s][i].to;
            int w = g[s][i].w;
            if(dis[v] > dis[s]+w)
            {
                dis[v] = dis[s]+w;
                if(!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&m,&n)==2)  //m n写反了···· 贡献好几次WA
    {
        for(int i = 1;i <= n;i++)
            g[i].clear();
        for(int i = 0;i < m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            edge e;
            e.to = b;e.w = c;
            g[a].push_back(e);
            e.to = a;
            g[b].push_back(e);  //无向图 变化成双向的。
        }
        spfa(n);
        printf("%d\n",dis[1]);
    }
    return 0;
}