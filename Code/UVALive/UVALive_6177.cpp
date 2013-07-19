// 6177	The King's Ups and Downs	Accepted	C++	0.009	2013-07-19 09:06:48
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20+5;
int P, D, N;
unsigned long long d[MAXN][MAXN][2], ans[MAXN];
int main()
{
	d[1][1][0] = d[1][1][1] = 1;
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= i; j++)
		{
			for (int k = j+1; k <= i+1; k++)
				d[i+1][k][1] += d[i][j][0];
			for (int k = 1; k <= j; k++)
				d[i+1][k][0] += d[i][j][1];
		}
	ans[1] = 1;
	for (int i = 2; i <= 20; i++)
		for (int j = 1; j <= i; j++)
			ans[i] += d[i][j][0]+d[i][j][1];
	scanf("%d", &P);
	while (P--)
	{
		scanf("%d%d", &D, &N);
		printf("%d %llu\n", D, ans[N]);
	}
	return 0;
}
