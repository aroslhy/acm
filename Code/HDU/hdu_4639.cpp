// 2013-08-01 18:23:10	Accepted	4639	0MS	228K	671 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10086+5;
const int MOD = 10007;
int T, d[MAXN];
char s[MAXN];
int main()
{
	d[0] = d[1] = 1;
	for (int i = 2; i <= 10086>>1; i++)
		d[i] = (d[i-1]+d[i-2])%MOD;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%s", s);
		int cnt = 0, ans = 1;
		for (int i = 0; s[i]; i++)
		{
			if ((cnt%2 && s[i] == 'e') || (!(cnt%2) && s[i] == 'h'))
				cnt++;
			else
			{
				ans  = (ans*d[cnt/2])%MOD;
				cnt = 0;
				if (s[i] == 'h')
					cnt++;
			}
		}
		ans = (ans*d[cnt/2])%MOD;
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}
