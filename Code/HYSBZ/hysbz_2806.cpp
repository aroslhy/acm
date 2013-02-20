//bigoceanlhy	2806	Accepted	54516 kb	2336 ms	C++/Edit	2346 B	2013-02-20 20:21:57
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1100000+5;
const int MAX_NODE = 2200000+5, MAX_CHD = 3;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<7];
int N, M, d[MAXN], g[MAXN];
char sw[MAXN], w[MAXN];
void Add(int u, int _ml, int _fa, int v = -1)
{
	ml[u] = _ml; fa[u] = _fa;
	if (v == -1)
		memset(chd[u], -1, sizeof(chd[u]));
	else
		memcpy(chd[u], chd[v], sizeof(chd[v]));
}
void Construct(char *str)
{
	nv = 1; Add(0, 0, -1);
	int cur = 0;
	for (int i = 0; str[i]; i++)
	{
		int c = id[str[i]], p = cur;
		cur = nv++; Add(cur, i+1, -1);
		for (; p != -1 && chd[p][c] == -1; p = fa[p])
			chd[p][c] = cur;
		if (p == -1)
			fa[cur] = 0;
		else
		{
			int q = chd[p][c];
			if (ml[q] == ml[p]+1)
				fa[cur] = q;
			else
			{
				int r = nv++; Add(r, ml[q], fa[q], q);
				ml[r] = ml[p]+1; fa[q] = fa[cur] = r;
				for (; p != -1 && chd[p][c] == q; p = fa[p])
					chd[p][c] = r;
			}
		}
	}
}
int main()
{
	id['0'] = 0; id['1'] = 1; id['2'] = 2;
	scanf("%d%d", &N, &M);
	for (int i = 0, n = 0; i < M; i++)
	{
		if (i)
			sw[n++] = '2';
		scanf("%s", sw+n);
		n += strlen(sw+n);
	}
	Construct(sw);
	while (N--)
	{
		scanf("%s", w);
		int l = 0, len = strlen(w), r = len+1, ans;
		while (l < r)
		{
			int mid = (l+r)/2, mml = 0, u = 0, s = 0, t = 0;
			g[t++] = 0;
			for (int i = 1; w[i-1]; i++)
			{
				int c = id[w[i-1]];
				if (chd[u][c] != -1)
					mml++, u = chd[u][c];
				else
				{
					while (u != -1 && chd[u][c] == -1)
						u = fa[u];
					if (u != -1)
						mml = ml[u]+1, u = chd[u][c];
					else
						mml = 0, u = 0;
				}
				d[i] = d[i-1];
				if (mml >= mid)
				{
					while (g[t-1] < i-mid)
					{
						int x = g[t-1]+1;
						while (s < t && d[x]+i-x > d[g[t-1]]+i-g[t-1])
							t--;
						g[t++] = x;
					}
					while (s < t && g[s] < i-mml)
						s++;
					d[i] = max(d[i-1], d[g[s]]+i-g[s]);
				}
			}
			if (10*d[len] >= 9*len)
				l = mid+1, ans = mid;
			else
				r = mid;
		}
		printf("%d\n", ans);
	}
	return 0;
}
