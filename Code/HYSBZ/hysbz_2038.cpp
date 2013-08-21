// bigoceanlhy	2038	Accepted	2772 kb	556 ms	C++/Edit	1477 B	2013-08-21 20:17:25
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5;
int N, M, C[MAXN], A[MAXN], B[MAXN];
int par[MAXN], r[MAXN], sum[MAXN], Q[MAXN], com[MAXN][3];
bool cmp(const int &a, const int &b)
{
	if (par[a] != par[b])
		return par[a] < par[b];
	else
		return B[a] < B[b];
}
int gcd(int a, int b)
{
	while (b)
	{
		int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}
int main()
{
	scanf("%d%d", &N, &M);
	int n = sqrt(N)+1;
	com[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &C[i]);
		sum[i] = 0;
		com[i][0] = 1;
		for (int j = 1; j <= 2 && j <= i; j++)
			com[i][j] = com[i-1][j-1]+com[i-1][j];
	}
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &A[i], &B[i]);
		par[i] = A[i]/n;
		r[i] = i;
	}
	sort(r+1, r+1+M, cmp);
	int L = 1, R = 1, q = 0;
	sum[C[1]]++;
	for (int i = 1; i <= M; i++)
	{
		while (A[r[i]] < L)
			q += sum[C[--L]]++;
		while (R < B[r[i]])
			q += sum[C[++R]]++;
		while (L < A[r[i]])
			q -= --sum[C[L++]];
		while (B[r[i]] < R)
			q -= --sum[C[R--]];
		Q[r[i]] = q;
	}
	for (int i = 1; i <= M; i++)
	{
		if (Q[i])
		{
			int g = gcd(Q[i], com[B[i]-A[i]+1][2]);
			printf("%d/%d\n", Q[i]/g, com[B[i]-A[i]+1][2]/g);
		}
		else
			printf("0/1\n");
	}
	return 0;
}
