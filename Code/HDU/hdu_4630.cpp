// 2013-07-31 14:42:09	Accepted	4630	1750MS	2416K	2289 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 50000+5;
int T, N, Q, a[MAXN], A[MAXN], B[MAXN];
int pre[MAXN], r[MAXN], q[MAXN];
int Tr[MAXN<<2], mark[MAXN<<2];
bool cmp(const int &a, const int b)
{
	return B[a] < B[b];
}
void Build(int idx, int L, int R)
{
	Tr[idx] = 0;
	mark[idx] = 0;
	if (L == R)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
}
void PushDown(int idx, int L, int R)
{
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (mark[idx] > Tr[left])
	{
		Tr[left] = mark[idx];
		mark[left] = mark[idx];
	}
	if (mark[idx] > Tr[right])
	{
		Tr[right] = mark[idx];
		mark[right] = mark[idx];
	}
	mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
	if (l <= L && R <= r)
	{
		if (c > Tr[idx])
		{
			Tr[idx] = c;
			mark[idx] = c;
		}
		return;
	}
	if (mark[idx])
		PushDown(idx, L, R);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (l <= mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, c);
	Tr[idx] = min(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int x)
{
	if (x == L && R == x)
		return Tr[idx];
	if (mark[idx])
		PushDown(idx, L, R);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (x <= mid)
		return Query(left, L, mid, x);
	else
		return Query(right, mid+1, R, x);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		fill(pre+1, pre+1+N, 0);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		scanf("%d", &Q);
		for (int i = 1; i <= Q; i++)
		{
			scanf("%d%d", &A[i], &B[i]);
			r[i] = i;
		}
		sort(r+1, r+1+Q, cmp);
		Build(1, 1, N);
		for (int i = 1, j = 1; i <= N && j <= Q; i++)
		{
			int n = sqrt(a[i]);
			for (int d = 1; d <= n; d++) if (!(a[i]%d))
			{
				if (pre[d])
					Update(1, 1, N, 1, pre[d], d);
				pre[d] = i;
				if (d*d == a[i])
					break;
				if (pre[a[i]/d])
					Update(1, 1, N, 1, pre[a[i]/d], a[i]/d);
				pre[a[i]/d] = i;
			}
			for (; j <= Q && B[r[j]] == i; j++)
				q[r[j]] = Query(1, 1, N, A[r[j]]);
		}
		for (int i = 1; i <= Q; i++)
			printf("%d\n", q[i]);
	}
	return 0;
}
