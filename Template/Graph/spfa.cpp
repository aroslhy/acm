#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 1000+5;
const int INF = 0x3f3f3f3f;
int n, m, e, s;
int v[MAXM], next[MAXM], head[MAXN];
int w[MAXM], d[MAXN];
int inq_cnt[MAXN]; //存在负权回路时需要
bool inq[MAXN];
queue<int> Q;
void addedge(int x, int y, int z)
{
    v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e;
    e++;
}
bool spfa()
{
    for (int i = 1; i <= n; i++)
        d[i] = (i == s ? 0 : INF);
    memset(inq, 0, sizeof(inq));
    memset(inq_cnt, 0, sizeof(inq_cnt));
    while (!Q.empty()) Q.pop();
    Q.push(s);
    inq[s] = 1;
    inq_cnt[s]++;
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
                    inq_cnt[v[e]]++;
                    if (inq_cnt[v[e]] > n)
                        return 0;
                }
            }
    }
    return 1;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(head, -1, sizeof(head));
    e = 0;

    return 0;
}
