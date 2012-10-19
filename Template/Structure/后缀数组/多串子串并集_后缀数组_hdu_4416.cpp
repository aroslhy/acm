/*
求多串的子串并集元素的个数，先用没出现过的不同的字符把多个串拼接，用后缀数组求这个串的不同子串的个数，再减去含有拼接字符的子串的个数。用上述方法求『A、B1、……、BN』中不同子串的个数sumAB和『B1、……、BN』中不同子串的个数sumB，答案就是sumAB-sumB。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300000+5, MAXM = 100000+5;
int T, N, L[MAXM];
int len, sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
int a[MAXN];
char A[MAXM];
void makesa(int *s, int n)
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
void lcp(int *s, int n)
{
	height[0] = 0;
	for (int i = 0, k = 0, j = rank[0]; i+1 < n; i++, k++)
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
		a[len] = 0;
		long long sumAB = 0, sumB = 0;
		makesa(a, len+1);
		lcp(a, len+1);
		for (int i = 1; i <= len; i++)
			sumAB += len-sa[i]-height[i];
		long long l = len;
		for (int i = 0; i < N; i++)
		{
			l -= L[i];
			sumAB -= (L[i]+1)*l;
			l--;
		}
		len -= L[0]+1;
		makesa(a+L[0]+1, len+1);
		lcp(a+L[0]+1, len+1);
		for (int i = 1; i <= len; i++)
			sumB += len-sa[i]-height[i];
		l = len;
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
