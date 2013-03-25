// aroslhy	SPOJ BTCODE_C	Accepted	14336 KB	2230 ms	C++ (g++ 4.0.0-8)	2044 B	2013-03-25 18:12:13
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 200000+5;
int N, t[MAXN];
int Tr[MAXN<<2], mark[MAXN<<2];
long long v[MAXN], num[MAXN];
void PushDown(int idx)
{
	int left = idx<<1, right = idx<<1|1;
	Tr[left] += mark[idx];
	mark[left] += mark[idx];
	Tr[right] += mark[idx];
	mark[right] += mark[idx];
	mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c)
{
	if (l <= L && R <= r)
	{
		Tr[idx] += c;
		mark[idx] += c;
		return;
	}
	if (mark[idx])
		PushDown(idx);
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	if (l <= mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, c);
}
long long Query(int idx, int L, int R, int x)
{
	if (x == L && R == x)
		return Tr[idx];
	if (mark[idx])
		PushDown(idx);
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	if (x <= mid)
		return Query(left, L, mid, x);
	else
		return Query(right, mid+1, R, x);
}
int main()
{
	scanf("%d", &N);
	vector<long long> vec;
	vec.push_back(0);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%lld", &t[i], &v[i]);
		if (t[i] == 1)
			vec.push_back(v[i]+1);
		else if (t[i] == 2)
			vec.push_back(v[i]-1);
		else if (t[i] == 3)
			vec.push_back(v[i]);
		else
			vec.push_back(v[i]-1), vec.push_back(v[i]+1);
	}
	sort(vec.begin(), vec.end());
	int n = 0;
	map<long long, int> id;
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (!n || vec[i] != vec[i-1])
		{
			num[n] = vec[i];
			id[num[n]] = n++;
		}
	}
	num[n] = num[n-1]+1;
	for (int i = 0; i < N; i++)
	{
		if (t[i] == 1)
			Update(1, 0, n, id[v[i]+1], n, 1);
		else if (t[i] == 2)
			Update(1, 0, n, 0, id[v[i]-1], 1);
		else if (t[i] == 3)
			Update(1, 0, n, id[v[i]], id[v[i]], 1);
		else
			Update(1, 0, n, 0, id[v[i]-1], 1), Update(1, 0, n, id[v[i]+1], n, 1);
	}
	int x, maxi = 0;
	for (int i = 0; i < n; i++)
	{
		int q = Query(1, 0, n, i);
//		printf("%d %lld\n", q, num[i]);
		if (q > maxi)
		{
			maxi = q;
			x = i;
		}
	}
	printf("%d %lld\n", maxi, num[x]);
	return 0;
}
