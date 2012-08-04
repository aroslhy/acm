#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 26+5;
const int INF = 0x3f3f3f3f;
int n, g[MAXN][MAXN], mark[MAXN];
bool vis[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%d", &n) && n)
    {
        memset(g, 0, sizeof(g));
        memset(mark, 0, sizeof(mark));
        for (int i = 1; i <= n; i++)
        {
            char s[MAXN];
            scanf("%s", s);
            int len = strlen(s);
            for (int i = 2; i < len; i++)
                g[s[0]-'A'][s[i]-'A'] = g[s[i]-'A'][s[0]-'A'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < n; j++) if (g[i][j] && mark[j])
                vis[mark[j]] = 1;
            for (int j = 1; ; j++) if (!vis[j])
            {
                mark[i] = j;
                break;
            }
            ans = max(ans, mark[i]);
        }
        printf("%d channel%s needed.\n", ans, ans > 1 ? "s" : "");
    }
    return 0;
}
