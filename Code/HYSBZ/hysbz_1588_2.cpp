// bigoceanlhy	1588	Accepted	2204 kb	592 ms	C++/Edit	2465 B	2013-03-19 11:28:30
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 50000+5;
const int INF = 0x3f3f3f3f;
int nv, root, chd[MAXN][2], fa[MAXN], toc[MAXN], rvs[MAXN], sz[MAXN];
namespace SplayTree
{
	int NewNode(int f, int t)
	{
		chd[f][t] = ++nv;
		chd[nv][0] = chd[nv][1] = 0;
		fa[nv] = f, toc[nv] = t, rvs[nv] = 0, sz[nv] = 1;
		return nv;
	}
	void UpdateSize(int x)
	{
		sz[x] = sz[chd[x][0]]+1+sz[chd[x][1]];
	}
	void PushDown(int x)
	{
		if (rvs[x])
		{
			swap(chd[x][0], chd[x][1]);
			toc[chd[x][0]] = 0;
			rvs[chd[x][0]] ^= 1;
			toc[chd[x][1]] = 1;
			rvs[chd[x][1]] ^= 1;
			rvs[x] = 0;
		}
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
		stack<int> sta;
		sta.push(x);
		for (int i = x; toc[i] != 2; i = fa[i])
			sta.push(fa[i]);
		while (!sta.empty())
			PushDown(sta.top()), sta.pop();
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
}
int N, x, val[MAXN];
int main()
{
	scanf("%d%d", &N, &x);
	root = SplayTree::NewNode(0, 2);
	val[root] = x;
	int ans = x;
	for (int i = 1; i < N; i++)
	{
		if (scanf("%d", &x) == EOF)
			x = 0;
		int u, v = root, t = 3;
		while (t != 2)
		{
			u = v;
			t = 2;
			if (x < val[u])
				v = chd[u][0], t = 0;
			else if (x > val[u])
				v = chd[u][1], t = 1;
			if (!v)
			{
				v = SplayTree::NewNode(u, t);
				val[v] = x;
				break;
			}
		}
		if (t != 2)
		{
			int d = INF;
			root = v;
			SplayTree::Splay(root);
			if (u = chd[root][0])
			{
				while (chd[u][1])
					u = chd[u][1];
				d = min(d, abs(x-val[u]));
			}
			if (u = chd[root][1])
			{
				while (chd[u][0])
					u = chd[u][0];
				d = min(d, abs(x-val[u]));
			}
			ans += d;
		}
	}
	printf("%d\n", ans);
	return 0;
}
