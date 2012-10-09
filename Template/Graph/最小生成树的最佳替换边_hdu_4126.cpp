#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 3000+5, MAXM = 6000+5;
const int INF = 0x3f3f3f3f;
int N, M, Q, X, Y, C;
int g[MAXN][MAXN], best[MAXN][MAXN], dis[MAXN], pre[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
bool vis[MAXN];
void addedge(int x, int y)
{
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			g[i][j] = g[j][i] = best[i][j] = best[j][i] = INF;
}
int prim()
{
	for (int i = 0; i < N; i++)
		vis[i] = 0, pre[i] = -1, dis[i] = INF;
	int res = 0;
	dis[0] = 0;
	for (int j = 0; j < N; j++)
	{
		int u = -1;
		for (int i = 0; i < N; i++)
			if (!vis[i] && (u == -1 || dis[i] < dis[u]))
				u = i;
		vis[u] = 1;
		res += dis[u];
		if (pre[u] != -1)
		{
			addedge(u, pre[u]);
			addedge(pre[u], u);
		}
		for (int i = 0; i < N; i++)
			if (!vis[i] && g[u][i] < dis[i])
			{
				dis[i] = g[u][i];
				pre[i] = u;
			}
	}
	return res;
}
int dfs(int st, int u, int fa)
{
	int mini = INF;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
	{
		int cur = dfs(st, v[i], u);
		mini = min(mini, cur);
		best[u][v[i]] = best[v[i]][u] = min(best[u][v[i]], cur);
	}
	if (st != fa)
		mini = min(mini, g[st][u]);
	return mini;
}
int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		init();
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &X, &Y, &C);
			g[X][Y] = g[Y][X] = C;
		}
		int mst = prim();
		for (int i = 0; i < N; i++)
			dfs(i, i, -1);
		scanf("%d", &Q);
		double ans = 0;
		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d%d", &X, &Y, &C);
			if (pre[X] == Y || pre[Y] == X)
				ans += mst-g[X][Y]+min(C, best[X][Y]);
			else
				ans += mst;
		}
		ans /= Q;
		printf("%.4f\n", ans);
	}
	return 0;
}
