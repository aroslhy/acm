//bigoceanlhy	3080	Accepted	176K	0MS	C++	2532B	2013-02-20 09:48:54
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 60+5, MAXM = 10+5;
const int MAX_NODE = 120+5, MAX_CHD = 4;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int T, M, Maxlen, Flag;
int mml[MAX_NODE][MAXM], r[MAX_NODE], ter[MAX_NODE];
char s[2][MAXN];
void Add(int u, int _ml, int _fa, int _ter, int v = -1)
{
	ml[u] = _ml; fa[u] = _fa; ter[u] = _ter;
	if (v == -1)
		memset(chd[u], -1, sizeof(chd[u]));
	else
		memcpy(chd[u], chd[v], sizeof(chd[v]));
}
void Construct(char *str)
{
	nv = 1; Add(0, 0, -1, 0);
	int cur = 0;
	for (int i = 0; str[i]; i++)
	{
		int c = id[str[i]], p = cur;
		cur = nv++; Add(cur, i+1, -1, i+1);
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
				int r = nv++; Add(r, ml[q], fa[q], ml[q], q);
				ml[r] = ml[p]+1; fa[q] = fa[cur] = r;
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
void dfs(int u, int len)
{
	if (mml[u][0] == len && len == Maxlen)
	{
		for (int i = 0; i < Maxlen; i++)
			printf("%c", s[0][ter[u]-Maxlen+i]);
		printf("\n");
		Flag = 1;
		return;
	}
	for (int i = 0; i < MAX_CHD && !Flag; i++) if (chd[u][i] != -1)
		dfs(chd[u][i], len+1);
}
int main()
{
	id['A'] = 0; id['C'] = 1; id['G'] = 2; id['T'] = 3;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &M, s[0]);
		Construct(s[0]);
		for (int i = 0; i < nv; i++)
			r[i] = i;
		sort(r, r+nv, cmp);
		memset(mml, 0, sizeof(mml));
		for (int i = 1; i < M; i++)
		{
			scanf("%s", s[1]);
			int l = 0, u = 0;
			for (int j = 0; s[1][j]; j++)
			{
				int c = id[s[1][j]];
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
		Maxlen = 0;
		for (int i = 0; i < nv; i++)
		{
			int u = r[i];
			mml[u][0] = ml[u];
			for (int j = 1; j < M; j++)
			{
				mml[u][0] = min(mml[u][0], mml[u][j]);
				mml[fa[u]][j] = max(mml[fa[u]][j], mml[u][j]);
			}
			Maxlen = max(Maxlen, mml[u][0]);
		}
		if (Maxlen < 3)
			printf("no significant commonalities\n");
		else
		{
			Flag = 0;
			dfs(0, 0);
		}
	}
	return 0;
}
