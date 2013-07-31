// 2013-07-27 22:17:48	Accepted	4616	234MS	5028K	2108 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5, MAXM = 100000+5;;
int T, N, C, trp[MAXN], A, B;
int e, head[MAXN], next[MAXM], v[MAXM];
long long val[MAXN], d[MAXN][4][2], maxi[4][2], tmp[4][2];
void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void dfs(int u, int fa, long long &ans)
{
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
		dfs(v[i], u, ans);
	for (int i = 0; i <= C; i++)
		for (int j = 0; j < 2; j++)
		{
			if (trp[u] && !i)
				tmp[i][j] = d[u][i][j] = 0;
			else
				tmp[i][j] = d[u][i][j] = val[u];
		}
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
	{
		for (int j = 0; j <= C; j++)
			for (int k = 0; k < 2; k++)
				maxi[j][k] = tmp[j][k];
		for (int j = 0; j <= C; j++)
		{
			if (!trp[u])
			{
				if (d[v[i]][j][0] && !(j == C && trp[v[i]]))
					maxi[j][0] = max(maxi[j][0], d[v[i]][j][0]+val[u]);
				if (d[v[i]][j][1])
					maxi[j][1] = max(maxi[j][1], d[v[i]][j][1]+val[u]);
			}
			if (trp[u])
			{
				if (j > 0 && d[v[i]][j-1][0])
					maxi[j][0] = max(maxi[j][0], d[v[i]][j-1][0]+val[u]);
				if (j > 1 && d[v[i]][j-1][1])
					maxi[j][1] = max(maxi[j][1], d[v[i]][j-1][1]+val[u]);
			}
		}
		for (int j = 0; j <= C; j++)
			for (int k = 0; j+k-trp[u] <= C; k++)
			{
				if (d[u][j][0] && maxi[k][1])
					ans = max(ans, d[u][j][0]+maxi[k][1]-val[u]);
				if (maxi[k][0] && d[u][j][1])
					ans = max(ans, maxi[k][0]+d[u][j][1]-val[u]);
			}
		for (int j = 0; j <= C; j++)
			for (int k = 0; k < 2; k++)
				d[u][j][k] = max(d[u][j][k], maxi[j][k]);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		memset(head, -1, sizeof(head));
		scanf("%d%d", &N, &C);
		for (int i = 0; i < N; i++)
			scanf("%I64d%d", &val[i], &trp[i]);
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d", &A, &B);
			addedge(A, B);
			addedge(B, A);
		}
		long long ans = 0;
		dfs(0, -1, ans);
		printf("%I64d\n", ans);
	}
	return 0;
}
