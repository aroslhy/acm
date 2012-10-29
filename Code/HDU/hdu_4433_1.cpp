//2012-10-29 21:07:58	Accepted	4433	375MS	596K	1465 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1004+5;
const int MAX = 10;
const int INF = 0x3f3f3f3f;
int d[MAXN][MAX][MAX];
char cur[MAXN], pas[MAXN];
inline int id(char x)
{
	return x-'0';
}
inline int up(int x, int y)
{
	return (x+y)%MAX;
}
inline int down(int x, int y)
{
	return (x-y+MAX)%MAX;
}
int main()
{
	while (scanf("%s%s", cur+1, pas+1) != EOF)
	{
		int n = strlen(pas+1);
		strcpy(cur+1+n, "00");
		for (int i = 0; i <= n; i++)
			memset(d[i], 0x3f, sizeof(d[i]));
		for (int i = 0; i < MAX/2; i++)
			for (int j = 0; j <= i; j++)
			{
				d[0][up(id(cur[1]), i)][up(id(cur[2]), j)] = min(d[0][up(id(cur[1]), i)][up(id(cur[2]), j)], i);
				d[0][down(id(cur[1]), i)][down(id(cur[2]), j)] = min(d[0][down(id(cur[1]), i)][down(id(cur[2]), j)], i);
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < MAX; j++)
				for (int k = 0; k < MAX; k++) if (d[i][j][k] < INF)
				{
					int p = (id(pas[i+1])-j+MAX)%MAX, q = (j-id(pas[i+1])+MAX)%MAX;
					for (int a = 0; a <= p; a++)
						for (int b = 0; b <= a; b++)
							d[i+1][up(k, a)][up(id(cur[i+3]), b)] = min(d[i+1][up(k, a)][up(id(cur[i+3]), b)], d[i][j][k]+p);
					for (int a = 0; a <= q; a++)
						for (int b = 0; b <= a; b++)
							d[i+1][down(k, a)][down(id(cur[i+3]), b)] = min(d[i+1][down(k, a)][down(id(cur[i+3]), b)], d[i][j][k]+q);
				}
		printf("%d\n", d[n][0][0]);
	}
	return 0;
}
