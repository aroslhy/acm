//bigoceanlhy	3261	Accepted	860K	32MS	G++	1811B	2012-09-29 11:09:11
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000+5;
const int INF = 0x3f3f3f3f;
int N, K, qua, s[MAXN];
int len, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
namespace SuffixArray
{
	void makesa()
	{
		int lena = len < 256 ? 256 : len;
		memset(top, 0, lena*sizeof(int));
		for (int i = 0; i < len; i++)
			top[rank[i] = s[i]&(-1)]++;
		for (int i = 1; i < lena; i++)
			top[i] += top[i-1];
		for (int i = 0; i < len ; i++)
			sa[--top[rank[i]]] = i;
		for (int k = 1; k < len; k <<= 1)
		{
			for (int i = 0; i < len; i++)
			{
				int j = sa[i]-k;
				if (j < 0)
					j += len;
				tmp[top[rank[j]]++] = j;
			}
			int j = sa[tmp[0]] = top[0] = 0;
			for (int i = 1; i < len; i++)
			{
				if (rank[tmp[i]] != rank[tmp[i-1]] || rank[tmp[i]+k] != rank[tmp[i-1]+k])
					top[++j] = i;
				sa[tmp[i]] = j;
			}
			memcpy(rank, sa , len*sizeof(int));
			memcpy(sa , tmp, len*sizeof(int));
			if (j+1 >= len)
				break;
		}
	}
	void lcp()
	{
		height[0] = 0;
		for (int i = 0, k = 0, j = rank[0]; i+1 < len; i++, k++)
			while (k >= 0 && s[i] != s[sa[j-1]+k])
			{
				height[j] = k--;
				j = rank[sa[j]+1];
			}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	len = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &qua);
		s[len++] = qua+1;
	}
	s[len++] = 0;
	SuffixArray::makesa();
	SuffixArray::lcp();
	int l = 0, r = N, ans = 0;
	while (l < r)
	{
		int mid = (l+r)>>1, maxi = 0, cnt = 1;
		for (int i = 1; i < len; i++)
		{
			if (height[i] >= mid)
				cnt++;
			else
			{
				maxi = max(maxi, cnt);
				cnt = 1;
			}
		}
		maxi = max(maxi, cnt);
		if (maxi >= K)
		{
			ans = mid;
			l = mid+1;
		}
		else
			r = mid;
	}
	printf("%d\n", ans);
	return 0;
}
