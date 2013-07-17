// 1585	Accepted	1076ms	5624kb	G++	2362B	2013-07-16 15:21:17	bigoceanlhy
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int T, N, Q, h[MAXN], A[MAXN], B[MAXN];
int rq[MAXN], rh[MAXN], q[MAXN], s[MAXN], t[MAXN];
int Tr[MAXN<<2];
void Build(int idx, int L, int R)
{
	Tr[idx] = 0;
	if (L == R)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
}
void PushDown(int idx)
{
	int left = idx<<1, right = idx<<1|1;
	Tr[left] += Tr[idx];
	Tr[right] += Tr[idx];
	Tr[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
	if (l <= L && R <= r)
	{
		Tr[idx] += c;
		return;
	}
	if (Tr[idx])
		PushDown(idx);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (l <= mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, c);
}
int Query(int idx, int L, int R, int x)
{
	if (x == L && R == x)
		return Tr[idx];
	if (Tr[idx])
		PushDown(idx);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (x <= mid)
		return Query(left, L, mid, x);
	else
		return Query(right, mid+1, R, x);
}
bool cmpq(const int &a, const int &b)
{
	return B[a] < B[b];
}
bool cmph(const int &a, const int &b)
{
	return t[a] < t[b];
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &N);
		stack<int> stal, star;
		h[0] = 0;
		stal.push(0);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &h[i]);
			while (h[i] <= h[stal.top()])
				stal.pop();
			s[i] = stal.top();
			stal.push(i);
		}
		h[N+1] = INF;
		star.push(N+1);
		for (int i = N; i >= 1; i--)
		{
			while (h[i] >= h[star.top()])
				star.pop();
			t[i] = star.top();
			star.push(i);
			rh[i] = i;
		}
		sort(rh+1, rh+1+N, cmph);
		scanf("%d", &Q);
		for (int i = 1; i <= Q; i++)
		{
			scanf("%d%d", &A[i], &B[i]);
			if (A[i] > B[i])
				swap(A[i], B[i]);
			rq[i] = i;
		}
		sort(rq+1, rq+1+Q, cmpq);
		Build(1, 1, N);
		for (int i = 1, j = 1, k = 1; i <= N; i++)
		{
			for (; t[rh[k]] == i && k <= N; k++) if (s[rh[k]])
				Update(1, 1, N, 1, s[rh[k]], 1);
			for (; B[rq[j]] == i && j <= Q; j++)
				q[rq[j]] = Query(1, 1, N, A[rq[j]]);
		}
		printf("Case %d:\n", cas);
		for (int i = 1; i <= Q; i++)
			printf("%d\n", q[i]);
	}
	return 0;
}
