#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 10000000;
const int MAXN = MAX+5;
int N, M, a, A, B;
int vis[MAXN], cnt[MAXN];
long long sum[MAXN];

bool is[MAXN]; int prm[MAXN];
int getprm(int n)
{
	int i, j, k = 0;
	int s, e = (int)(sqrt(0.0+n)+1);
	memset(is, 1, sizeof(is));
	prm[k++] = 2; is[0] = is[1] = 0;
	for (i = 4; i < n; i += 2) is[i] = 0;
	for (i = 3; i < e; i += 2) if (is[i]) {
		prm[k++] = i;
		for (s = i*2, j = i*i; j < n; j += s)
			is[j] = 0;
	}
	for (; i < n; i += 2) if (is[i]) prm[k++] = i;
	return k;
}

int main()
{
	getprm(MAXN);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		if (a > MAX)
		{
			printf("aros\n");
			return 0;
		}
		vis[a]++;
	}
	for (int i = 2; i <= MAX; i++)
	{
		if (is[i])
		{
			for (int j = i; j <= MAX; j += i)
				cnt[i] += vis[j];
		}
		sum[i] = sum[i-1]+cnt[i];
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &A, &B);
		if (A > MAX)
			printf("0\n");
		else
			printf("%I64d\n", sum[min(B, MAX)]-sum[A-1]);
	}
	return 0;
}
