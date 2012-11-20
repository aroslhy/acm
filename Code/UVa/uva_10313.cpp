//10313 	Pay the Price 	Accepted 	C++ 	0.056 	2012-11-20 11:23:14
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300+5;
const int MAX = 300;
int N, L1, L2;
long long d[MAXN][MAXN], f[MAXN][MAXN];
char line[100];
int main()
{
	d[0][0] = f[0][0] = 1;
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= i; j++)
		{
			d[i][j] = f[i-j][min(j, i-j)];
			f[i][j] = f[i][j-1]+d[i][j];
		}
	while (gets(line))
	{
		int n = sscanf(line, "%d%d%d", &N, &L1, &L2);
		if (n > 0)
		{
			if (n == 1)
				printf("%lld\n", f[N][N]);
			else if (n == 2)
				printf("%lld\n", f[N][min(L1, N)]);
			else if (L1 > N)
				printf("0\n");
			else if (L1 > 0)
				printf("%lld\n", f[N][min(L2, N)]-f[N][L1-1]);
			else
				printf("%lld\n", f[N][min(L2, N)]);
		}
	}
	return 0;
}
