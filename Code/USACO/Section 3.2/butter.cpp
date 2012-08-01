/*
ID: bigocea1
PROG: butter
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAXN = 800+5, MAXM = 1450*2+5;
const int INF = 0x3f3f3f3f;
int n, m, e, s;
int v[MAXM], next[MAXM], head[MAXN];
int w[MAXM], d[MAXN];
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e;
    e++;
}
void spfa()
{
    for (int i = 1; i <= n; i++)
        d[i] = (i == s ? 0 : INF);
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int e = head[u]; e != -1; e = next[e])
            if(d[v[e]] > d[u]+w[e])
            {
                d[v[e]] = d[u]+w[e];
                if(!inq[v[e]])
                {
                    Q.push(v[e]);
                    inq[v[e]] = 1;
                }
            }
    }
}
int N, P, C, p[MAXN];
int main()
{
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    e = 0;
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &N, &P, &C);
    n = P;
    for (int i = 1; i <= N; i++)
    {
        int t;
        scanf("%d", &t);
        p[t]++;
    }
    for (int i = 1; i <= C; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    int ans = INF;
    for (int i = 1; i <= P; i++)
    {
        s = i; spfa();
        int sum = 0;
        for (int j = 1; j <= P; j++)
            sum += p[j]*d[j];
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
