// 2013-03-31 21:50:05	Accepted	4535	0MS	288K	670 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100, MAXN = MAX+5;
const long long MOD = 1000000007;
int T, N;
long long d[MAXN], F[MAXN], C[MAXN][MAXN];
int main()
{
	for (int i = 0; i <= MAX; i++)
		C[i][0] = 1;
	F[0] = 1;
	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
		F[i] = (F[i-1]*i)%MOD;
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		long long ans = 0, flag = -1;
		for (int i = 2; i <= N; i++)
		{
			flag = -flag;
			ans = (ans+flag*C[N][i]*F[N-i])%MOD;
		}
		printf("%lld\n", (ans+MOD)%MOD);
	}
	return 0;
}
