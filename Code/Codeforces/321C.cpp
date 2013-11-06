// Nov 6, 2013 4:52:32 PM	bigoceanlhy	 321C - Ciel the Commander	 GNU C++	Accepted	218 ms	10200 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int N, A, B, mark[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
int sz[MAXN];
bool cent[MAXN];
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
void solve_subproblem(int u, int pl)
{
	compute_subtree_size(u, -1);
	int s = search_centroid(u, -1, sz[u]).second;
	cent[s] = 1;
	mark[s] = pl+1;
	for (int i = head[s]; i != -1; i = next[i]) if (!cent[v[i]])
		solve_subproblem(v[i], mark[s]);
}
int main()
{
	scanf("%d", &N);
	fill(head, head+N, -1);
	for (int i = 1; i < N; i++)
	{
		scanf("%d%d", &A, &B);
		A--, B--;
		addedge(A, B);
		addedge(B, A);
	}
	solve_subproblem(0, -1);
	for (int i = 0; i < N; i++)
		printf("%c%s", 'A'+mark[i], i+1 < N ? " " : "\n");
	return 0;
}
