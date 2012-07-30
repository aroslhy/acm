#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
const int MAXN = 10000+5, MAXM = 20000+5, MAXQ = 50000+5;
const int INF = 0x3f3f3f3f;
int N, M, Q, p[MAXN], fa[MAXN], cas;
bool des[MAXM];
int n, m, e, s;
int v[MAXM], next[MAXM], head[MAXN];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
}
struct Node
{
    bool isdestroy;
    int a, b;
    Node(bool x, int y, int z = 0)
    {
        isdestroy = x;
        a = y;
        b = z;
    }
};
int ans[MAXQ];
stack<Node> S_q;
stack<int> S_a;
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int cas = 1; scanf("%d", &N) != EOF; cas++)
    {
        for (int i = 0; i < N; i++)
            scanf("%d", &p[i]);
        scanf("%d", &M);
        memset(head, -1, sizeof(head));
        e = 0;
        for (int i = 0; i < M; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (p[x] > p[y] || (p[x] == p[y] && x < y))
                swap(x, y);
            addedge(x, y);
        }
        scanf("%d", &Q);
        memset(des, 0, sizeof(des));
        for (int i = 0; i < Q; i++)
        {
            char s[10]; int a, b;
            scanf("%s", s);
            if (s[0] == 'q')
            {
                scanf("%d", &a);
                S_q.push(Node(0, a));
            }
            else
            {
                scanf("%d%d", &a, &b);
                if (p[a] > p[b] || (p[a] == p[b] && a < b))
                    swap(a, b);
                S_q.push(Node(1, a, b));
                for (int e = head[a]; e != -1; e = next[e])
                    if (v[e] == b)
                    {
                        des[e] = 1;
                        break;
                    }
            }
        }
        for (int i = 0; i < N; i++)
            fa[i] = i;
        for (int u = 0; u < N; u++)
            for (int e = head[u]; e != -1; e = next[e])
                if (!des[e])
                {
                    int x = Find(u), y = Find(v[e]);
                    if (p[x] > p[y])
                        fa[y] = x;
                    else if (p[x] < p[y])
                        fa[x] = y;
                    else if (x < y)
                        fa[y] = x;
                    else
                        fa[x] = y;
                }
        while (!S_q.empty())
        {
            Node n = S_q.top(); S_q.pop();
            if (!n.isdestroy)
            {
                int x = Find(n.a);
                S_a.push(p[x] > p[n.a] ? x : -1);
            }
            else
            {
                int x = Find(n.a), y = Find(n.b);
                if (p[x] > p[y])
                    fa[y] = x;
                else if (p[x] < p[y])
                    fa[x] = y;
                else if (x < y)
                    fa[y] = x;
                else
                    fa[x] = y;
            }
        }
        if (cas > 1)
            printf("\n");
        while (!S_a.empty())
        {
            printf("%d\n", S_a.top());
            S_a.pop();
        }
    }
    return 0;
}
