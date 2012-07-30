#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int T, a, b, c, d, ans, d2, ans2; bool vis[201][201];
struct State{int A, B, C, p;};
queue<State> Q;
int Pour(State &s, int x)
{
    int res;
    if (x == 1)
    {
        if (s.A > b - s.B)
            res = b - s.B, s.A -= (b - s.B), s.B = b;
        else
            res = s.A, s.B += s.A, s.A = 0;
    }
    else if (x == 2)
    {
        if (s.A > c - s.C)
            res = c - s.C, s.A -= (c - s.C), s.C = c;
        else
            res = s.A, s.C += s.A, s.A = 0;
    }
    else if (x == 3)
    {
        if (s.B > a - s.A)
            res = a - s.A, s.B -= (a - s.A), s.A = a;
        else
            res = s.B, s.A += s.B, s.B = 0;
    }
    else if (x == 4)
    {
        if (s.B > c - s.C)
            res = c - s.C, s.B -= (c - s.C), s.C = c;
        else
            res = s.B, s.C += s.B, s.B = 0;
    }
    else if (x == 5)
    {
        if (s.C > a - s.A)
            res = a - s.A, s.C -= (a - s.A), s.A = a;
        else
            res = s.C, s.A += s.C, s.C = 0;
    }
    else if (x == 6)
    {
        if (s.C > b - s.B)
            res = b - s.B, s.C -= (b - s.B), s.B = b;
        else
            res = s.C, s.B += s.C, s.C = 0;
    }
    return res;
}
bool Search()
{
    while (!Q.empty()) Q.pop();
    State root = {0, 0, c, 0};
    Q.push(root);
    vis[0][0] = 1;
    if (root.A == d || root.B == d || root.C == d)
        return 1;
    while (!Q.empty())
    {
        State t0 = Q.front(); Q.pop();
        for (int i = 1; i <= 6; i++)
        {
            State t1 = t0; int t_p = Pour(t1, i);
            if (!vis[t1.A][t1.B])
            {
                t1.p += t_p;
                if (t1.A == d || t1.B == d || t1.C == d)
                {
                    ans = t1.p;
                    return 1;
                }
                if (d2 < t1.A && t1.A < d)
                    d2 = t1.A, ans2 = t1.p;
                if (d2 < t1.B && t1.B < d)
                    d2 = t1.B, ans2 = t1.p;
                if (d2 < t1.C && t1.C < d)
                    d2 = t1.C, ans2 = t1.p;
                Q.push(t1);
                vis[t1.A][t1.B] = 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        memset(vis, 0, sizeof(vis));
        ans = 0; d2 = 0; ans2 = 0;
        if (Search())
            printf("%d %d\n", ans, d);
        else
            printf("%d %d\n", ans2, d2);
    }
    return 0;
}
