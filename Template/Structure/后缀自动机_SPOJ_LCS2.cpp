#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 10+5;
const int MAX_NODE = 200000+5, MAX_CHD = 26;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int mml[MAX_NODE][MAXM], r[MAX_NODE];
char s[MAXN];
namespace Suffix_Automaton
{
	void Initialize()
	{
		for (int i = 0; i < MAX_CHD; i++)
			id['a'+i] = i;
	}
	void Add(int u, int _ml, int _fa, int v = -1)
	{
		ml[u] = _ml; fa[u] = _fa;
		v == -1 ? memset(chd[u], -1, sizeof(chd[u])) : memcpy(chd[u], chd[v], sizeof(chd[v]));
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
}
bool cmp(const int &a, const int &b)
{
	return ml[a] > ml[b];
}
int main()
{
	Suffix_Automaton::Initialize();
	scanf("%s", s);
	Suffix_Automaton::Construct(s);
	for (int i = 0; i < nv; i++)
		r[i] = i;
	sort(r, r+nv, cmp);
	memset(mml, 0, sizeof(mml));
	int cnt = 0;
	for (int i = 1; scanf("%s", s) != EOF; i++, cnt++)
	{
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
		for (int j = 1; j <= cnt; j++)
		{
			mini = min(mini, mml[r[i]][j]);
			mml[fa[r[i]]][j] = max(mml[fa[r[i]]][j], mml[r[i]][j]);
		}
		ans = max(ans, mini);
	}
	printf("%d\n", ans);
	return 0;
}
