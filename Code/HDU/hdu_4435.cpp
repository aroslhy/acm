//2012-11-18 21:49:53	Accepted	4435	31MS	352K	1285 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 128+5;
int N, D, x[MAXN], y[MAXN];
int d[MAXN][MAXN], ans;
char s[MAXN];
bool vis[MAXN], chg[MAXN];
bool check()
{
	queue<int> Q;
	memset(vis, 0, sizeof(vis));
	Q.push(1);
	vis[1] = 1;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int v = 1; v <= N; v++) if (!vis[v])
		{
			if (chg[v] && d[u][v] <= D)
			{
				Q.push(v);
				vis[v] = 1;
			}
			if (!chg[v] && 2*d[u][v] <= D)
				vis[v] = 1;
		}
	}
	for (int j = 1; j <= N; j++) if (!vis[j])
		return 0;
	return 1;
}
int main()
{
	while (scanf("%d%d", &N, &D) != EOF)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			for (int j = 1; j < i; j++)
				d[i][j] = d[j][i] = ceil(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
		}
		memset(chg, 1, sizeof(chg));
		if (!check())
			printf("-1\n");
		else
		{
			for (int i = N; i > 1; i--)
			{
				chg[i] = 0;
				if (!check())
					chg[i] = 1;
			}
			bool flag = 0;
			for (int i = N; i >= 1; i--)
			{
				if (chg[i])
				{
					printf("1");
					flag = 1;
				}
				else if (flag)
					printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}
