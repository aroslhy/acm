// UESTC_DaPangZi	UESTC 1709	Accepted	1068 KB	666 ms	G++	1036 B	2013-07-22 15:08:33
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5;
int T, N, a[MAXN], cnt[3][32];
long long pow2[32];
int main()
{
	freopen("put.in", "r", stdin);
	pow2[0] = 1;
	for (int i = 1; i <= 30; i++)
		pow2[i] = pow2[i-1]<<1;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &N);
		long long sum[3] = {}, ans[3] = {};
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			for (int j = 0; j < 30; j++)
			{
				if (a[i]&(1<<j))
				{
					cnt[0][j]++;
					sum[1] += (i-1-cnt[1][j])*pow2[j];
					cnt[1][j] = i;
					sum[2] += (i-1-cnt[2][j]*2)*pow2[j];
					cnt[2][j] = i-cnt[2][j];
				}
				else
				{
					sum[0] -= cnt[0][j]*pow2[j];
					cnt[0][j] = 0;
				}
			}
			for (int k = 0; k < 3; k++)
			{
				sum[k] += a[i];
				ans[k] += sum[k];
			}
//			printf("%d ", sum[0]);
		}
		printf("Case #%d: %.6lf %.6lf %.6lf\n", cas, (double)ans[0]*2/((long long)N*(N+1)), (double)ans[1]*2/((long long)N*(N+1)), (double)ans[2]*2/((long long)N*(N+1)));
	}
	return 0;
}
