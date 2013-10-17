// 2013-10-17 09:16:31	 Accepted	3375	C++	180	404	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 15;
const int MAXN = 15+5, MAXM = 30+5;
int N, a[MAXN], b[MAXN], x[MAXN], y[MAXN], d[MAXN][MAXM][MAXM], f[1<<MAX];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d%d%d", &a[i], &b[i], &x[i], &y[i]);
			for (int j = 0; j <= x[i]; j++)
				for (int k = 0; k <= y[i]; k++)
				{
					d[i][j][k] = 0;
					if (j)
						d[i][j][k] = max(d[i][j][k], d[i][j-1][k]+b[i]*k);
					if (k)
						d[i][j][k] = max(d[i][j][k], d[i][j][k-1]+a[i]*j);
				}
		}
		int tot = (1<<N)-1;
		fill(f+1, f+1+tot, 0);
		for (int u = 0; u < tot; u++)
		{
			int iv = 0, tv = 0;
			for (int i = 1; i <= N; i++) if (u&(1<<(i-1)))
			{
				iv += b[i]*y[i];
				tv += a[i]*x[i];
			}
			for (int i = 1; i <= N; i++) if (!(u&(1<<(i-1))))
			{
				int v = u^(1<<(i-1));
				f[v] = max(f[v], f[u]+iv*x[i]+tv*y[i]+d[i][x[i]][y[i]]);
			}
		}
		printf("%d\n", f[tot]);
	}
	return 0;
}
