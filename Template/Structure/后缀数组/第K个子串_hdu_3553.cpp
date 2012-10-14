#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 100000+5;
int T;
int sa[MAXN], height[MAXN], rank[MAXN], tmp[MAXN], top[MAXN];
int Tr[MAXN<<2];
long long K, sumlen[MAXN];
char S[MAXN];
namespace SuffixArray
{
	void makesa(char *s, int n)
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
	void lcp(char *s, int n)
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
namespace SegTr
{
	void Build(int idx, int L, int R)
	{
		if (L == R)
		{
			Tr[idx] = R;
			return;
		}
		int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
		Build(left, L, mid);
		Build(right, mid+1, R);
		Tr[idx] = (height[Tr[left]] <= height[Tr[right]] ? Tr[left] : Tr[right]);
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
		if (ql && !qr)
			return ql;
		else if (!ql && qr)
			return qr;
		else
			return (height[ql] <= height[qr] ? ql : qr);
	}
}
void solve(int len, int &rk, int &rl)
{
	int h = 0;
	long long a = 1, b = len;
	while (a < b)
	{
		int q = SegTr::Query(1, 1, len, a+1, b);
		if (K <= (height[q]-h)*(b-a+1))
		{
			rk = a; rl = h+1+(K-1)/(b-a+1);
			return;
		}
		K -= (height[q]-h)*(b-a+1);
		if (K <= sumlen[q-1]-sumlen[a-1]-height[q]*(q-a))
		{
			b = q-1; h = height[q];
			continue;
		}
		K -= sumlen[q-1]-sumlen[a-1]-height[q]*(q-a);
		a = q;
		h = height[q];
	}
	rk = a; rl = h+K;
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%s%I64d", S, &K);
		int len = strlen(S);
		SuffixArray::makesa(S, len+1);
		SuffixArray::lcp(S, len+1);
		for (int i = 1; i <= len; i++)
			sumlen[i] = sumlen[i-1]+len-sa[i];
		SegTr::Build(1, 1, len);
		int rk, rl;
		solve(len, rk, rl);
		printf("Case %d: ", cas);
		for (int i = 0; i < rl; i++)
			printf("%c", S[sa[rk]+i]);
		printf("\n");
	}
	return 0;
}
