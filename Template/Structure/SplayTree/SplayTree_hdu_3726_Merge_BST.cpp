#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000+5, MAXM = 60000+5, MAXQ = 460000+5;
int N, M, val[MAXN], u[MAXM], v[MAXM], X[MAXQ], K[MAXQ], V[MAXQ], root[MAXN];
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN];
char ope[MAXQ][5];
bool del[MAXM];
int NewNode(int f, int t)
{
	nv++;
	if (t < 2)
		chd[f][t] = nv;
	chd[nv][0] = chd[nv][1] = 0;
	fa[nv] = f, toc[nv] = t, sz[nv] = 1;
	return nv;
}
void PushUp(int u)
{
	int &ls = chd[u][0], &rs = chd[u][1];
	sz[u] = sz[ls]+1+sz[rs];
}
void Rotate(int u)
{
	int t = toc[u], v = fa[u], w = chd[u][t^1];
	toc[u] = toc[v];
	fa[u] = fa[v];
	if (toc[u] != 2)
		chd[fa[u]][toc[u]] = u;
	toc[v] = t^1;
	fa[v] = u;
	chd[u][t^1] = v;
	if (w)
	{
		toc[w] = t;
		fa[w] = v;
	}
	chd[v][t] = w;
	PushUp(v);
}
void Splay(int u)
{
	while (toc[u] != 2)
	{
		int v = fa[u];
		if (toc[u] == toc[v])
			Rotate(v);
		else
			Rotate(u);
		if (toc[u] == 2)
			break;
		Rotate(u);
	}
	PushUp(u);
}
int Find(int u, int rank)
{
	for (; ; )
	{
		if (sz[chd[u][0]]+1 == rank)
			break;
		if (rank <= sz[chd[u][0]])
			u = chd[u][0];
		else
		{
			rank -= sz[chd[u][0]]+1;
			u = chd[u][1];
		}
	}
	return u;
}
int Split(int u, int t)
{
	int v = chd[u][t];
	if (!v)
		return 0;
	chd[u][t] = 0;
	PushUp(u);
	fa[v] = 0;
	toc[v] = 2;
	return v;
}
void Merge(int u, int t, int v)
{
	if (!v)
		return;
	chd[u][t] = v;
	fa[v] = u;
	toc[v] = t;
	PushUp(u);
}
void Insert(int u, int v)
{
	for (; ; )
	{
		int t = val[v] > val[u];
		if (!chd[u][t])
		{
			Merge(u, t, v);
			break;
		}
		else
			u = chd[u][t];
	}
	Splay(v);
}
int Merge_BST(int u, int v)
{
	if (chd[v][0])
		u = Merge_BST(u, chd[v][0]);
	if (chd[v][1])
		u = Merge_BST(u, chd[v][1]);
	if (fa[v])
		Split(fa[v], toc[v]);
	Insert(u, v);
	return v;
}
int findroot(int x)
{
	return root[x] == x ? x : root[x] = findroot(root[x]);
}
int main()
{
	for (int cas = 1; scanf("%d%d", &N, &M) && N && M; cas++)
	{
		nv = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &val[i]);
			NewNode(0, 2);
			root[i] = i;
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%d%d", &u[i], &v[i]);
			del[i] = 0;
		}
		int Q = 1;
		for (; ; Q++)
		{
			scanf("%s", ope[Q]);
			if (ope[Q][0] == 'E')
				break;
			if (ope[Q][0] == 'D')
			{
				scanf("%d", &X[Q]);
				del[X[Q]] = 1;
			}
			else if (ope[Q][0] == 'Q')
				scanf("%d%d", &X[Q], &K[Q]);
			else
			{
				scanf("%d%d", &X[Q], &V[Q]);
				swap(V[Q], val[X[Q]]);
			}
		}
		Q--;
		for (int i = 1; i <= M; i++) if (!del[i])
		{
			int x = findroot(u[i]), y = findroot(v[i]);
			if (x == y)
				continue;
			if (sz[x] < sz[y])
				swap(x, y);
			Merge_BST(x, y);
			root[x] = y;
		}
		long long ans = 0, cnt = 0;
		for (int i = Q; i >= 1; i--)
		{
			if (ope[i][0] == 'D')
			{
				int x = findroot(u[X[i]]), y = findroot(v[X[i]]);
				if (x == y)
					continue;
				if (sz[x] < sz[y])
					swap(x, y);
				Merge_BST(x, y);
				root[x] = y;
			}
			else if (ope[i][0] == 'Q')
			{
				int x = findroot(X[i]);
				if (0 < K[i] && K[i] <= sz[x])
					ans += val[Find(x, sz[x]-K[i]+1)];
				cnt++;
			}
			else
			{
				root[X[i]] = root[findroot(X[i])] = X[i];
				Splay(X[i]);
				if (chd[X[i]][0] && chd[X[i]][1])
				{
					int u = Split(X[i], 0),  v = Split(X[i], 1);
					val[X[i]] = V[i];
					Splay(u = Find(u, sz[u]));
					Merge(u, 1, v);
					Insert(u, X[i]);
				}
				else if (chd[X[i]][0])
				{
					int x = Split(X[i], 0);
					val[X[i]] = V[i];
					Insert(x, X[i]);
				}
				else if (chd[X[i]][1])
				{
					int x = Split(X[i], 1);
					val[X[i]] = V[i];
					Insert(x, X[i]);
				}
				else
					val[X[i]] = V[i];
			}
		}
		printf("Case %d: %.6lf\n", cas, (double)ans/cnt);
	}
	return 0;
}
