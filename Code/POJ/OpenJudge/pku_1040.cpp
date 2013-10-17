// aroslhy	Accepted	2508kB	260ms	1852 B	G++	13.10.17
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 10000+5, MAXM = 100000+5, MAXK = 10+5, MAXS = 20+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N, M, K, SK, U, V, W, D, c[MAXN], s[MAXN][MAXK];
int e, head[MAXN], next[MAXM], v[MAXM], w[MAXM], d[MAXM], dst[MAXN][MAXK];
double f[MAXS][MAXS];
bool inq[MAXN][MAXK];
void addedge(int x, int y, int a, int b)
{
	v[e] = y; w[e] = a; d[e] = b;
	next[e] = head[x]; head[x] = e++;
}
void spfa(int src, int stt)
{
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < K; j++)
			dst[i][j] = INF;
	dst[src][stt] = 0;
	queue<pair<int, int> > Q;
	Q.push(make_pair(src, stt));
	while (!Q.empty())
	{
		int u = Q.front().first, p = Q.front().second;
		Q.pop();
		inq[u][p] = 0;
		int q = (p+1)%K, cost = c[u];
		if (dst[u][p]+cost < dst[u][q])
		{
			dst[u][q] = dst[u][p]+cost;
			if (!inq[u][q])
			{
				Q.push(make_pair(u, q));
				inq[u][q] = 1;
			}
		}
		for (int i = head[u]; i != -1; i = next[i])
		{
			q = (p+d[i])%K, cost = floor(f[s[u][p]][s[v[i]][q]]*w[i]+eps);
			if (dst[u][p]+cost < dst[v[i]][q])
			{
				dst[v[i]][q] = dst[u][p]+cost;
				if (!inq[v[i]][q])
				{
					Q.push(make_pair(v[i], q));
					inq[v[i]][q] = 1;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &N, &M, &K, &SK);
		e = 0;
		fill(head+1, head+1+N, -1);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &c[i]);
			for (int j = 0; j < K; j++)
				scanf("%d", &s[i][j]);
		}
		for (int i = 1; i <= SK; i++)
			for (int j = 1; j <= SK; j++)
				scanf("%lf", &f[i][j]);
		for (int i = 1; i <= M; i++)
		{
			scanf("%d%d%d%d", &U, &V, &W, &D);
			addedge(U, V, W, D);
		}
		spfa(1, 0);
		int ans = INF;
		for (int i = 0; i < K; i++)
			ans = min(ans, dst[N][i]);
		printf("%d\n", ans);
	}
	return 0;
}
