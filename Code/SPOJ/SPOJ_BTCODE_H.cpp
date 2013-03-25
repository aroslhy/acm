// aroslhy	SPOJ BTCODE_H	Accepted	4096 KB	70 ms	C++ (g++ 4.0.0-8)	733 B	2013-03-25 18:31:17
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 300+5, MAXT = 25+5;
int T, N[MAXT], L[MAXT];
double c[MAXN][MAXN], d[MAXN][MAXN];
using namespace std;
int main()
{
	scanf("%d", &T);
	int maxn = 0, maxl = 0;
	for (int i = 1; i <= T; i++)
	{
		scanf("%d%d", &N[i], &L[i]);
		maxn = max(maxn, N[i]);
		maxl = max(maxl, L[i]);
	}
	c[0][0] = 1;
	for (int i = 1; i <= maxn; i++)
	{
		c[i][0] = c[i-1][0]/2;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])/2;
		d[i][0] = 1;
		for (int j = 1; j <= maxl; j++)
		{
			d[i][j] = 0;
			for (int k = 0; k <= i; k++)
				d[i][j] += (1+d[k][j-1]+d[i-k][j-1])*c[i][k];
		}
	}
	for (int i = 1; i <= T; i++)
		printf("%.2lf\n", d[N[i]][L[i]]);
	return 0;
}
