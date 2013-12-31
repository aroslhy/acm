#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 4000+5, MAXM = 36000+5;
int N, A, sum[MAXN], num[MAXM];
char s[MAXN];
int main()
{
	scanf("%d%s", &A, s+1);
	N = strlen(s+1);
	for (int i = 1; i <= N; i++)
	{
		sum[i] = sum[i-1]+s[i]-'0';
		for (int j = 1; j <= i; j++)
			num[sum[i]-sum[j-1]]++;
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
		{
			int x = sum[j]-sum[i-1];
			if (x)
			{
				if (!(A%x))
					if (A/x <= N*9)
						ans += num[A/x];
			}
			else if (!A)
				ans += N*(N+1)/2;
		}
	printf("%I64d\n", ans);
	return 0;
}

