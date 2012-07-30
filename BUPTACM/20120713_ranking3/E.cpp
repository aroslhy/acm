#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5, MAXM = 100000+5;
int N, M, Q, A[MAXM], B[MAXM], c[MAXM];
int p[MAXN];
bool nc[MAXM], vis[MAXN];
vector<int> ans;
int find(int x)
{
    return (p[x] == x) ? x : (p[x] = find(p[x]));
}
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
        scanf("%d%d", &A[i], &B[i]);
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d", &c[i]);
        nc[c[i]] = 1;
    }
    for (int u = 1; u <= N; u++)
        p[u] = u;
    for (int i = 1; i <= M; i++) if (!nc[i])
    {
        int x = find(A[i]), y = find(B[i]);
        if (x != y)
            p[x] = y;
    }
    int cnt = 0;
    for (int u = 1; u <= N; u++)
    {
        int f = find(u);
        if (!vis[f])
        {
            cnt++;
            vis[f] = 1;
        }
    }
    ans.push_back(cnt);
    for (int i = Q; i >= 1; i--)
    {
        int x = find(A[c[i]]), y = find(B[c[i]]);
        if (x != y)
        {
            ans.push_back(--cnt);
            p[x] = y;
        }
        else
            ans.push_back(cnt);
    }
    int num = ans.size();
    for (int i = num-2; i >= 0; i--)
    {
        printf("%d", ans[i]);
        printf(i ? " " : "\n");
    }
    return 0;
}
