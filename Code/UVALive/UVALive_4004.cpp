// 4004	Space Beacon	Accepted	C++	0.009	2013-03-27 10:52:06
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXN = 18+5;
int T, a[MAXN];
long long d[10][MAXN][2];
char s[1<<10];
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		d[i][1][0] = d[i][1][1] = 1;
		d[i][2][0] = 9-i;
		d[i][2][1] = i-1;
	}
	for (int j = 3; j <= 18; j++)
		for (int i = 1; i <= 9; i++)
		{
			for (int k = i+1; k <= 9; k++)
				d[i][j][0] += d[k][j-1][1];
			for (int k = 1; k < i; k++)
				d[i][j][1] += d[k][j-1][0];
		}
	scanf("%d",&T); gets(s);
	while (T--)
	{
		gets(s);
		int n = 0;
		for (int i = 0; s[i]; i++) if (isdigit(s[i]))
			a[n++] = s[i]-'0';
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < a[i]; j++)
				for (int k = max(3-i, 1); k <= 18-i; k++)
				{
					if (!i)
						ans += d[j][k][0]+d[j][k][1];
					else if ((i == 1 && j != a[i-1]) || (i > 1 && ((a[i-2] > a[i-1] && a[i-1] < j) || (a[i-2] < a[i-1] && a[i-1] > j))))
						ans += d[j][k][a[i-1] > j ? 0 : 1];
				}
			if (i >= 3)
				ans++;
		}
		printf("%lld\n", ++ans);
	}
	return 0;
}
