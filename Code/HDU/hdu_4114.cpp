//2012-10-07 19:25:47	Accepted	4114	7156MS	14308K	1927 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50+5;
const int MAX = 8;
const int INF = 0x3f3f3f3f;
int T, N, M, K, A, B, D, P[MAX], NFT[MAX], FT[MAX], NF, F;
int fast[MAXN], attr[MAXN], cost[2][1<<MAX];
int w[MAXN][MAXN], f[1<<MAX][1<<MAX][MAXN];
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &N, &M, &K);
		int ALL = (1<<K)-1, ans = INF;
		fill(fast+1, fast+1+N, 0);
		fill(attr+1, attr+1+N, 0);
		for (int i = 0; i < 2; i++)
			fill(cost[i]+1, cost[i]+1+ALL, 0);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				w[i][j] = (i == j ? 0 : INF);
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &A, &B, &D);
			w[A][B] = w[B][A] = min(w[B][A], D);
		}
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
		for (int i = 0; i < K; i++)
		{
			scanf("%d%d%d%d", &P[i], &NFT[i], &FT[i], &NF);
			attr[P[i]] |= (1<<i);
			for (int j = 0; j < NF; j++)
			{
				scanf("%d", &F);
				fast[F] |= (1<<i);
			}
		}
		for (int a = 0; a <= ALL; a++)
			for (int i = 0; i < K; i++) if (a&(1<<i))
			{
				cost[0][a] += NFT[i];
				cost[1][a] += FT[i];
			}
		for (int a = 0; a <= ALL; a++)
			for (int b = 0; b <= ALL; b++)
				fill(f[a][b]+1, f[a][b]+1+N, INF);
		f[0][0][1] = 0;
		for (int a = 0; a <= ALL; a++)
			for (int b = 0; b <= ALL; b++)
				for (int u = 1; u <= N; u++) if (f[a][b][u] < INF)
					for (int v = 1; v <= N; v++)
					{
						int c = a|fast[v], d = b|attr[v];
						f[c][b][v] = min(f[c][b][v], f[a][b][u]+w[u][v]);
						f[c][d][v] = min(f[c][d][v], f[a][b][u]+w[u][v]+cost[0][attr[v]&(~b)&(~c)]+cost[1][attr[v]&(~b)&c]);
					}
		for (int a = 0; a <= ALL; a++)
			ans = min(ans, f[a][ALL][1]);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
