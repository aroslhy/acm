// 3999	The longest constant gene	Accepted	C++	5.689	2013-03-27 10:54:57
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000000+5, MAXM = 12+5;
const int MAX_NODE = 4000000+5, MAX_CHD = 4;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int T, N, mml[MAX_NODE][MAXM], r[MAX_NODE];
char s[MAXN];
void Add(int u, int _ml, int _fa, int v = -1)
{
	ml[u] = _ml, fa[u] = _fa;
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
				ml[r] = ml[p]+1, fa[q] = fa[cur] = r;
				for (; p != -1 && chd[p][c] == q; p = fa[p])
					chd[p][c] = r;
			}
		}
	}
}
bool cmp(const int &a, const int &b)
{
	return ml[a] > ml[b];
}
int main()
{
	id['A'] = 0, id['C'] = 1, id['G'] = 2, id['T'] = 3;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &N, s);
		Construct(s);
		for (int i = 0; i < nv; i++)
			r[i] = i;
		sort(r, r+nv, cmp);
		memset(mml, 0, sizeof(mml));
		for (int i = 1; i < N; i++)
		{
			scanf("%s", s);
			int l = 0, u = 0;
			for (int j = 0; s[j]; j++)
			{
				int c = id[s[j]];
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
				mml[u][i] = max(mml[u][i], l);
			}
		}
		int ans = 0;
		for (int i = 0; i < nv; i++)
		{
			int mini = ml[r[i]];
			for (int j = 1; j < N; j++)
			{
				mini = min(mini, mml[r[i]][j]);
				mml[fa[r[i]]][j] = max(mml[fa[r[i]]][j], mml[r[i]][j]);
			}
			ans = max(ans, mini);
		}
		printf("%d\n", ans);
	}
	return 0;
}
