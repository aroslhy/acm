/*
ID: bigocea1
PROG: agrinet
LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = MAXN*MAXN;
int N, r[MAXM], p[MAXM], u[MAXM], v[MAXM], w[MAXM], m;
int cmp(const int a, const int b) {return w[a]<w[b];}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int Kruskal()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
        r[i] = i;
    sort(r+1, r+1+m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int e = r[i], x = find(u[e]), y = find(v[e]);
        if (x != y)
            ans += w[e], p[x] = y;
    }
    return ans;
}
int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    scanf("%d", &N);
    m = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            m++, u[m] = i, v[m] = j, scanf("%d", &w[m]);
    printf("%d\n", Kruskal());
	return 0;
}
