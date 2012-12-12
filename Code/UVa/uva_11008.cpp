//11008 	Antimatter Ray Clearcutting 	Accepted 	C++ 	2.656 	2012-12-12 02:15:41
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 16;
const int INF = 0x3f3f3f3f;
int T, N, M, X[MAX], Y[MAX];
int cnt[1<<MAX], d[1<<MAX];
void dfs(int x, int y, int z)
{
	if (x == MAX)
	{
		cnt[z] = y;
		return;
	}
	z &= (~(1<<x));
	dfs(x+1, y, z);
	z |= (1<<x);
	dfs(x+1, y+1, z);
}
int main()
{
	dfs(0, 0, 0);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &N, &M);
		int tot = 1<<N;
		for (int i = 0; i < N; i++)
			scanf("%d%d", &X[i], &Y[i]);
		fill(d+1, d+tot, INF);
		int ans = INF;
		for (int u = 0; u < tot; u++) if (d[u] < INF)
		{
			if (cnt[u] >= M)
				ans = min(ans, d[u]);
			for (int i = 0; i < N; i++) if (!((1<<i)&u))
			{
				int v = u;
				for (int j = 0; j < N; j++)
					if (X[i] == X[j] && Y[i] == Y[j])
						v |= (1<<j);
				d[v] = min(d[v], d[u]+1);
				for (int j = i+1; j < N; j++) if (!((1<<j)&u))
					if (!(X[i] == X[j] && Y[i] == Y[j]))
					{
						int v = u;
						for (int k = 0; k < N; k++)
							if ((X[i]-X[j])*(Y[j]-Y[k]) == (X[j]-X[k])*(Y[i]-Y[j]))
								v |= (1<<k);
						d[v] = min(d[v], d[u]+1);
					}
			}
		}
		if (cas > 1)
			printf("\n");
		printf("Case #%d:\n%d\n", cas, ans);
	}
	return 0;
}
