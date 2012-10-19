/*
题意：一个有N个节点的树形的地图，知道了每条变经过所需要的时间，现在给出时间T，问能不能在T时间内从1号节点到N节点。每个节点都有相对应的价值，而且每个价值只能被取一次，问如果可以从1号节点走到n号节点的话，最多可以取到的最大价值为多少。
分析：先求出从1号节点到n号节点的最短路，如果花费大于时间T，则直接输出不符合，将最短路上的权值全部赋值为0，在总时间T上减去最短路的长度，表示最短路已经走过，对其它点进行树形背包求解，需要注意的是如果不是最短路上的边都要走两次，即走过去还要再走回来，状态转移方程：dp[i][j]=max(dp[i][j],dp[i][k]+dp[i][j-2*val-k])
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 500+5;
int N, T, a, b, t, A[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM], w[MAXM];
int fa[MAXN], d[MAXN][MAXM];
void addedge(int x, int y, int z)
{
	v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void mark(int u)
{
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa[u])
		{
			fa[v[i]] = u;
			mark(v[i]);
		}
}
void dfs(int u, int C)
{
	fill(d[u], d[u]+1+C, A[u]);
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa[u])
	{
		int cost = w[i]*2;
		if (cost <= C)
		{
			dfs(v[i], C-cost);
			for (int j = C; j >= 0; j--)
				for (int k = 0; k <= j-cost; k++)
					d[u][j] = max(d[u][j], d[u][j-k-cost]+d[v[i]][k]);
		}
	}
}
int main()
{
	while (scanf("%d%d", &N, &T) != EOF)
	{
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d%d", &a, &b, &t);
			addedge(a, b, t);
			addedge(b, a, t);
		}
		for (int i = 1; i <= N; i++)
			scanf("%d", &A[i]);
		int ans = 0;
		mark(1);
		for (int u = N; ; )
		{
			ans += A[u];
			A[u] = 0;
			if (u == 1)
				break;
			for (int i = head[u]; i != -1; i = next[i]) if (v[i] == fa[u])
			{
				u = v[i];
				T -= w[i];
				w[i] = 0;
				w[i^1] = 0;
				break;
			}
		}
		if (T < 0)
			printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
		else
		{
			dfs(1, T);
			ans += d[1][T];
			printf("%d\n", ans);
		}
	}
	return 0;
}
