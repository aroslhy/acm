#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 250000+5;
const int MAX_NODE = 500000+5, MAX_CHD = 26;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int cnt[MAX_NODE], r[MAX_NODE], F[MAXN];
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
	memset(cnt, 0, sizeof(cnt));
	int l = 0, u = 0;
	for (int i = 0; s[i]; i++)
	{
		int c = id[s[i]];
		if (chd[u][c] != -1)
			l++, u = chd[u][c];
		else
		{
			while (u != -1 && chd[u][c] == -1)
				u = fa[u];
			l = ml[u]+1, u = chd[u][c];
		}
		cnt[u]++;
	}
	for (int i = 0; i < nv; i++)
	{
		F[ml[r[i]]] = max(F[ml[r[i]]], cnt[r[i]]);
		cnt[fa[r[i]]] += cnt[r[i]];
	}
	for (int i = 1; s[i-1]; i++)
		printf("%d\n", F[i]);
	return 0;
}
