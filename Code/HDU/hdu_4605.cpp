// 2013-08-27 18:29:35	Accepted	4605	2687MS	5808K	2442 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int T, N, M, U, A, B, Q, V, X, w[MAXN], chd[MAXN][2];
int map[MAXM];
int e, head[MAXN], next[MAXN], v[MAXN], q[MAXN][2];
int Tr[MAXN<<2][2];
int n;
void addedge(int x, int y)
{
	e++;
	v[e] = y;
	next[e] = head[x]; head[x] = e;
}
void Update(int idx, int L, int R, int x, int c, int t)
{
	if (x == L && R == x)
	{
		Tr[idx][t] += c;
		return;
	}
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (x <= mid)
		Update(left, L, mid, x, c, t);
	else
		Update(right, mid+1, R, x, c, t);
	Tr[idx][t] = Tr[left][t]+Tr[right][t];
}
int Query(int idx, int L, int R, int l, int r, int t)
{
	if (l <= L && R <= r)
		return Tr[idx][t];
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	int ql = 0, qr = 0;
	if (l <= mid)
		ql = Query(left, L, mid, l, r, t);
	if (mid < r)
		qr = Query(right, mid+1, R, l, r, t);
	return ql+qr;
}
void dfs(int u)
{
	for (int i = head[u]; i != -1; i = next[i])
	{
		int m = lower_bound(map+1, map+1+n, v[i])-map;
		if (Query(1, 1, n, m, m, 0)+Query(1, 1, n, m, m, 1))
		{
			q[i][0] = q[i][1] = -1;
			continue;
		}
		int suml[2] = {}, sumr = 0;
		if (m > 1)
		{
			suml[0] = Query(1, 1, n, 1, m-1, 0);
			suml[1] = Query(1, 1, n, 1, m-1, 1);
		}
		if (m < n)
			sumr = Query(1, 1, n, m+1, n, 0)+Query(1, 1, n, m+1, n, 1);
		q[i][0] = suml[1];
		q[i][1] = (suml[0]+suml[1])*3+sumr;
	}
	if (chd[u][0])
	{
		int m = lower_bound(map+1, map+1+n, w[u])-map;
		Update(1, 1, n, m, 1, 0);
		dfs(chd[u][0]);
		Update(1, 1, n, m, -1, 0);
		Update(1, 1, n, m, 1, 1);
		dfs(chd[u][1]);
		Update(1, 1, n, m, -1, 1);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		e = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &w[i]);
			chd[i][0] = chd[i][1] = 0;
			map[i] = w[i];
			head[i] = -1;
		}
		scanf("%d", &M);
		while (M--)
		{
			scanf("%d%d%d", &U, &A, &B);
			chd[U][0] = A;
			chd[U][1] = B;
		}
		scanf("%d", &Q);
		for (int i = 1; i <= Q; i++)
		{
			scanf("%d%d", &V, &X);
			addedge(V, X);
			map[N+i] = X;
		}
		sort(map+1, map+1+N+Q);
		n = unique(map+1, map+1+N+Q)-(map+1);
		dfs(1);
		for (int i = 1; i <= Q; i++)
		{
			if (q[i][0] == -1 && q[i][1] == -1)
				printf("0\n");
			else
				printf("%d %d\n", q[i][0], q[i][1]);
		}
	}
	return 0;
}
