// 2013-09-14 10:26:38	Accepted	4441	1046MS	10148K	3337 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 200000+5;
int N, X, val[MAXN], neg[MAXN], pos[MAXN][2];
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN], stack[MAXN];
long long sum[MAXN];
char ope[10];
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
	int ls = chd[u][0], rs = chd[u][1];
	sz[u] = sz[ls]+1+sz[rs];
	neg[u] = neg[ls]+(val[u] < 0)+neg[rs];
	sum[u] = sum[ls]+val[u]+sum[rs];
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
int main()
{
	for (int cas = 1; scanf("%d", &N) != EOF; cas++)
	{
		set<int> st;
		for (int i = 1; i <= N; i++)
			st.insert(i);
		printf("Case #%d:\n", cas);
		nv = 0;
		int root = NewNode(0, 2);
		val[root] = 0;
		while (N--)
		{
			scanf("%s%d", ope, &X);
			if (ope[0] == 'i')
			{
				int mini = *st.begin();
				st.erase(st.begin());
				Splay(root = Find(root, X+1));
				int u = Split(root, 1);
				root = NewNode(root, 1);
				val[root] = mini;
				Splay(root);
				pos[mini][0] = root;
				Merge(root, 1, u);
				int rank = sz[u]-neg[u];
				if (rank)
				{
					int v = u;
					for (; ; )
					{
						int ls = chd[v][0], rs = chd[v][1];
						if (rank == neg[rs]+1 && val[v] < 0)
							break;
						if (rank <= neg[rs])
							v = rs;
						else
						{
							rank -= neg[rs]+(val[v] < 0);
							v = ls;
						}
					}
					Splay(root = v);
					int w = Split(root, 0);
					root = NewNode(root, 0);
					val[root] = -mini;
					Splay(root);
					pos[mini][1] = root;
					Merge(root, 0, w);
				}
				else
				{
					Splay(root = Find(root, sz[root]));
					root = NewNode(root, 1);
					val[root] = -mini;
					Splay(root);
					pos[mini][1] = root;
				}
			}
			else if (ope[0] == 'r')
			{
				Splay(root = pos[X][0]);
				int u = Split(root, 0), v = Split(root, 1);
				Splay(root = Find(u, sz[u]));
				Merge(root, 1, v);
				Splay(root = pos[X][1]);
				int w = Split(root, 0), x = Split(root, 1);
				Splay(root = Find(w, sz[w]));
				Merge(root, 1, x);
				st.insert(X);
			}
			else
			{
				Splay(root = pos[X][0]);
				int u = Split(root, 1);
				Splay(u = pos[X][1]);
				int v = chd[u][0];
				printf("%I64d\n", sum[v]);
				Merge(root, 1, u);
			}
		}
	}
	return 0;
}
