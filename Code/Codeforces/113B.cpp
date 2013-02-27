//Feb 27, 2013 6:01:36 PM 	bigoceanlhy 	113B - Petr# 	GNU C++ 	Accepted 	93 ms 	500 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5;
const int MAX_NODE = 4000+5, MAX_CHD = 26;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int r[MAX_NODE], lensb, lense, ans;
char t[MAXN], sb[MAXN], se[MAXN];
bool mark[MAX_NODE];
void Initialize()
{
	for (int i = 0; i < MAX_CHD; i++)
		id['a'+i] = i;
}
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
bool cmp(const int &a, const int &b)
{
	return ml[a] < ml[b];
}
void dfs(int u, int len)
{
	if (mark[u] && len >= lense)
		ans++;
	for (int i = 0; i < MAX_CHD; i++) if (chd[u][i] != -1)
		dfs(chd[u][i], len+1);
}
int main()
{
	Initialize();
	scanf("%s%s%s", t, sb, se);
	Construct(t);
	for (int i = 0; i < nv; i++)
		r[i] = i;
	sort(r, r+nv, cmp);
	lensb = 0, lense = 0;
	int l = 0, u = 0;
	for (int i = 0; se[i]; i++)
	{
		int c = id[se[i]];
		if (chd[u][c] != -1)
			l++, u = chd[u][c];
		else
		{
			while (u != -1 && chd[u][c] == -1)
				u = fa[u];
			if (u != -1)
				l = ml[u]+1, u = chd[u][c];
			else
				l = 0, u = 0;
		}
		lense++;
	}
	ans = 0;
	if (l == lense)
	{
		memset(mark, 0, sizeof(mark));
		mark[u] = 1;
		for (int i = 0; i < nv; i++)
			if (mark[fa[r[i]]])
				mark[r[i]] = 1;
		int l = 0, u = 0;
		for (int i = 0; sb[i]; i++)
		{
			int c = id[sb[i]];
			if (chd[u][c] != -1)
				l++, u = chd[u][c];
			else
			{
				while (u != -1 && chd[u][c] == -1)
					u = fa[u];
				if (u != -1)
					l = ml[u]+1, u = chd[u][c];
				else
					l = 0, u = 0;
			}
			lensb++;
		}
		if (l == lensb)
			dfs(u, lensb);
	}
	printf("%d\n", ans);
	return 0;
}
