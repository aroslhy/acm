/*
题意：给定一个图G，有q次询问（相互独立），每次询问(u,v,w)，表示将<u,v>这条边的边权更改为w，求此时的最小生成树的值。
算法：先求得最小生成树，对于每次询问(u,v,w)，分两种情况讨论：
1、若<u,v>是非最小生成树上的边，那么不用考虑，最小生成树仍是原来的值。
2、若<u,v>是最小生成树上的边，那么我们就需要在这条边所导致的两个集合中分别选出一个点i,j并且g[i][j]最小来替代那条被增加的边，那么反过来考虑，对于一条非最小生成树上的边<u,v>，它可以替代哪些边呢？就是u->x1->x2->...->xk->v这条路径（因为是树，所以这条路径唯一）上的边。那么现在要求的就是对于每条树上的边<u,v>，得到一个best[u][v]表示去掉它，最小的替代边的权值。这个可以用dfs来做，以每个点为起点做dfs，遍历整个最小生成树，得到best[i][j]，这样复杂度就是O(N^2)的，然后对于每次询问就可以O(1)回答了。这个dfs的写法还是有点技巧的，具体就见代码吧。
*/
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
