// 2013-09-21 17:49:15	Accepted	4750	4125MS	17280K	1737 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 500000+5, MAXP = 100000+5;
int N, M, P, u[MAXM<<1], v[MAXM<<1], w[MAXM], t[MAXP];
int fa[MAXN], sum[MAXN], rw[MAXM], rt[MAXP], qry[MAXP];
int head[MAXN<<1], next[MAXM<<1];
int cnt, vis[MAXN];
bool cmpw(const int &a, const int &b)
{
	return w[a] < w[b];
}
bool cmpt(const int &a, const int &b)
{
	return t[a] < t[b];
}
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int dfs(int u)
{
	int ret = 1;
	vis[u] = cnt;
	for (int i = head[u]; i != -1; i = next[i]) if (!vis[v[i]])
		ret += dfs(v[i]);
	return ret;
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		memset(head, -1, sizeof(head));
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
			next[i] = head[u[i]];
			head[u[i]] = i;
			rw[i] = i;
			u[M+i] = v[i], v[M+i] = u[i];
			next[M+i] = head[u[M+i]];
			head[u[M+i]] = M+i;
		}
		sort(rw, rw+M, cmpw);
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			fa[i] = i;
			sum[i] = 1;
			if (!vis[i])
			{
				cnt++;
				int x = dfs(i);
				ans += x*(x-1);
			}
		}
		scanf("%d", &P);
		for (int i = 0; i < P; i++)
		{
			scanf("%d", &t[i]);
			rt[i] = i;
		}
		sort(rt, rt+P, cmpt);
		for (int i = 0, j = 0; i < P; i++)
		{
			for (; j < M && w[rw[j]] < t[rt[i]]; j++)
			{
				int p = find(u[rw[j]]), q = find(v[rw[j]]);
				if (p == q)
					continue;
				else
				{
					ans -= sum[p]*sum[q]*2;
					fa[p] = q;
					sum[q] += sum[p];
				}
			}
			qry[rt[i]] = ans;
		}
		for (int i = 0; i < P; i++)
			printf("%d\n", qry[i]);
	}
	return 0;
}
