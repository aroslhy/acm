// aroslhy	URAL 1918	Accepted	349 KB	1390 ms	G++ 4.7.2	531 B	2013-05-09 10:06:23
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5000+5;
const long long MOD = 1000000007;
int N;
long long d[2][MAXN], sum[2][MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		d[1][i] = 1;
		sum[1][i] = i;
	}
	int s = 0, t = 1;
	for (int i = 2; i <= N; i++)
	{
		swap(s, t);
		for (int j = 1; j <= N; j++)
		{
			d[t][j] = ((d[s][j]*j+sum[s][j-1]-sum[s][i-1])%MOD+MOD)%MOD;
			sum[t][j] = (sum[t][j-1]+d[t][j])%MOD;
		}
	}
	printf("%lld\n", d[t][N]);
	return 0;
}
