#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX = 50, INF = 0x3f3f3f3f;
int T, n, m, N;
int s, t, cap[MAX][MAX];
int a[MAX], p[MAX], flow[MAX][MAX];
queue<int> Q;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        s = m+7; t = m+8; N = m+8;
        memset(cap, 0, sizeof(cap));
        for (int i = 1; i <= 6; i++)
            cap[s][m+i] = n/6;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                char s[10]; scanf("%s", s);
                if (!strcmp(s, "XXL"))
                    cap[m+1][i] = 1;
                else if (!strcmp(s, "XL"))
                    cap[m+2][i] = 1;
                else if (!strcmp(s, "L"))
                    cap[m+3][i] = 1;
                else if (!strcmp(s, "M"))
                    cap[m+4][i] = 1;
                else if (!strcmp(s, "S"))
                    cap[m+5][i] = 1;
                else if (!strcmp(s, "XS"))
                    cap[m+6][i] = 1;
            }
            cap[i][t] = 1;
        }
        int ans = 0;
        memset(flow, 0, sizeof(flow));
        for(;;)
        {
            memset(a, 0, sizeof(a));
            a[s] = INF;
            Q.push(s);
            while(!Q.empty())
            {
                int u = Q.front(); Q.pop();
                for(int v = 1; v <= N; v++)
                    if(!a[v] && cap[u][v] > flow[u][v])
                    {
                        p[v] = u; Q.push(v);
                        a[v] = min(a[u], cap[u][v]-flow[u][v]);
                    }
            }
            if(a[t] == 0) break;
            for(int v = t; v != s; v = p[v])
            {
                flow[p[v]][v] += a[t];
                flow[v][p[v]] -= a[t];
            }
            ans += a[t];
        }
        if (ans < m)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
