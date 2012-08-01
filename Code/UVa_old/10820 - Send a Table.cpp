#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 50000+5;
int N;
int c = 0, phi[MAXN];
bool vis[MAXN];
int Phi(int x)
{
    int &res = phi[x];
    if (res) return res;
    int t = x, p[MAXN], c2 = 0;
    for (int i = 2; t != 1; i++)
        if (!vis[i] && !(t%i))
        {
            p[++c2] = i;
            while (!(t%i))
                t /= i;
        }
    res = x;
    for (int i = 1; i <= c2; i++)
        res = res/p[i]*(p[i]-1);
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int m = sqrt(MAXN+0.5);
    memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= m; i++)
        if (!vis[i])
        {
            for (int j = i*i; j <= MAXN; j += i)
                vis[j] = 1;
//            printf("%d\n", i);
        }
    memset(phi, 0, sizeof(phi));
	while (scanf("%d", &N) && N)
	{
	    int ans = 0;
	    for (int i = 1; i <= N; i++)
            ans += Phi(i);
        ans = ans*2-1;
        printf("%d\n", ans);
	}
	return 0;
}
