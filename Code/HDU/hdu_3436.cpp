// 2013-09-13 14:32:39	Accepted	3436	406MS	8320K	3312 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 200000+5, MAXM = 100000+5;
int T, N, Q, X[MAXN], len[MAXN], val[MAXN], sum[MAXN];
int nv, chd[MAXN][2], fa[MAXN], toc[MAXN], sz[MAXN];
char ope[MAXM][10];
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
	sum[u] = sum[ls]+len[u]+sum[rs];
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
		int ls = chd[u][0], rs = chd[u][1];
		if (sz[ls]+1 == rank)
			break;
		if (rank <= sz[ls])
			u = ls;
		else
		{
			rank -= sz[ls]+1;
			u = rs;
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
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		nv = 0;
		scanf("%d%d", &N, &Q);
		vector<int> V;
		V.push_back(0);
		for (int i = 0; i < Q; i++)
		{
			scanf("%s%d", ope[i], &X[i]);
			if (ope[i][0] == 'T' || ope[i][0] == 'Q')
				V.push_back(X[i]);
		}
		sort(V.begin(), V.end());
		int n = unique(V.begin(), V.end())-V.begin();
		map<int, int> p;
		int root = NewNode(0, 2);
		sum[root] = len[root] = 0;
		for (int i = 1; i < n; i++)
		{
			if (V[i] > V[i-1]+1)
			{
				root = NewNode(root, 1);
				val[root] = V[i-1]+1;
				sum[root] = len[root] = V[i]-V[i-1]-1;
			}
			root = NewNode(root, 1);
			val[root] = V[i];
			sum[root] = len[root] = 1;
			p.insert(make_pair(V[i], root));
		}
		if (N > V[n-1])
		{
			root = NewNode(root, 1);
			val[root] = V[n-1]+1;
			sum[root] = len[root] = N-V[n-1];
		}
		Splay(root);
		Splay(root = Find(root, 1));
		root = Split(root, 1);
		printf("Case %d:\n", cas);
		for (int i = 0; i < Q; i++)
		{
			if (ope[i][0] == 'T')
			{
				Splay(root = p.find(X[i])->second);
				if (!chd[root][0])
					continue;
				int u = Split(root, 0), v = Split(root, 1);
				Merge(root, 1, u);
				Splay(root = Find(root, sz[root]));
				Merge(root, 1, v);
			}
			else if (ope[i][0] == 'Q')
			{
				Splay(root = p.find(X[i])->second);
				printf("%d\n", sum[chd[root][0]]+1);
			}
			else
			{
				int u = root, rank = X[i];
				for (; ; )
				{
					int ls = chd[u][0], rs = chd[u][1];
					if (sum[ls]+1 <= rank && rank <= sum[ls]+len[u])
						break;
					if (rank <= sum[ls])
						u = ls;
					else
					{
						rank -= sum[ls]+len[u];
						u = rs;
					}
				}
				printf("%d\n", val[u]+rank-sum[chd[u][0]]-1);
			}
		}
	}
	return 0;
}
