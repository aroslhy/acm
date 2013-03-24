// aroslhy	SPOJ HACKING	Accepted	5018 KB	1280 ms	C++ (g++ 4.0.0-8)	1797 B	2013-03-24 16:39:11
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5;
const int MAX_NODE = 20000+5, MAX_CHD = 26;
const int INF = 0x3f3f3f3f;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE];
int T, N, M, K, r[MAX_NODE], f[MAX_NODE];
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
		int c = str[i]-'a', p = cur;
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
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%s", &N, &M, &K, s);
		Construct(s);
		for (int i = 0; i < nv; i++)
			r[i] = i;
		sort(r, r+nv, cmp);
		for (int i = 0; i < nv; i++)
		{
			int u = r[i];
			f[u] = INF;
			for (int j = 0; j < K; j++)
			{
				if (chd[u][j] == -1)
				{
					f[u] = 0;
					break;
				}
				else
					f[u] = min(f[u], f[chd[u][j]]+1);
			}
		}
		int u = 0;
		for (bool flag = 0; !flag; )
		{
			if (!f[u])
			{
				for (int j = 0; j < K; j++) if (chd[u][j] == -1)
				{
					printf("%c\n", 'a'+j);
					flag = 1;
					break;
				}
			}
			else
			{
				for (int j = 0; j < K; j++) if (f[u] == f[chd[u][j]]+1)
				{
					printf("%c", 'a'+j);
					u = chd[u][j];
					break;
				}
			}
		}
	}
	return 0;
}
