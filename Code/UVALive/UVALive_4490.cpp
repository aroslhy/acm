//4490 	Help Bubu 	Accepted 	C++ 	1.172 	2012-10-18 13:41:49
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const int MAX = 8, INF = 0x3f3f3f3f;
int N, K, h[MAXN];
int cnt[1<<MAX], d[2][MAXN][1<<MAX][MAX+5];
inline void setzero(int x, int p)
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= p; j++)
			for (int k = 0; k <= MAX; k++)
				d[x][i][j][k] = INF;
}
int main()
{
	for (int i = 1; i < (1<<MAX); i++)
		for (int j = 0; j < MAX; j++)
			if (i&(1<<j))
				cnt[i]++;
	for (int cas = 1; scanf("%d%d", &N, &K); cas++)
	{
		if (!N && !K)
			break;
		int tot = 0, s = 0, t = 1, ans = INF;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &h[i]);
			h[i] -= 25;
			tot |= (1<<h[i]);
		}
		setzero(t, tot);
		d[t][0][0][MAX] = 0;
		for (int i = 0; i < N; i++)
		{
			swap(s, t);
			setzero(t, tot);
			for (int j = 0; j <= K; j++)
				for (int k = 0; k <= tot; k++)
					for (int l = 0; l <= MAX; l++) if (d[s][j][k][l] < INF)
					{
						if (j < K)
							d[t][j+1][k][l] = min(d[t][j+1][k][l], d[s][j][k][l]);
						d[t][j][k|(1<<h[i+1])][h[i+1]] = min(d[t][j][k|(1<<h[i+1])][h[i+1]], d[s][j][k][l]+(h[i+1] != l ? 1 : 0));
					}
		}
		for (int j = 0; j <= K; j++)
			for (int k = 0; k <= tot; k++)
				for (int l = 0; l <= MAX; l++) if (d[t][j][k][l] < INF)
					ans = min(ans, d[t][j][k][l]+cnt[k^tot]);
		printf("Case %d: %d\n\n", cas, ans);
	}
	return 0;
}
