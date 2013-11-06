// Oct 29, 2013 5:01:45 PM	bigoceanlhy	 329A - Purification	 GNU C++	Accepted	 15 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
int N;
char mat[MAXN][MAXN];
bool r[MAXN], c[MAXN];
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		memset(r, 1, sizeof(r));
		memset(c, 1, sizeof(c));
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", mat[i]+1);
			for (int j = 1; j <= N; j++) if (mat[i][j] == '.')
				r[i] = c[j] = 0;
		}
		bool flag = 1;
		for (int i = 1; i <= N && flag; i++)
			for (int j = 1; j <= N && flag; j++) if (r[i] && c[j])
				flag = 0;
		if (flag)
		{
			bool flag2 = 1;
			for (int i = 1; i <= N && flag2; i++) if (r[i])
				flag2 = 0;
			if (flag2)
			{
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++) if (mat[i][j] == '.')
					{
						printf("%d %d\n", i, j);
						break;
					}
			}
			else
			{
				for (int j = 1; j <= N; j++)
					for (int i = 1; i <= N; i++) if (mat[i][j] == '.')
					{
						printf("%d %d\n", i, j);
						break;
					}
			}
		}
		else
			printf("-1\n");
	}
	return 0;
}
