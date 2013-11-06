/*
题意：给一棵无根树，求任意两点距离小于等于K的点对数量。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 10000+5, MAXM = 20000+5;
int N, K, X, Y, Z;
int e, head[MAXN], next[MAXM], v[MAXM], w[MAXM];
int ans, sz[MAXN];
bool cent[MAXN];
vector<int> ds, tds;
void addedge(int x, int y, int z)
{
	v[e] = y, w[e] = z;
	next[e] = head[x], head[x] = e++;
}
int get_size(int u, int p)
{
	sz[u] = 1;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
		sz[u] += get_size(v[i], u);
	return sz[u];
}
pair<int, int> get_cent(int u, int p, int tot)
{
	pair<int, int> res = make_pair(N, -1);
	int sum = 1, maxi = 0;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
	{
		res = min(res, get_cent(v[i], u, tot));
		maxi = max(maxi, sz[v[i]]);
		sum += sz[v[i]];
	}
	maxi = max(maxi, tot-sum);
	return res = min(res, make_pair(maxi, u));
}
void calc_dist(int u, int p, int d, vector<int> &ds)
{
	ds.push_back(d);
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
		calc_dist(v[i], u, d+w[i], ds);
}
int count_pair(vector<int> &ds)
{
	int res = 0;
	sort(ds.begin(), ds.end());
	for (int i = 0, j = ds.size()-1; i < ds.size() && i < j; i++)
	{
		for (; j > i && ds[i]+ds[j] > K; j--);
		res += j-i;
	}
	return res;
}
void solve_subprob(int u)
{
	get_size(u, -1);
	int s = get_cent(u, -1, sz[u]).second;
	cent[s] = 1;
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
		solve_subprob(v[i]);
	ds.assign(1, 0);
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
	{
		tds.clear();
		calc_dist(v[i], s, w[i], tds);
		ans -= count_pair(tds);
		ds.insert(ds.end(), tds.begin(), tds.end());
	}
	ans += count_pair(ds);
	cent[s] = 0;
}
int main()
{
	while (scanf("%d%d", &N, &K) && !(!N && !K))
	{
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d%d", &X, &Y, &Z);
			addedge(X, Y, Z);
			addedge(Y, X, Z);
		}
		ans = 0;
		solve_subprob(1);
		printf("%d\n", ans);
	}
	return 0;
}
