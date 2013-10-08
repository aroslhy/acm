// 2013-09-17 14:11:31	Accepted	4747	1828MS	16516K	2133 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 200000+5;
int N, a[MAXN], mex1[MAXN], next[MAXN];
int Tmin[MAXN<<2], Tmax[MAXN<<2];
long long Tsum[MAXN<<2], mark[MAXN<<2];
void PushUp(int idx)
{
	int left = idx<<1, right = idx<<1|1;
	Tsum[idx] = Tsum[left]+Tsum[right];
	Tmin[idx] = min(Tmin[left], Tmin[right]);
	Tmax[idx] = max(Tmax[left], Tmax[right]);
	mark[idx] = -1;
}
void Build(int idx, int L, int R)
{
	if (L == R)
	{
		Tsum[idx] = Tmin[idx] = Tmax[idx] = mex1[R];
		mark[idx] = -1;
		return;
	}
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Build(left, L, mid);
	Build(right, mid+1, R);
	PushUp(idx);
}
void PushDown(int idx, int L, int R)
{
	if (mark[idx] == -1)
		return;
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	Tsum[left] = mark[idx]*(mid-L+1);
	Tmin[left] = Tmax[left] = mark[left] = mark[idx];
	Tsum[right] = mark[idx]*(R-mid);
	Tmin[right] = Tmax[right] = mark[right] = mark[idx];
}
void Update(int idx, int L, int R, int l, int r, long long c)
{
	if (l <= L && R <= r)
	{
		if (Tmax[idx] <= c)
			return;
		else if (c <= Tmin[idx])
		{
			Tsum[idx] = c*(R-L+1);
			Tmin[idx] = Tmax[idx] = mark[idx] = c;
			return;
		}
	}
	PushDown(idx, L, R);
	int left = idx<<1, right = idx<<1|1, mid = (L+R)>>1;
	if (l <= mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, c);
	PushUp(idx);
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		map<int, int> mp;
		int mini = 0;
		fill(next+1, next+1+N, 0);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			map<int, int>::iterator it = mp.find(a[i]);
			if (it != mp.end())
			{
				next[it->second] = i;
				it->second = i;
			}
			else
				mp.insert(make_pair(a[i], i));
			while (mp.find(mini) != mp.end())
				mini++;
			mex1[i] = mini;
		}
		Build(1, 1, N);
		long long ans = 0;
		for (int i = 1; i <= N; i++)
		{
			ans += Tsum[1];
			if (!next[i])
				next[i] = N+1;
			Update(1, 1, N, 1, next[i]-1, a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
