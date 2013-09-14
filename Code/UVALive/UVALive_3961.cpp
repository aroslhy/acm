// 3961 	Robotic Sort 	Accepted 	C++ 	0.246 	2013-09-12 10:23:58
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, val[MAXN], pos[MAXN], r[MAXN];
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN], rvs[MAXN], stack[MAXN];
int NewNode(int f, int t)
{
	nv++;
	if (t < 2)
		chd[f][t] = nv;
	chd[nv][0] = chd[nv][1] = 0;
	fa[nv] = f, toc[nv] = t, rvs[nv] = 0, sz[nv] = 1;
	return nv;
}
void PushUp(int u)
{
	int &ls = chd[u][0], &rs = chd[u][1];
	sz[u] = sz[ls]+1+sz[rs];
}
void PushDown(int u)
{
	if (!rvs[u])
		return;
	int &ls = chd[u][0], &rs = chd[u][1];
	swap(ls, rs);
	toc[ls] = 0;
	rvs[ls] ^= 1;
	toc[rs] = 1;
	rvs[rs] ^= 1;
	rvs[u] = 0;
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
	int top = 0;
	stack[top++] = u;
	for (int i = u; toc[i] != 2; i = fa[i])
		stack[top++] = fa[i];
	while (top)
		PushDown(stack[--top]);
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
		PushDown(u);
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
bool cmp(const int &a, const int &b)
{
	if (val[a] != val[b])
		return val[a] < val[b];
	else
		return a < b;
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		nv = 0;
		int root = NewNode(0, 2);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &val[i]);
			root = NewNode(root, 1);
			pos[i] = root;
			r[i] = i;
		}
		sort(r+1, r+1+N, cmp);
		Splay(root);
		for (int i = 1; i <= N; i++)
		{
			Splay(root = pos[r[i]]);
			if (i > 1)
				printf(" ");
			printf("%d", i+sz[chd[root][0]]-1);
			int u = Split(root, 0), v = Split(root, 1);
			Splay(u = Find(u, 1));
			int w = Split(u, 1);
			rvs[w] ^= 1;
			Merge(u, 1, w);
			Splay(root = Find(u, sz[u]));
			Merge(root, 1, v);
		}
		printf("\n");
	}
	return 0;
}
