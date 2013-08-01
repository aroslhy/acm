// 2013-08-01 18:47:39	Accepted	4638	1140MS	4376K	2121 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5;
int T, N, M, id[MAXN], A[MAXN], B[MAXN];
int pos[MAXN], pre1[MAXN], pre2[MAXN], r[MAXN], q[MAXN];
int Tr[MAXN<<2];
bool cmp(const int &a, const int &b)
{
	return B[a] < B[b];
}
void Build(int idx, int L, int R)
{
	Tr[idx] = 0;
	if (L == R)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
}
void PushDown(int idx, int L, int R)
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
		PushDown(idx, L, R);
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
		scanf("%d%d", &N, &M);
		fill(pos+1, pos+1+N, 0);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &id[i]);
			pre1[i] = pre2[i] = 0;
			if (id[i]-1 >= 1)
				pre1[i] = pos[id[i]-1];
			if (id[i]+1 <= N)
				pre2[i] = pos[id[i]+1];
			pos[id[i]] = i;
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%d%d", &A[i], &B[i]);
			r[i] = i;
		}
		sort(r+1, r+1+M, cmp);
		Build(1, 1, N);
		for (int i = 1, j = 1; i <= N && j <= M; i++)
		{
			Update(1, 1, N, 1, i, 1);
			if (pre1[i])
				Update(1, 1, N, 1, pre1[i], -1);
			if (pre2[i])
				Update(1, 1, N, 1, pre2[i], -1);
			for (; j <= M && B[r[j]] == i; j++)
				q[r[j]] = Query(1, 1, N, A[r[j]]);
		}
		for (int i = 1; i <= M; i++)
			printf("%d\n", q[i]);
	}
	return 0;
}
