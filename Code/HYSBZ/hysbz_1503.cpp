// bigoceanlhy	1503	Accepted	3932 kb	1008 ms	C++/Edit	3188 B	2013-03-20 19:45:34
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int nv, root, chd[MAXN][2], fa[MAXN], toc[MAXN], rvs[MAXN], sz[MAXN];
int N, M, K, val[MAXN], cnt[MAXN];
char cmd[5];
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
//		sz[x] = sz[chd[x][0]]+1+sz[chd[x][1]];
		sz[x] = sz[chd[x][0]]+cnt[x]+sz[chd[x][1]];
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
//		stack<int> sta;
//		sta.push(x);
//		for (int i = x; toc[i] != 2; i = fa[i])
//			sta.push(fa[i]);
//		while (!sta.empty())
//			PushDown(sta.top()), sta.pop();
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
	int Find(int x, int rank)
	{
		for (; ; )
		{
//			PushDown(x);
			if (sz[chd[x][1]] < rank && rank <= sz[chd[x][1]]+cnt[x])
				break;
			if (rank <= sz[chd[x][1]])
				x = chd[x][1];
			else
			{
				rank -= sz[chd[x][1]]+cnt[x];
				x = chd[x][0];
			}
		}
		return x;
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	root = SplayTree::NewNode(0, 2);
	val[root] = INF;
	int tot = 0, m = M;
	while (N--)
	{
		scanf("%s%d", cmd, &K);
		if (cmd[0] == 'I')
		{
			if (K < M)
				continue;
			int u, v = root, t = 3, k = K-M+m;
			while (t != 2)
			{
				u = v;
				if (k < val[u])
					v = chd[u][0], t = 0;
				else if (k > val[u])
					v = chd[u][1], t = 1;
				else
					t = 2;
				if (!v)
				{
					v = SplayTree::NewNode(u, t);
					val[v] = k;
					break;
				}
			}
			cnt[v]++;
			SplayTree::Splay(root = v);
		}
		else if (cmd[0] == 'A' || cmd[0] == 'S')
		{
			if (cmd[0] == 'A')
				m -= K;
			else
				m += K;
			int u = root, v;
			while (u)
			{
				if (val[u] >= m)
				{
					v = u;
					u = chd[u][0];
				}
				else
					u = chd[u][1];
			}
			SplayTree::Splay(root = v);
			tot += sz[chd[root][0]];
			chd[root][0] = 0;
			SplayTree::Splay(root);
		}
		else if (K <= sz[root])
			printf("%d\n", val[SplayTree::Find(root, K)]-m+M);
		else
			printf("-1\n");
	}
	printf("%d\n", tot);
	return 0;
}
