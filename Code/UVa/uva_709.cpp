//709 	Formatting Text 	Accepted 	C++ 	0.020 	2012-12-19 03:06:24
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 80+5, MAXM = 10000+5;
const int INF = 0x3f3f3f3f;
int N, len[MAXM], d[MAXM][MAXN], p[MAXM][MAXN];
char word[MAXM][MAXN], line[MAXM];
int main()
{
	while (scanf("%d", &N) && N)
	{
		gets(line);
		int n = 0;
		while (gets(line))
		{
			if (!line[0])
				break;
			for (int p = 0; line[p]; )
			{
				sscanf(line+p, "%s", word[++n]);
				len[n] = strlen(word[n]);
				p += len[n];
				while (line[p] == ' ')
					p++;
			}
		}
		len[n+1] = INF;
		fill(d[n+1]+1, d[n+1]+1+N, INF);
		d[n+1][1] = 0;
		for (int i = n; i >= 1; i--)
		{
			fill(d[i]+1, d[i]+1+N, INF);
			if (d[i+1][1]+(len[i] < N ? 500 : 0) < d[i][1])
			{
				d[i][1] = d[i+1][1]+(len[i] < N ? 500 : 0);
				p[i][1] = 1;
			}
			if (d[i+1][1] < d[i][N-len[i]+1])
			{
				d[i][N-len[i]+1] = d[i+1][1];
				p[i][N-len[i]+1] = 1;
			}
			for (int j = 1; j-1+len[i] <= N; j++)
				for (int k = j+len[i]+1; k-1+len[i+1] <= N; k++)
					if (d[i+1][k]+(k-j-len[i]-1)*(k-j-len[i]-1) < d[i][j])
					{
						d[i][j] = d[i+1][k]+(k-j-len[i]-1)*(k-j-len[i]-1);
						p[i][j] = k;
					}
		}
		for (int i = 1, j = 1; i <= n; i++)
		{
			printf("%s", word[i]);
			if (p[i][j] > 1)
			{
				int x = sqrt(d[i][j]-d[i+1][p[i][j]]);
				for (int k = 0; k <= x; k++)
					printf(" ");
			}
			else
				printf("\n");
			j = p[i][j];
		}
		printf("\n");
	}
	return 0;
}
