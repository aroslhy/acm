#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 20000+5, MAXM = 50000+5;
const int INF = 0x3f3f3f3f;
int N, M;
int outdgr[MAXN], indgr[MAXN];
int v[MAXM], next[MAXM], head[MAXN], e;
int idx, cnt;
int dfn[MAXN], low[MAXN];
int belong[MAXN], amount[MAXN]; //对强连通分量染色(缩点)记录包含节点数
bool instack[MAXN];
stack<int> S;
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++idx;
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
    while (scanf("%d%d", &N, &M) != EOF)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        for (int i = 0; i < M; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        memset(dfn, -1, sizeof(dfn)); //Tarjan 初始化
        memset(instack, 0, sizeof(instack));
        idx = 0; cnt = 0;
        for (int u = 1; u <= N; u++)
            if (dfn[u] == -1)
                tarjan(u);
        if (cnt == 1)
        {
            printf("0\n");
            continue;
        }
        memset(outdgr, 0, sizeof(outdgr));
        memset(indgr, 0, sizeof(indgr));
        for (int u = 1; u <= N; u++) //统计缩点后的出度
            for (int i = head[u]; i != -1; i = next[i])
                if (belong[u] != belong[v[i]])
                {
                    outdgr[belong[u]]++;
                    indgr[belong[v[i]]]++;
                }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (!outdgr[i]) cnt1++;
            if (!indgr[i]) cnt2++;
        }
        int ans = max(cnt1, cnt2);
        printf("%d\n", ans);
    }
    return 0;
}
