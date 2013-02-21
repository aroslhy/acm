//Feb 21, 2013 7:32:16 AM 	bigoceanlhy 	235C - Cyclical Quest 	GNU C++ 	Accepted 	921 ms 	240700 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5, MAXM = 2000000+5;
const int MAX_NODE = 2000000+5, MAX_CHD = 26;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE], id[1<<8];
int fail[MAXN];
int N, cnt[MAX_NODE], r[MAX_NODE];
char s[MAXM];
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
	nv = 1; Add(0, 0, -1); cnt[0] = 1;
	int cur = 0;
	for (int i = 0; str[i]; i++)
	{
		int c = id[str[i]], p = cur;
		cur = nv++; Add(cur, i+1, -1); cnt[cur] = 1;
		cnt[cur] = 1;
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
				int r = nv++; Add(r, ml[q], fa[q], q); cnt[r] = 0;
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
void get_fail(char *pat)
{
	fail[0] = -1;
	for (int i = 1, j = -1; pat[i]; i++)
	{
		while (j != -1 && pat[j+1] != pat[i])
			j = fail[j];
		if (pat[j+1] == pat[i])
			j++;
		fail[i] = j;
	}
}
int main()
{
	for (int i = 0; i < MAX_CHD; i++)
		id['a'+i] = i;
	scanf("%s", s);
	Construct(s);
	for (int i = 0; i < nv; i++)
		r[i] = i;
	sort(r, r+nv, cmp);
	for (int i = 0; i < nv; i++)
		cnt[fa[r[i]]] += cnt[r[i]];
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", s);
		get_fail(s);
		int len = strlen(s), cir = len-fail[len-1]-1;
		if (len%cir)
			cir = len;
		memcpy(s+len, s, sizeof(char)*cir);
		s[len+cir-1] = 0;
		int l = 0, u = 0, ans = 0;
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
			if (l >= len)
			{
				if (ml[fa[u]] >= len)
					u = fa[u];
				ans += cnt[u];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
