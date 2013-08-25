#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = (1<<21)+5;
int Q, K, N;
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN];
char cmd[1<<4], ch, val[MAXN];
int NewNode(int f, int t)
{
	nv++;
	if (t < 2)
		chd[f][t] = nv;
	chd[nv][0] = chd[nv][1] = 0;
	fa[nv] = f, toc[nv] = t, sz[nv] = 1;
	return nv;
}
void Update(int x)
{
	sz[x] = sz[chd[x][0]]+1+sz[chd[x][1]];
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
	Update(y);
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
	Update(x);
}
int Find(int x, int rank)
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
void Split(int u, int v)
{
	if (!v)
		return;
	chd[u][1] = 0;
	Update(u);
	fa[v] = 0;
	toc[v] = 2;
}
void Join(int u, int v)
{
	if (!v)
		return;
	chd[u][1] = v;
	fa[v] = u;
	toc[v] = 1;
	Update(u);
}
void Get(int u)
{
	if (chd[u][0])
		Get(chd[u][0]);
	printf("%c", val[u]);
	if (chd[u][1])
		Get(chd[u][1]);
}
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d", &Q);
	nv = 0;
	int root = NewNode(0, 2);
	while (Q--)
	{
		scanf("%s", cmd);
		if (cmd[0] == 'M')
		{
			scanf("%d", &K);
			int u = Find(root, K+1);
			Splay(root = u);
		}
		else if (cmd[0] == 'I')
		{
			scanf("%d", &N);
			int u = root, v = chd[root][1];
			Split(u, v);
			for (int i = 1; i <= N; i++)
			{
				scanf("%c", &ch);
				while (!(32 <= ch && ch <= 126))
					scanf("%c", &ch);
				u = NewNode(u, 1);
				val[u] = ch;
				Splay(u);
			}
			Join(u, v);
			Splay(root);
		}
		else if (cmd[0] == 'D')
		{
			scanf("%d", &N);
			int u = chd[root][1];
			Split(root, u);
			N = min(sz[u], N);
			u = Find(u, N);
			Splay(u);
			int v = chd[u][1];
			Split(u, v);
			Join(root, v);
		}
		else if (cmd[0] == 'G')
		{
			scanf("%d", &N);
			int u = chd[root][1];
			Split(root, u);
			u = Find(u, N);
			Splay(u);
			int v = chd[u][1];
			Split(u, v);
			Get(u);
			printf("\n");
			Join(u, v);
			Join(root, u);
		}
		else if (cmd[0] == 'P')
		{
			int u = chd[root][0];
			if (!u)
				continue;
			while (chd[u][1])
				u = chd[u][1];
			Splay(root = u);
		}
		else
		{
			int v = chd[root][1];
			if (!v)
				continue;
			while (chd[v][0])
				v = chd[v][0];
			Splay(root = v);
		}
	}
	return 0;
}
