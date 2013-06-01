#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N;
long long P;
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%lld", &N, &P);
		long long n = 1LL<<N;
		if (P == n)
			printf("Case #%d: %lld %lld\n", cas, (1LL<<N)-1, (1LL<<N)-1);
		else
		{
			long long mini = 0, maxi = 0;
			for (int i = 1; i <= N; i++)
			{
				mini <<= 1, maxi <<= 1;
				if (n-P < 1LL<<i)
					mini ^= 1;
				if (P >= 1LL<<i)
					maxi ^= 1;
			}
			printf("Case #%d: %lld %lld\n", cas, mini-1, maxi);
		}
	}
	return 0;
}
