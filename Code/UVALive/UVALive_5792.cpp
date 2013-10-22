// 5792	Diccionário Portuñol	Accepted	C++	0.032	2013-10-21 13:52:53
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 100000+5;
int N[2], vis[2], cnt[2][26], nv[2], chd[2][MAXM][26];
char s[MAXN];
void Insert(int t, char *str)
{
	int u = 0;
	for (int i = 0; str[i]; i++)
	{
		int id = str[i]-'a';
		if (!chd[t][u][id])
		{
			int v = nv[t]++;
			memset(chd[t][v], 0, sizeof(chd[t][v]));
			chd[t][u][id] = v;
			vis[t]++;
			if (u)
				cnt[t][id]++;
		}
		u = chd[t][u][id];
	}
}
int main()
{
	while (scanf("%d%d", &N[0], &N[1]))
	{
		if (!N[0] && !N[1])
			break;
		for (int t = 0; t < 2; t++)
		{
			nv[t] = 1;
			memset(chd[t][0], 0, sizeof(chd[t][0]));
			vis[t] = 0;
			memset(cnt[t], 0, sizeof(cnt[t]));
			for (int i = 0; i < N[t]; i++)
			{
				scanf("%s", s);
				if (t)
					reverse(s, s+strlen(s));
				Insert(t, s);
			}
		}
		long long ans = (long long)vis[0]*vis[1];
		for (int i = 0; i < 26; i++)
			ans -= (long long)cnt[0][i]*cnt[1][i];
		printf("%lld\n", ans);
	}
	return 0;
}
