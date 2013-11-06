// bigoceanlhy	1741	Accepted	1544K	188MS	G++	2239B	2013-11-06 19:47:28
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000+5, MAXM = 20000+5;
int N, K;
int e, head[MAXN], next[MAXM], v[MAXM], w[MAXM];
int ans, sz[MAXN];
bool cent[MAXN];
vector<int> ds, tds;
void addedge(int x, int y, int z)
{
	v[e] = y, w[e] = z;
	next[e] = head[x], head[x] = e++;
}
int compute_subtree_size(int u, int p)
{
	sz[u] = 1;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
		sz[u] += compute_subtree_size(v[i], u);
	return sz[u];
}
pair<int, int> search_centroid(int u, int p, int tot)
{
	pair<int, int> res = make_pair(INF, -1);
	int sum = 1, maxi = 0;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
	{
		res = min(res, search_centroid(v[i], u, tot));
		maxi = max(maxi, sz[v[i]]);
		sum += sz[v[i]];
	}
	maxi = max(maxi, tot-sum);
	res = min(res, make_pair(maxi, u));
	return res;
}
void enumerate_paths(int u, int p, int d, vector<int> &ds)
{
	ds.push_back(d);
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
		enumerate_paths(v[i], u, d+w[i], ds);
}
int count_pairs(vector<int> &ds)
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
void solve_subproblem(int u)
{
	compute_subtree_size(u, -1);
	int s = search_centroid(u, -1, sz[u]).second;
	cent[s] = 1;
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
		solve_subproblem(v[i]);
	ds.assign(1, 0);
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
	{
		tds.clear();
		enumerate_paths(v[i], s, w[i], tds);
		ans -= count_pairs(tds);
		ds.insert(ds.end(), tds.begin(), tds.end());
	}
	ans += count_pairs(ds);
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
			int u, v, len;
			scanf("%d%d%d", &u, &v, &len);
			u--, v--;
			addedge(u, v, len);
			addedge(v, u, len);
		}
		ans = 0;
		solve_subproblem(0);
		printf("%d\n", ans);
	}
	return 0;
}
