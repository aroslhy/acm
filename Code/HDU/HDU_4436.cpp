//2013-02-18 13:07:47	Accepted	4436	250MS	12624K	1780 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 110000+5;
const int MAX_NODE = 220000+5, MAX_CHD = 11;
const int MOD = 2012;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE];
int N, r[MAX_NODE], sum[MAX_NODE], cnt[MAX_NODE];
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
		int c = str[i]-'0', p = cur;
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
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0, n = 0; i < N; i++)
		{
			if (i)
				s[n++] = '9'+1;
			scanf("%s", s+n);
			n += strlen(s+n);
		}
		Construct(s);
		for (int i = 0; i < nv; i++)
			r[i] = i;
		sort(r, r+nv, cmp);
		int ans = 0;
		fill(sum, sum+nv, 0);
		fill(cnt, cnt+nv, 0);
		cnt[0] = 1;
		for (int i = 0; i < nv; i++)
		{
			int u = r[i];
			if (i && !cnt[u])
				continue;
			ans = (ans+sum[u])%MOD;
			for (int j = 0; j <= 9; j++) if (u+j && chd[u][j] != -1)
			{
				int v = chd[u][j];
				sum[v] = (sum[v]+10*sum[u]+cnt[u]*j)%MOD;
				cnt[v] += cnt[u];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
