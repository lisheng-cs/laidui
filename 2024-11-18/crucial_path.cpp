#include <bits/stdc++.h>
const int MAXN = 100010;
int indegree[MAXN], topsort[MAXN];
int vearliest[MAXN]; // 记录每个顶点的最早发生时间
int vlatest[MAXN];   // 记录每个顶点的最晚发生时间
using namespace std;
// 邻接表指针版
typedef struct Node
{
    int v, w;
    Node *next;
} Node, *Pnode;
typedef struct Graph
{
    int n, e;
    Pnode head[MAXN];
} Graph;
// 边集数组存活动
int idx;
struct Edge
{
    int u, v, w;
} edge[MAXN];
void CreateGraph(Graph &g, Graph &rg)
{
    cin >> g.n >> g.e;
    for (int i = 0; i < g.n; i++)
        g.head[i] = nullptr;
    for (int i = 0; i < g.e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Pnode p = new Node;
        p->v = v;
        p->w = w;
        // 头插法
        p->next = g.head[u];
        g.head[u] = p;
        // 反向边
        Pnode q = new Node;
        q->v = u;
        q->w = w;
        q->next = rg.head[v];
        rg.head[v] = q;
        // 记录活动
        edge[idx].u = u;
        edge[idx].v = v;
        edge[idx].w = w;
        idx++;
    }
}
void CruicalPath(Graph &g, Graph &rg)
{
    memset(indegree, 0, sizeof(indegree));
    memset(vearliest, 0, sizeof(vearliest));
    memset(vlatest, 0x3f, sizeof(vlatest));
    for (int i = 1; i <= g.n; i++)
    {
        Pnode p = g.head[i];
        while (p)
        {
            indegree[p->v]++;
            p = p->next;
        }
    }
    queue<int> q;
    for (int i = 0; i < g.n; i++)
        if (indegree[i] == 0)
        {
            q.push(i);
            vearliest[i] = 0;
        }
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // 存拓扑排序结果，以便根据反图求最迟发生时间
        topsort[cnt++] = u;
        Pnode p = g.head[u];
        while (p)
        {
            vearliest[p->v] = max(vearliest[p->v], vearliest[u] + p->w);
            indegree[p->v]--;
            if (indegree[p->v] == 0)
                q.push(p->v);
            p = p->next;
        }
    }
    // 初始化汇点的最迟发生时间为最早发生时间, 一般情况下汇点只有一个（也就是任务的终点）
    vlatest[topsort[cnt - 1]] = vearliest[topsort[cnt - 1]];
    for (int i = cnt - 1; i >= 0; i--)
    {
        Pnode p = rg.head[topsort[i]];
        while (p)
        {
            vlatest[p->v] = min(vlatest[topsort[i]] - p->w, vlatest[p->v]);
            p = p->next;
        }
    }
    // 此时事件的最早发生时间和最迟发生时间已经求出来了
    // 接下来找到关键路径，也就是最早发生时间和最迟发生时间相等的活动
    for (int i = 0; i < idx; i++)
    {
        if (vearliest[edge[i].u] == vlatest[edge[i].v] - edge[i].w)
            cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl; // 关键路径活动
    }
}
void solve()
{
    Graph g, rg;
    CreateGraph(g, rg);
    CruicalPath(g, rg);
}
int main()
{
    solve();
    return 0;
}