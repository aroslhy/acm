//10913 	Walking on a Grid 	Accepted 	C++ 	0.032 	2012-12-10 13:29:24
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 75+5, MAXK = 5+5;
const long long INF = 1LL<<60;
int N, K, g[MAXN][MAXN], cnt[MAXN][MAXN];
long long sum[MAXN][MAXN], d[MAXN][MAXN][MAXK];
int main()
{
	for (int cas = 1; scanf("%d%d", &N, &K); cas++)
	{
		if (!N && !K)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &g[i][j]);
				sum[i][j] = sum[i][j-1]+g[i][j];
				cnt[i][j] = cnt[i][j-1]+(g[i][j] < 0 ? 1 : 0);
			}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				fill(d[i][j], d[i][j]+K+1, -INF);
		for (int j = 1; j <= N && cnt[1][j] <= K; j++)
			d[1][j][cnt[1][j]] = sum[1][j];
		for (int i = 2; i < N; i++)
			for (int j = 1; j <= N; j++)
				for (int p = 1; p <= N; p++)
				{
					int s = (p < j ? sum[i][j]-sum[i][p-1] : sum[i][p]-sum[i][j-1]);
					int c = (p < j ? cnt[i][j]-cnt[i][p-1] : cnt[i][p]-cnt[i][j-1]);
					for (int k = K; k >= c; k--)
						if (d[i-1][p][k-c] > -INF)
							d[i][j][k] = max(d[i][j][k], d[i-1][p][k-c]+s);
				}
		for (int p = 1; p <= N; p++)
		{
			int s = sum[N][N]-sum[N][p-1];
			int c = cnt[N][N]-cnt[N][p-1];
			for (int k = K; k >= c; k--)
				if (d[N-1][p][k-c] > -INF)
					d[N][N][k] = max(d[N][N][k], d[N-1][p][k-c]+s);
		}
		long long ans = -INF;
		for (int k = 0; k <= K; k++)
			ans = max(ans, d[N][N][k]);
		if (ans > -INF)
			printf("Case %d: %lld\n", cas, ans);
		else
			printf("Case %d: impossible\n", cas);
	}
	return 0;
}
