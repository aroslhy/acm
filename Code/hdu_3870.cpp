#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 160000+5, MAXM = 640000+5, MAXP = 400+5;
const int INF = 0x3f3f3f3f;
int T, N, A[MAXP][MAXP];
int n, s, t;
int e, head[MAXN], next[MAXM], v[MAXM];
int w[MAXM], d[MAXN];
bool inq[MAXN];
struct cmp
{
    bool operator () (const int a, const int b)
    {
        return d[a] > d[b];
    }
};
priority_queue<int, vector<int>, cmp> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
    v[e] = x; w[e] = z;
    next[e] = head[y]; head[y] = e++;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
void spfa()
{
    for (int i = 0; i < n; i++)
        d[i] = (i == s) ? 0 : INF;
    memset(inq, 0, sizeof(inq));
    Q.push(s);
    inq[s] = 1;
    while (!Q.empty())
    {
        int u = Q.top(); Q.pop();
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
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &A[i][j]);
        int r = N-1;
        n = r*r; s = n++; t = n++;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < r; j++)
            {
                int x = r*i+j;
                if (j+1 < r)
                    addedge(x, x+1, A[i][j+1]);
                if (i+1 < r)
                    addedge(x, x+r, A[i+1][j]);
            }
        for (int j = 0; j < r; j++)
        {
            addedge(j, t, A[0][j]);
            addedge(s, r*(r-1)+j, A[r][j]);
        }
        for (int i = 0; i < r; i++)
        {
            addedge(r*i+r-1, t, A[i][r]);
            addedge(s, r*i, A[i][0]);
        }
        spfa();
        printf("%d\n", d[t]);
    }
    return 0;
}
