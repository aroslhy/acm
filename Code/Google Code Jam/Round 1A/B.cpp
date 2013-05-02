#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5;
int T, N, Tr[MAXN<<2];
long long E, R, v[MAXN];
void Build(int idx, int L, int R)
{
	if (L == R)
	{
		Tr[idx] = R;
		return;
	}
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
	if (v[Tr[left]] < v[Tr[right]])
		Tr[idx] = Tr[right];
	else
		Tr[idx] = Tr[left];
}
int Query(int idx, int L, int R, int l, int r)
{
	if (l <= L && R <= r)
		return Tr[idx];
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	int ql = 0, qr = 0;
	if (l <= mid)
		ql = Query(left, L, mid, l, r);
	if (mid < r)
		qr = Query(right, mid+1, R, l, r);
	if (ql && qr)
	{
		if (v[ql] < v[qr])
			return qr;
		else
			return ql;
	}
	else
		return ql+qr;
}
long long solve(int a, int b, long long s, long long t)
{
	if (a > b)
		return 0;
	int id = Query(1, 1, N, a, b);
	long long x = min(s+(id-a)*R, E), y = max(0LL, t-(b-id)*R);
	return solve(a, id-1, s, max(0LL, x-R))+(x-y)*v[id]+solve(id+1, b, min(y+R, E), t);
}
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%lld%lld%d", &E, &R, &N);
		for (int i = 1; i <= N; i++)
			scanf("%lld", &v[i]);
		Build(1, 1, N);
		printf("Case #%d: %lld\n", cas, solve(1, N, E, 0));
	}
	return 0;
}
