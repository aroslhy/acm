// Jun 27, 2013 10:33:10 AM	bigoceanlhy	 319B - Psychos in a Line	 GNU C++	Accepted	 109 ms	 2700 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int N, a[MAXN], p[MAXN], c[MAXN];
int Tr[MAXN<<2];
void Insert(int idx, int L, int R, int x)
{
	if (x <= L && R <= x)
	{
		Tr[idx] = c[x];
		return;
	}
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	if (x <= mid)
		Insert(left, L, mid, x);
	else
		Insert(right, mid+1, R, x);
	Tr[idx] = max(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R, int l, int r)
{
	if (l <= L && R <= r)
		return Tr[idx];
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	int ql = 0, qr = 0;
	if (l <= mid)
		ql = Query(left, L, mid, l, r);
	if (mid < r)
		qr = Query(right, mid+1, R, l, r);
	return max(ql, qr);
}
int main()
{
	scanf("%d", &N);
	vector<int> vec;
	a[0] = INF;
	vec.push_back(0);
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		while (a[i] > a[vec[vec.size()-1]])
			vec.pop_back();
		p[i] = vec[vec.size()-1];
		vec.push_back(i);
		if (!p[i])
			c[i] = INF;
		else if (p[i] < i-1)
			c[i] = Query(1, 1, N, p[i]+1, i-1)+1;
		else
			c[i] = 1;
		Insert(1, 1, N, i);
		if (c[i] < INF)
			ans = max(ans, c[i]);
	}
	printf("%d\n", ans);
	return 0;
}
