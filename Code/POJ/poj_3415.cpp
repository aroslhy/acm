// bigoceanlhy	3415	Accepted	35864K	344MS	G++	2209B	2013-10-22 19:49:37
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
const int MAX_NODE = 200000+5, MAX_CHD = 52;
int K, r[MAX_NODE];
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<7];
long long cnt[MAX_NODE], vis[MAX_NODE];
char s[MAXN];
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
	return ml[a] > ml[b];
}
int main()
{
	for (int i = 0; i < 26; i++)
	{
		id['a'+i] = i;
		id['A'+i] = i+26;
	}
	while (scanf("%d", &K) && K)
	{
		scanf("%s", s);
		Construct(s);
		for (int i = 0; i < nv; i++)
		{
			r[i] = i;
			vis[i] = cnt[i] = 0;
		}
		sort(r, r+nv, cmp);
		int u = 0;
		for (int i = 0; s[i]; i++)
			vis[u = chd[u][id[s[i]]]]++;
		for (int i = 0; i < nv; i++) if (fa[r[i]] != -1)
			vis[fa[r[i]]] += vis[r[i]];
		scanf("%s", s);
		long long ans = 0;
		int l = 0; u = 0;
		for (int i = 0; s[i]; i++)
		{
			int c = id[s[i]];
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
			if (l >= K)
			{
				ans += (l-max(K, ml[fa[u]]+1)+1)*vis[u];
				if (ml[fa[u]] >= K)
					cnt[fa[u]]++;
			}
		}
		for (int i = 0; i < nv; i++)
		{
			int u = r[i];
			if (fa[u] != -1 && ml[fa[u]] >= K)
				cnt[fa[u]] += cnt[u];
			ans += (ml[u]-max(K, ml[fa[u]]+1)+1)*cnt[u]*vis[u];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
