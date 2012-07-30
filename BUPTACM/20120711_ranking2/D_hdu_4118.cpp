#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 100000+5, MAXM = 100000*2+5;
int T, N, X, Y, Z;
int e, head[MAXN], next[MAXM], v[MAXM];
long long w[MAXM], ans;
int cnt[MAXN];
bool vis[MAXN], ins[MAXN];
stack<int> sta;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
void dfs()
{
    sta.push(1);
    vis[1] = 1;
    ins[1] = 1;
    while (!sta.empty())
    {
        int u = sta.top();
        cnt[u] = 1;
        for (int i = head[u]; i != -1; i = next[i]) if (!vis[v[i]])
        {
            sta.push(v[i]);
            vis[v[i]] = 1;
            ins[v[i]] = 1;
        }
        if (u == sta.top())
        {
            for (int i = head[u]; i != -1; i = next[i]) if (!ins[v[i]])
            {
                ans += min(cnt[v[i]], N-cnt[v[i]])*2*w[i];
                cnt[u] += cnt[v[i]];
            }
            sta.pop();
            ins[u] = 0;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        e = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &N);
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &X, &Y, &Z);
            addedge(X, Y, Z);
            addedge(Y, X, Z);
        }
        ans = 0;
        dfs();
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}

