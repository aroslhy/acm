// 11922 	Permutation Transformer 	Accepted 	C++ 	0.475 	2013-09-12 02:02:01
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int N, M, A, B, val[MAXN];
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
void Print(int u)
{
	PushDown(u);
	if (chd[u][0])
		Print(chd[u][0]);
	if (val[u])
		printf("%d\n", val[u]);
	if (chd[u][1])
		Print(chd[u][1]);
}
int main()
{
	scanf("%d%d", &N, &M);
	nv = 0;
	int root = NewNode(0, 2);
	for (int i = 1; i <= N; i++)
	{
		root = NewNode(root, 1);
		val[root] = i;
	}
	Splay(root);
	while (M--)
	{
		scanf("%d%d", &A, &B);
		Splay(root = Find(root, A));
		int u = Split(root, 1);
		if (B < N)
		{
			Splay(u = Find(u, B-A+1));
			int v = Split(u, 1);
			Splay(v = Find(v, sz[v]));
			rvs[u] ^= 1;
			Merge(v, 1, u);
			Merge(root, 1, v);
		}
		else
		{
			rvs[u] ^= 1;
			Merge(root, 1, u);
		}
	}
	Print(root);
	return 0;
}
