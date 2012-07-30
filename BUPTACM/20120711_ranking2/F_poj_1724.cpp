#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5, MAXK = 10000+5;
int K, N, R, S, D, L, T;
int e, head[MAXN], next[MAXM], v[MAXM];
int w[MAXM], t[MAXM], d[MAXN][MAXK];
struct Node
{
    int dst, cost, len;
    Node (int x, int y = 0, int z = 0)
    {
        dst = x; cost = y; len = z;
    }
};
bool operator < (const Node a, const Node b)
{
    if (a.len != b.len)
        return a.len > b.len;
    else
        return a.cost > b.cost;
}
priority_queue<Node> que;
void addedge(int x, int y, int z, int a)
{
    v[e] = y; w[e] = z; t[e] = a;
    next[e] = head[x]; head[x] = e++;
}
int spfa()
{
    while (!que.empty()) que.pop();
    que.push(Node(1));
    while (!que.empty())
    {
        Node x = que.top(); que.pop();
        if (x.dst == N)
            return x.len;
        for (int i = head[x.dst]; i != -1; i = next[i])
            if (x.cost+t[i] <= K)
            {
                Node y(v[i], x.cost+t[i], x.len+w[i]);
                que.push(y);
            }
    }
    return -1;
}
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    e = 0;
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &K, &N, &R);
    for (int i = 1; i <= R; i++)
    {
        scanf("%d%d%d%d", &S, &D, &L, &T);
        addedge(S, D, L, T);
    }
    int ans = spfa();
    printf("%d\n", ans);
    return 0;
}
