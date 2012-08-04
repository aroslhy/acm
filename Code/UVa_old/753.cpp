#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAX = 400+5, INF = 0x3f3f3f3f;
int T, n, m, k, N;
int s, t, cap[MAX][MAX];
int a[MAX], p[MAX], flow[MAX][MAX];
queue<int> Q;
map<string, int> M;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        s = 1; t = 2; N = 2;
        memset(cap, 0, sizeof(cap));
        M.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            string str; cin>>str;
            if (!M[str]) M[str] = ++N;
            int v = M[str]; cap[s][v]++;
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            string str_, str;
            cin>>str_>>str;
            if (!M[str]) M[str] = ++N;
            int u = M[str];
            cap[u][t]++;
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            string str1, str2;
            cin>>str1>>str2;
            if (!M[str1]) M[str1] = ++N;
            if (!M[str2]) M[str2] = ++N;
            int v = M[str1], u = M[str2];
            cap[u][v] = INF;
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
        printf("%d\n", m-ans);
        if (T) printf("\n");
    }
    return 0;
}
