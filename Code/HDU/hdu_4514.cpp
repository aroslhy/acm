// 2013-03-23 18:20:00	Accepted	4514	921MS	7288K	1643 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
const int INF = 0x3f3f3f3f;
int N, M, X, Y, Z;
int e, u[MAXM], v[MAXM], next[MAXM], head[MAXN];
int w[MAXM], fa[MAXN], p[MAXN], maxi[MAXN][2];
bool vis[MAXN];
int ans;
void addedge(int x, int y, int z)
{
    u[e] = x; v[e] = y; w[e] = z;
    next[e] = head[x]; head[x] = e++;
}
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
void dfs(int u, int f)
{
	vis[u] = 1;
	fa[u] = f;
	maxi[u][0] = maxi[u][1] = 0;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != f)
	{
		dfs(v[i], u);
		if (maxi[v[i]][0]+w[i] > maxi[u][0])
		{
			maxi[u][1] = maxi[u][0];
			maxi[u][0] = maxi[v[i]][0]+w[i];
		}
		else if (maxi[v[i]][0]+w[i] > maxi[u][1])
			maxi[u][1] = maxi[v[i]][0]+w[i];
	}
	ans = max(ans, maxi[u][0]+maxi[u][1]);
}
int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &X, &Y, &Z);
			if (M >= N)
				continue;
			addedge(X, Y, Z);
			addedge(Y, X, Z);
		}
		if (M >= N)
			printf("YES\n");
		else
		{
			for (int i = 1; i <= N; i++)
				p[i] = i;
			bool flag = 0;
			for (int i = 0; i < e && !flag; i += 2)
			{
				int x = find(u[i]), y = find(v[i]);
				if (x == y)
					flag = 1;
				else
					p[x] = y;
			}
			if (flag)
				printf("YES\n");
			else
			{
				memset(vis, 0, sizeof(vis));
				ans = 0;
				for (int i = 1; i <= N; i++) if (!vis[i])
					dfs(i, 0);
				printf("%d\n", ans);
			}
		}
    }
    return 0;
}
