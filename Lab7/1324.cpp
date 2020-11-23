#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>//队列

using namespace std;

const int MAX_S = (1 << 14) + 100; //蛇的最大状态数（压缩后）
const int MAX_N = 20 + 2; //洞穴最大的长宽
const int INF = (1 << 29); //最大步数上限

struct State
{
   int x, y, dis, s;
   State(int x = 0, int y = 0, int dis = 0, int s = 0) : x(x), y(y), dis(dis), s(s) {};
};

struct Point
{
   int x, y;
};

int N, M, res, L;
int vis[MAX_N][MAX_N][MAX_S];//蛇的位置状态存储
int fx[4] = { -1, 0, 1, 0 };
int fy[4] = { 0, 1, 0, -1 };
bool _map[MAX_N][MAX_N];//存储石头位置
Point pos[MAX_N * MAX_N];//存储蛇的位置
queue <State> Q;

int get_start()//取得蛇的初始状态
{
   int dir, dx, dy, s = 0;
   for (int i = L - 1; i > 0; i--)//i = L-1~1
   {
       dx = pos[i].x - pos[i - 1].x, dy = pos[i].y - pos[i - 1].y;
       if (dx == 0 && dy == 1)//
           dir = 1;
       else if (dx == 0 && dy == -1)
           dir = 3;
       else if (dx == -1 && dy == 0)
           dir = 0;
       else if (dx == 1 && dy == 0)
           dir = 2;
       s = s << 2;
       s = s | dir;//只需要两位来保存相邻的关系 最低位保存头和头下一个的关系 最高位保存尾和尾上一个的关系
       //蛇移动一步只需将该数据向左移动两位 更改新头和头下一位的关系
   }
   return s;
}
int get_next_state(int i, int s)//i代表蛇头走的方向，s代表蛇的当前状态
{
   int dir;
   int k = (1 << ((L - 1) << 1)) - 1;//L代表蛇的大小，K可以得到（l-1）个1
   int dx = 0, dy = 0;
   dx = dx - fx[i], dy = dy - fy[i];
   if (dx == 0 && dy == 1)
       dir = 1;
   else if (dx == 0 && dy == -1)
       dir = 3;
   else if (dx == -1 && dy == 0)
       dir = 0;
   else if (dx == 1 && dy == 0)
       dir = 2;
   s = s << 2;
   s = s | dir;
   s = s & k; //去除高位无用部分
   return s;
}

bool judge_code(int x, int y, int pre_x, int pre_y, int s)
{
   int dir;
   for (int i = 0; i < L - 1; i++)
   {
       dir = 3;
       dir = dir & s; //取s最低两位即上一个头和下一个头的关系也即上一次蛇头移动的方向
       s = s >> 2;
       if (x == pre_x + fx[dir] && y == pre_y + fy[dir]) //判断蛇身是否有重合
           return false;
       pre_x = pre_x + fx[dir], pre_y = pre_y + fy[dir];
   }
   return true;
}

void BFS()
{
   State a;
   int dx, dy, s;
   while (!Q.empty())
   {
       a = Q.front();
       Q.pop();
       for (int i = 0; i < 4; i++)//每次都向四个方向试探
       {
           dx = a.x + fx[i], dy = a.y + fy[i]; //下一次蛇头的x、y值，i用来确定方向
           s = get_next_state(i, a.s);
           if (dx > 0 && dy > 0 && dx <= N && dy <= M && !vis[dx][dy][s] && !_map[dx][dy] && judge_code(dx, dy, a.x, a.y, a.s))
           //蛇头的x、y必须在矩阵内部且试探后的状态没有经历过且没有石头且没有与之前的蛇身重合
           {
               if (dx == 1 && dy == 1) //到达出口则直接返回，此时层数必然是最少的，也就是说路径最短
               {
                   res = a.dis + 1;
                   return;
               }
               vis[dx][dy][s] = 1; //已经历过的状态
               Q.push(State(dx, dy, a.dis + 1, s)); //每次已经走过的路径长度加一
           }
       }
   }
}

int main()
{
   int s = 0, _case = 0;
   State _start;
   while (scanf("%d%d%d", &N, &M, &L), N + M + L) //输入行列数和蛇的长度
   {
       res = INF;
       memset(_map, 0, sizeof(_map)); //石头位置初始化
       memset(vis, 0, sizeof(vis)); //已经经历的状态初始化
       for (int i = 0; i < L; i++)
           scanf("%d%d", &pos[i].x, &pos[i].y); //当前蛇的位置
       int K, u, v;
       scanf("%d", &K); //石头数
       for (int i = 0; i < K; i++)
       {
           scanf("%d%d", &u, &v);
           _map[u][v] = 1; //石头的位置
       }
       if (pos[0].x == 1 && pos[0].y == 1) //蛇头已经在出口处
       {
           printf("Case %d: 0\n", ++_case);
           continue; //直接到下一轮输入
       }
       s = get_start();//蛇的初始状态
       Q.push(State(pos[0].x, pos[0].y, 0, s)); //初始位置和状态进入队列
       vis[pos[0].x][pos[0].y][s] = 1; //vis[蛇头行][蛇头列][蛇状态]蛇的初始状态经历
       BFS(); //广度优先搜索
       if (res == INF) 
           printf("Case %d: -1\n", ++_case);
       else
           printf("Case %d: %d\n", ++_case, res);//输出最短路径
       while (!Q.empty()) //队列清空
           Q.pop();
   }
   return 0;
}