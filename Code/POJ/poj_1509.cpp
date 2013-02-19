//bigoceanlhy	1509	Accepted	2620K	0MS	G++	1374B	2013-02-19 10:09:33
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000+5;
const int MAX_NODE = 40000+5, MAX_CHD = 26;
int nv, chd[MAX_NODE][MAX_CHD], ml[MAX_NODE], fa[MAX_NODE];
int N;
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
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", s);
		int len = strlen(s);
		memcpy(s+len, s, sizeof(char)*(len+1));
		Construct(s);
		int u = 0, l = 0;
		bool flag = 1;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < MAX_CHD && !flag; i++) if (chd[u][i] != -1)
			{
				l++;
				u = chd[u][i];
				flag = 1;
			}
		}
		printf("%d\n", 2*len-l+1);
	}
	return 0;
}
