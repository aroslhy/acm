// 2013-03-31 22:09:58	Accepted	4540	0MS	244K	846 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 500, MAXN = 20+5, MAXM = 10+5, MAXL = MAX+5;
const int INF = 0x3f3f3f3f;
int N, K, x[MAXN][MAXM], d[MAXN][MAXL];
int main()
{
	while (scanf("%d%d", &N, &K) != EOF)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= K; j++)
				scanf("%d", &x[i][j]);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= MAX; j++)
				d[i][j] = INF;
		for (int i = 1; i <= K; i++)
			d[1][x[1][i]] = 0;
		for (int i = 2; i <= N; i++)
			for (int j = 1; j <= K; j++)
			{
				for (int k = 1; k <= MAX; k++) if (d[i-1][k] < INF)
					d[i][x[i][j]] = min(d[i][x[i][j]], d[i-1][k]+abs(x[i][j]-k));
			}
		int ans = INF;
		for (int i = 1; i <= MAX; i++)
			ans = min(ans, d[N][i]);
		printf("%d\n", ans);
	}
	return 0;
}
