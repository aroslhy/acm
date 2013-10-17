// 2013-10-17 09:26:10	 Accepted	3381	C++	310	1548	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5;
int N, s[MAXN], x[MAXN], y[MAXN];
int Tr[MAXN<<2];
void Update(int idx, int L, int R, int x, int c)
{
	if (x <= L && R <= x)
	{
		Tr[idx] = c;
		return;
	}
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (x <= mid)
		Update(left, L, mid, x, c);
	else
		Update(right, mid+1, R, x, c);
	Tr[idx] = max(Tr[left], Tr[right]);
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
	return max(ql, qr);
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 1; i <= N; i++)
			scanf("%d%d%d", &s[i], &x[i], &y[i]);
		for (int i = N; i > 1; i--)
		{
			if (i+x[i] <= N)
				Update(1, 1, N, i, s[i]+Query(1, 1, N, i+x[i], min(i+y[i]-1, N)));
			else
				Update(1, 1, N, i, s[i]);
		}
		if (x[1] < N)
			printf("%d\n", s[1]+Query(1, 1, N, 1+x[1], min(y[1], N)));
		else
			printf("%d\n", s[1]);
	}
	return 0;
}
