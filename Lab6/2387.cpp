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


//dijkstra算法

// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// #include<cmath>
// #define CLR(x) memset(x,0,sizeof(x))
// using namespace std;
// const int INF = 100000;
// const int maxp = 1100;
// const int maxl = 1000000;
// int edge[maxp][maxp];
// int dist[maxp];
// int vis[maxp];
// int p,l;

// int dijkstra(int x)       //磁少风格版
// {
//     for(int i = 1 ; i <= p ; i++)
//         dist[i] = INF;
//     int v = x;
//     dist[v]=0;
//     vis[v]=1;
//     for(int i = 1 ; i <= p ; i++)
//     {
//         for(int j = 1; j <= p ; j++)
//         {
//             if(vis[j]!=1 && dist[v]+edge[v][j] < dist[j])
//             {
//                 dist[j] = dist[v] + edge[v][j];
//             }

//         }
//         int minn = INF;
//         for(int j = 1 ; j <= p ; j++)
//             if(vis[j]!=1 && dist[j] < minn)
//             {
//                 minn=dist[j];
//                 v=j;
//             }
//         vis[v]=1;
//     }
// }

// int main()
// {
//     while(scanf("%d%d",&l,&p)!= EOF)
//     {
//         for(int i = 0 ; i < maxp ; i++)
//         {
//             for(int j = 0 ; j < maxp ; j++)
//             {
//                 edge[i][j] = INF;
//             }
//             edge[i][i] = 0;// 因为可能输入重复两条边的值我们需要选出同样的边最小的那一个值；
//         }
//         CLR(vis);
//         for(int i = 1 ; i <= l ; i++)
//         {
//             int u,v,w;
//             scanf("%d %d %d",&u,&v,&w);
//             if(edge[u][v] > w)
//             {
//                 edge[u][v] = edge[v][u] = w;
//             }
//         }
//         dijkstra(1);
//         printf("%d\n",dist[p]);
//     }

// }
