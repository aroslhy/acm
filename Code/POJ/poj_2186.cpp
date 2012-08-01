#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 10000+5, MAXM = 50000+5;
int N, M;
int outdgr[MAXN];
int v[MAXM], next[MAXM], head[MAXN], e;
int index, cnt;
int dfn[MAXN], low[MAXN];
int belong[MAXN], amount[MAXN]; //对强连通分量染色（缩点）、记录包含节点数
bool instack[MAXN];
stack<int> S;
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    S.push(u);
    instack[u] = 1;
    for (int i = head[u]; i != -1; i = next[i])
    {
        if (dfn[v[i]] == -1)
        {
            tarjan(v[i]);
            low[u] = min(low[u], low[v[i]]);
        }
        else if (instack[v[i]])
            low[u] = min(low[u], dfn[v[i]]);
    }
    if (low[u] == dfn[u])
    {
        cnt++;
        for (int c = 1; ; c++)
        {
            int x = S.top(); S.pop();
            instack[x] = 0;
            belong[x] = cnt;
            if (x == u)
            {
                amount[cnt] = c;
                break;
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(head, -1, sizeof(head));
    e = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d%d", &A, &B);
        addedge(A, B);
    }
    memset(dfn, -1, sizeof(dfn)); //Tarjan初始化
    memset(instack, 0, sizeof(instack));
    index = 0; cnt = 0;
    for (int u = 1; u <= N; u++)
        if (dfn[u] == -1)
            tarjan(u);
    memset(outdgr, 0, sizeof(outdgr));
    for (int u = 1; u <= N; u++) //统计缩点后的出度
        for (int i = head[u]; i != -1; i = next[i])
            if (belong[u] != belong[v[i]])
                outdgr[belong[u]]++;
    int ans = 0;
    for (int i = 1; i <= cnt; i++) if (!outdgr[i])
    {
        if (!ans)
            ans = amount[i];
        else
        {
            ans = 0;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
