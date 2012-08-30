//2012-08-30 15:29:13	Accepted	4039	671MS	16204K	3007 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 2000+5, MAXL = 15+5;
const int INF = 0x3f3f3f3f;
int T, N, Q, m[2], f[MAXN][MAXN];
int e, head[MAXN], next[MAXN], v[MAXN];
char t[MAXL], name[MAXN][MAXL];
bool vis[MAXN];
vector<int> ans;
queue<pair<int, int> > que;
map<string, int> mp;
bool cmp(const int a, const int b)
{
    return strcmp(name[a], name[b]) < 0;
}
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e++;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));
    mp.clear();
}
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        init();
        scanf("%d%d", &N, &Q);
        int n = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%s", t);
                m[j] = mp[(string)t];
                if (!m[j])
                {
                    mp[(string)t] = m[j] = ++n;
                    strcpy(name[n], t);
                }
            }
            addedge(m[0], m[1]);
            addedge(m[1], m[0]);
        }
        for (int i = 1; i <= n; i++)
        {
            fill(vis+1, vis+1+n, 0);
            que.push(make_pair(i, 0));
            vis[i] = 1;
            while (!que.empty())
            {
                int u = que.front().first, s = que.front().second;
                que.pop();
                for (int j = head[u]; j != -1; j = next[j]) if (!vis[v[j]])
                {
                    if (s == 1)
                        f[i][v[j]]++;
                    else
                    {
                        que.push(make_pair(v[j], s+1));
                        vis[v[j]] = 1;
                    }
                }
            }
        }
        printf("Case %d:\n", cas);
        for (int i = 1; i <= Q; i++)
        {
            scanf("%s", t);
            int m = mp[(string)t];
            ans.clear();
            for (int j = 1; j <= n; j++) if (f[m][j])
            {
                if (!ans.size() || f[m][j] == f[m][ans[0]])
                    ans.push_back(j);
                else if (f[m][j] > f[m][ans[0]])
                {
                    ans.clear();
                    ans.push_back(j);
                }
            }
            if (ans.size())
            {
                sort(ans.begin(), ans.end(), cmp);
                for (int j = 0; j < (int)ans.size(); j++)
                {
                    if (j)
                        printf(" ");
                    printf("%s", name[ans[j]]);
                }
            }
            else
                printf("-");
            printf("\n");
        }
    }
    return 0;
}
