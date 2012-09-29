//18:59:39	29 Sep 2012	aroslhy	1297. Palindrome	C++	Accepted	0.015	176 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000+5;
const int INF = 0x3f3f3f3f;
int Tr[MAXN<<2];
int n, sa[MAXN], height[MAXN], RANK[MAXN], tmp[MAXN], top[MAXN];
char s[MAXN];
namespace SuffixArray
{
	void makesa()
	{
		int na = n < 256 ? 256 : n;
		memset(top, 0, na*sizeof(int));
		for (int i = 0; i < n; i++)
			top[RANK[i] = s[i]&(-1)]++;
		for (int i = 1; i < na; i++)
			top[i] += top[i-1];
		for (int i = 0; i < n ; i++)
			sa[--top[RANK[i]]] = i;
		for (int k = 1; k < n; k <<= 1)
		{
			for (int i = 0; i < n; i++)
			{
				int j = sa[i]-k;
				if (j < 0)
					j += n;
				tmp[top[RANK[j]]++] = j;
			}
			int j = sa[tmp[0]] = top[0] = 0;
			for (int i = 1; i < n; i++)
			{
				if (RANK[tmp[i]] != RANK[tmp[i-1]] || RANK[tmp[i]+k] != RANK[tmp[i-1]+k])
					top[++j] = i;
				sa[tmp[i]] = j;
			}
			memcpy(RANK, sa , n*sizeof(int));
			memcpy(sa , tmp, n*sizeof(int));
			if (j+1 >= n)
				break;
		}
	}
	void lcp()
	{
		height[0] = 0;
		for (int i = 0, k = 0, j = RANK[0]; i+1 < n; i++, k++)
			while (k >= 0 && s[i] != s[sa[j-1]+k])
			{
				height[j] = k--;
				j = RANK[sa[j]+1];
			}
	}
}
namespace SegTr
{
	void Build(int idx, int L, int R)
	{
		if (L == R)
		{
			Tr[idx] = height[R];
			return;
		}
		int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
		Build(left, L, mid);
		Build(right, mid+1, R);
		Tr[idx] = min(Tr[left], Tr[right]);
	}
	int Query(int idx, int L, int R, int l, int r)
	{
		if (l <= L && R <= r)
			return Tr[idx];
		int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
		int q = INF;
		if (l <= mid)
			q = min(q, Query(left, L, mid, l, r));
		if (mid < r)
			q = min(q, Query(right, mid+1, R, l, r));
		return q;
	}
}
int main()
{
	scanf("%s", s);
	int len = n = strlen(s);
	s[n++] = '$';
	for (int i = n-2; i >= 0; i--)
		s[n++] = s[i];
	s[n++] = 0;
	SuffixArray::makesa();
	SuffixArray::lcp();
	SegTr::Build(1, 1, n-1);
	int pos, maxi = 0;
	for (int i = 0; i < len; i++)
		for (int k = 0; k <= 1; k++)
		{
			int r = SegTr::Query(1, 1, n-1, min(RANK[i], RANK[n-i-1-k])+1, max(RANK[i], RANK[n-i-1-k]));
			if (r*2-k > maxi)
			{
				maxi = r*2-k;
				pos = i-r+k;
			}
		}
	for (int i = 0; i < maxi; i++)
		printf("%c", s[pos+i]);
	printf("\n");
	return 0;
}
