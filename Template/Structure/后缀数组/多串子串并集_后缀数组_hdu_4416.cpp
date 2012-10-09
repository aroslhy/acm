#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300000+5, MAXM = 100000+5;
int T, N, L[MAXM];
int len, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
int *s, a[MAXN];
char A[MAXM];
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
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%s", &N, A);
		len = 0;
		for (L[0] = 0; A[L[0]]; L[0]++)
			a[len++] = A[L[0]]-'a'+1;
		for (int i = 1; i <= N; i++)
		{
			a[len++] = 26+i;
			scanf("%s", A);
			for (L[i] = 0; A[L[i]]; L[i]++)
				a[len++] = A[L[i]]-'a'+1;
		}
		a[len++] = 0;
		long long sumAB = 0, sumB = 0;
		s = a;
		makesa(); lcp();
		for (int i = 1; i < len; i++)
			sumAB += len-1-sa[i]-height[i];
		long long l = len-1;
		for (int i = 0; i < N; i++)
		{
			l -= L[i];
			sumAB -= (L[i]+1)*l;
			l--;
		}
		s = a+L[0]+1; len -= L[0]+1;
		makesa(); lcp();
		for (int i = 1; i < len; i++)
			sumB += len-1-sa[i]-height[i];
		l = len-1;
		for (int i = 1; i < N; i++)
		{
			l -= L[i];
			sumB -= (L[i]+1)*l;
			l--;
		}
		printf("Case %d: %I64d\n", cas, sumAB-sumB);
	}
	return 0;
}
