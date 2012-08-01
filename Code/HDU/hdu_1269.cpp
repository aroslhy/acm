#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 10000+5, MAXM = 100000+5;
int N, M;
int v[MAXM], next[MAXM], head[MAXN], e;
int index, cnt;
int dfn[MAXN], low[MAXN];
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
        for (;;)
        {
            int x = S.top(); S.pop();
            instack[x] = 0;
            if (x == u) break;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &M))
    {
        if (!N && !M) break;
        memset(head, -1, sizeof(head));
        e = 0;
        for (int i = 0; i < M; i++)
        {
            int A, B;
            scanf("%d%d", &A, &B);
            addedge(A, B);
        }
        memset(dfn, -1, sizeof(dfn)); //Tarjan³õÊ¼»¯
        memset(instack, 0, sizeof(instack));
        index = 0; cnt = 0;
        for (int u = 1; u <= N; u++)
            if (dfn[u] == -1)
                tarjan(u);
        printf(cnt == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}
