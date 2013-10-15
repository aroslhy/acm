/*
Kth Number
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 3321933+5;
int T, N, M, a[MAXN], A, B, K;
int nv, root[MAXN], chd[MAXM][2], cnt[MAXM];
int map[MAXN];
int Build(int L, int R)
{
	int u = nv++;
	cnt[u] = 0;
	if (L == R)
		return u;
	int mid = (L+R)>>1;
	chd[u][0] = Build(L, mid);
	chd[u][1] = Build(mid+1, R);
	return u;
}
int Update(int pre, int L, int R, int pos)
{
	int u = nv++;
	cnt[u] = cnt[pre]+1;
	if (L == R)
		return u;
	int mid = (L+R)>>1;
	if (pos <= mid)
	{
		chd[u][0] = Update(chd[pre][0], L, mid, pos);
		chd[u][1] = chd[pre][1];
	}
	else
	{
		chd[u][0] = chd[pre][0];
		chd[u][1] = Update(chd[pre][1], mid+1, R, pos);
	}
	return u;
}
int Query(int rl, int rr, int L, int R, int rank)
{
	if (L == R)
		return R;
	int mid = (L+R)>>1, tmp = cnt[chd[rr][0]]-cnt[chd[rl][0]];
	if (rank <= tmp)
		return Query(chd[rl][0], chd[rr][0], L, mid, rank);
	else
		return Query(chd[rl][1], chd[rr][1], mid+1, R, rank-tmp);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			map[i] = a[i];
		}
		sort(map+1, map+1+N);
		int n = unique(map+1, map+1+N)-(map+1);
		nv = 0;
		root[0] = Build(1, n);
		for (int i = 1; i <= N; i++)
			root[i] = Update(root[i-1], 1, n, lower_bound(map+1, map+1+n, a[i])-map);
		while (M--)
		{
			scanf("%d%d%d", &A, &B, &K);
			int id = Query(root[A-1], root[B], 1, n, K);
			printf("%d\n", map[id]);
		}
	}
	return 0;
}
