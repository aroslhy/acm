// 2013-08-24 22:08:33	Accepted	4699	1671MS	28472K	2567 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5;
int Q, X, val[MAXN], sum[MAXN], maxi[MAXN];
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN];
char cmd[5];
int NewNode(int f, int t)
{
	nv++;
	if (t < 2)
		chd[f][t] = nv;
	chd[nv][0] = chd[nv][1] = 0;
	fa[nv] = f, toc[nv] = t, sz[nv] = 1;
	return nv;
}
void UpdateSize(int x)
{
	sz[x] = sz[chd[x][0]]+1+sz[chd[x][1]];
	sum[x] = sum[chd[x][0]]+val[x]+sum[chd[x][1]];
	if (x == 1)
	{
		maxi[x] = -0x3f3f3f3f;
		return;
	}
	maxi[x] = max(maxi[chd[x][0]], sum[chd[x][0]]+val[x]);
	maxi[x] = max(maxi[x], sum[chd[x][0]]+val[x]+maxi[chd[x][1]]);
}
void Rotate(int x)
{
	int t = toc[x], y = fa[x], z = chd[x][1-t];
	toc[x] = toc[y];
	fa[x] = fa[y];
	if (toc[x] != 2)
		chd[fa[x]][toc[x]] = x;
	toc[y] = 1-t;
	fa[y] = x;
	chd[x][1-t] = y;
	if (z)
	{
		toc[z] = t;
		fa[z] = y;
	}
	chd[y][t] = z;
	UpdateSize(y);
}
void Splay(int x)
{
	while (toc[x] != 2)
	{
		int y = fa[x];
		if (toc[x] == toc[y])
			Rotate(y);
		else
			Rotate(x);
		if (toc[x] == 2)
			break;
		Rotate(x);
	}
	UpdateSize(x);
}
int find(int x, int rank)
{
	for (; ; )
	{
		if (sz[chd[x][0]]+1 == rank)
			break;
		if (rank <= sz[chd[x][0]])
			x = chd[x][0];
		else
		{
			rank -= sz[chd[x][0]]+1;
			x = chd[x][1];
		}
	}
	return x;
}
int main()
{
	while (scanf("%d", &Q) != EOF)
	{
		scanf("%d", &Q);
		nv = 0;
		int cur = NewNode(0, 2);
		while (Q--)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'I')
			{
				scanf("%d", &X);
				int v = chd[cur][1], u = NewNode(cur, 1);
				val[u] = X;
				UpdateSize(cur);
				Splay(cur = u);
				chd[cur][1] = v;
				if (v)
					fa[v] = u;
				UpdateSize(cur);
			}
			else if (cmd[0] == 'D')
			{
				int u = chd[cur][0], v = chd[cur][1];
				if (!u)
					continue;
				fa[u] = 0, toc[u] = 2;
				while (chd[u][1])
					u = chd[u][1];
				Splay(cur = u);
				chd[cur][1] = v;
				if (v)
					fa[v] = cur;
				UpdateSize(cur);
			}
			else if (cmd[0] == 'L')
			{
				int u = chd[cur][0];
				if (!u)
					continue;
				while (chd[u][1])
					u = chd[u][1];
				Splay(cur = u);
			}
			else if (cmd[0] == 'R')
			{
				int u = chd[cur][1];
				if (!u)
					continue;
				while (chd[u][0])
					u = chd[u][0];
				Splay(cur = u);
			}
			else
			{
				scanf("%d", &X);
				int u = find(cur, X+1);
				Splay(u);
				printf("%d\n", max(maxi[chd[u][0]], sum[chd[u][0]]+val[u]));
				Splay(cur);
			}
		}
	}
	return 0;
}
