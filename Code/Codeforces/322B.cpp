// Jun 28, 2013 8:30:59 PM	bigoceanlhy	 322B - Ciel and Flowers	 GNU C++	Accepted	 15 ms	 100 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 30+5;
int x[3], d[MAXN][MAXN][MAXN];
int main()
{
	int n = 30;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
			{
				int &dp = d[i][j][k];
				if (i >= 1 && j >= 1 && k >= 1)
					dp = d[i-1][j-1][k-1]+1;
				if (i >= 3)
					dp = max(dp, d[i-3][j][k]+1);
				if (j >= 3)
					dp = max(dp, d[i][j-3][k]+1);
				if (k >= 3)
					dp = max(dp, d[i][j][k-3]+1);
			}
	scanf("%d%d%d", &x[0], &x[1], &x[2]);
	sort(x, x+3);
	int sum = 0;
	if (x[0] > 9)
	{
		sum += x[0]/9*3;
		x[0] %= 9;
	}
	if (x[1]-x[0] > 9)
	{
		sum += (x[1]-x[0])/9*3;
		x[1] = x[0]+(x[1]-x[0])%9;
	}
	if (x[2]-x[1] > 9)
	{
		sum += (x[2]-x[1])/9*3;
		x[2] = x[1]+(x[2]-x[1])%9;
	}
	sum += d[x[0]][x[1]][x[2]];
	printf("%d\n", sum);
	return 0;
}
