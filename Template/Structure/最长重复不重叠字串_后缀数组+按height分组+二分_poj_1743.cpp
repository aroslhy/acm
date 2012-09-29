#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000+5;
const int INF = 0x3f3f3f3f;
int N, a[MAXN], s[MAXN];
int n, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
namespace SuffixArray
{
	void makesa()
	{
		int lena = n < 256 ? 256 : n;
		memset(top, 0, lena*sizeof(int));
		for (int i = 0; i < n; i++)
			top[rank[i] = s[i]&(-1)]++;
		for (int i = 1; i < lena; i++)
			top[i] += top[i-1];
		for (int i = 0; i < n ; i++)
			sa[--top[rank[i]]] = i;
		for (int k = 1; k < n; k <<= 1)
		{
			for (int i = 0; i < n; i++)
			{
				int j = sa[i]-k;
				if (j < 0)
					j += n;
				tmp[top[rank[j]]++] = j;
			}
			int j = sa[tmp[0]] = top[0] = 0;
			for (int i = 1; i < n; i++)
			{
				if (rank[tmp[i]] != rank[tmp[i-1]] || rank[tmp[i]+k] != rank[tmp[i-1]+k])
					top[++j] = i;
				sa[tmp[i]] = j;
			}
			memcpy(rank, sa , n*sizeof(int));
			memcpy(sa , tmp, n*sizeof(int));
			if (j+1 >= n)
				break;
		}
	}
	void lcp()
	{
		height[0] = 0;
		for (int i = 0, k = 0, j = rank[0]; i+1 < n; i++, k++)
			while (k >= 0 && s[i] != s[sa[j-1]+k])
			{
				height[j] = k--;
				j = rank[sa[j]+1];
			}
	}
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		n = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
			if (i)
				s[n++] = a[i]-a[i-1]+88;
		}
		s[n++] = 0;
		SuffixArray::makesa();
		SuffixArray::lcp();
		int l = 4, r = max(l+1, N/2), ans = -1;
		while (l < r)
		{
			int mid = (l+r)>>1, t = 0, mini = sa[0], maxi = sa[0];
			for (int i = 1; i < n; i++)
			{
				if (height[i] >= mid)
				{
					mini = min(mini, sa[i]);
					maxi = max(maxi, sa[i]);
				}
				else
				{
					t = max(t, maxi-mini);
					mini = maxi = sa[i];
				}
			}
			t = max(t, maxi-mini);
			if (t > mid)
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid;
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
