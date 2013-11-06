// 2013-11-06 19:42:28	Accepted	4670	4062MS	9468K	2943 B	C++	Aros
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAX = 30;
const int MAXN = 50000+5, MAXM = 100000+5, MAXK = MAX+5;
int N, K, X, Y, sz[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
long long P, ans, prm[MAXK], f[MAXN], pow3[MAXK];
bool cent[MAXN];
map<long long, long long> ds;
vector<long long> tds;
void addedge(int x, int y)
{
	v[e] = y;
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
	pair<int, int> res = make_pair(N, -1);
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
void enumerate_paths(int u, int p, long long d)
{
	long long c = 0;
	for (int k = 0; k < K; k++)
	{
		int a = d/pow3[k]%3, b = (3-a)%3;
		c += b*pow3[k];
	}
	map<long long, long long>::iterator it = ds.find(c);
	if (it != ds.end())
		ans += it->second;
	tds.push_back(d);
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != p && !cent[v[i]])
	{
		long long nd = 0;
		for (int k = 0; k < K; k++)
		{
			int a = d/pow3[k]%3, b = f[v[i]]/pow3[k]%3, c = (a+b)%3;
			nd += c*pow3[k];
		}
		enumerate_paths(v[i], u, nd);
	}
}
void solve_subproblem(int u)
{
	compute_subtree_size(u, -1);
	int s = search_centroid(u, -1, sz[u]).second;
	cent[s] = 1;
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
		solve_subproblem(v[i]);
	ds.clear();
	ds[f[s]]++;
	if (!f[s])
		ans++;
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
	{
		tds.clear();
		enumerate_paths(v[i], s, f[v[i]]);
		for (int j = 0; j < tds.size(); j++)
		{
			long long d = 0;
			for (int k = 0; k < K; k++)
			{
				int a = tds[j]/pow3[k]%3, b = f[s]/pow3[k]%3, c = (a+b)%3;
				d += c*pow3[k];
			}
			ds[d]++;
		}
	}
	cent[s] = 0;
}
int main()
{
	pow3[0] = 1;
	for (int i = 1; i <= MAX; i++)
		pow3[i] = pow3[i-1]*3;
	while (scanf("%d", &N) != EOF)
	{
		e = 0;
		fill(head, head+N, -1);
		scanf("%d", &K);
		for (int i = 0; i < K; i++)
			scanf("%I64d", &prm[i]);
		for (int i = 0; i < N; i++)
		{
			scanf("%I64d", &P);
			f[i] = 0;
			for (int j = 0; j < K; j++)
			{
				int c = 0;
				for (; !(P%prm[j]); c++)
					P /= prm[j];
				f[i] += (c%3)*pow3[j];
			}
		}
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d", &X, &Y);
			X--, Y--;
			addedge(X, Y);
			addedge(Y, X);
		}
		ans = 0;
		solve_subproblem(0);
		printf("%I64d\n", ans);
	}
	return 0;
}
