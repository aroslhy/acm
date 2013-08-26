// 2013-08-22 20:41:25	Accepted	4689	0MS	204K	714 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20+5;
long long d[2][MAXN];
char str[MAXN];
int main()
{
	while (scanf("%s", str+1) != EOF)
	{
		int cnt = 0, s = 0, t = 1;
		memset(d[t], 0, sizeof(d[t]));
		d[t][1] = 1;
		for (int i = 1; str[i+1]; i++)
		{
			swap(s, t);
			memset(d[t], 0, sizeof(d[t]));
			if (str[i] == '+')
				cnt++;
			for (int j = 0; j <= cnt; j++)
			{
				if (str[i+1] == '+')
				{
					d[t][j+1] += d[s][j]*(1+cnt-j);
					d[t][j] += d[s][j]*j;
				}
				else
				{
					if (j)
						d[t][j-1] += d[s][j]*j;
					d[t][j] += d[s][j]*(cnt-j);
				}
			}
		}
		printf("%I64d\n", d[t][0]);
	}
	return 0;
}
