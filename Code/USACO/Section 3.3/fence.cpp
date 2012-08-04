/*
ID: bigocea1
PROG: fence
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
const int MAXN = 500+5, MAXM = 1024*2+5;
const int INF = 0x3f3f3f3f;
int F, dgr[MAXN];
stack<int> S;
vector<int> out;
int e;
int v[MAXM], next[MAXM], head[MAXN];
bool vis[MAXM];
void addedge(int x, int y)
{
    v[e] = y;
    next[e] = head[x]; head[x] = e;
    e++;
}
int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    e = 0;
    memset(head, -1, sizeof(head));
    scanf("%d", &F);
    for (int i = 1; i <= F; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
        dgr[x]++; dgr[y]++;
    }
    int s;
    for (int i = 1; i <= 500; i++)
        if (dgr[i])
        {
            s = i;
            break;
        }
    for (int i = 1; i <= 500; i++)
        if (dgr[i]%2)
        {
            s = i;
            break;
        }
    S.push(s);
    while (!S.empty())
    {
        int x = S.top();
        int y = INF, z;
        for (int i = head[x]; i != -1; i = next[i])
            if (!vis[i] && y > v[i])
            {
                y = v[i];
                z = i;
            }
        if (y < INF)
        {
            vis[z] = vis[z^1] = 1;
//            printf("%d\n", y);
            S.push(y);
        }
        else
        {
            S.pop();
            out.push_back(x);
        }
    }
    for (int i = (int)out.size()-1; i >= 0; i--)
        printf("%d\n", out[i]);
    return 0;
}
