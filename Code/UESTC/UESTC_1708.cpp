// UESTC_DaPangZi	UESTC 1708	Accepted	876 KB	0 ms	G++	681 B	2013-07-22 12:51:26
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10+5;
int T, a[MAXN], b[MAXN];
char line[100];
int main()
{
	freopen("put.in", "r", stdin);
	scanf("%d", &T);
	gets(line);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d:\n", cas);
		gets(line);
		int n = sscanf(line, "%d%d%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
		sort(a, a+n);
		memset(b, 0, sizeof(b));
		do
		{
			if (memcmp(a, b, sizeof(a)))
			{
				for (int i = 0; i < n; i++)
				{
					if (i)
						printf(" ");
					printf("%d", a[i]);
				}
				printf("\n");
			}
			memcpy(b, a, sizeof(a));
		}
		while (next_permutation(a, a+n));
	}
	return 0;
}
