// 1491	Accepted	92ms	6000kb	G++	835B	2013-03-24 16:44:49	bigoceanlhy
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000000+5;
int T, fail[MAXN];
char s[MAXN], t[MAXN];
void get_fail(char *pat)
{
	fail[0] = -1;
	for (int i = 1, j = -1; pat[i]; i++)
	{
		while (j != -1 && pat[j+1] != pat[i])
			j = fail[j];
		if (pat[j+1] == pat[i])
			j++;
		fail[i] = j;
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", s, t);
		int n = strlen(s);
		s[n++] = '$';
		s[n++] = 0;
		get_fail(t);
		int ans = 0, l = 0, len = strlen(t);
		for (int i = 0, j = 0; s[i]; )
		{
			if (s[i] == t[j])
				i++, j++, l++;
			else if (!j)
				i++;
			else
			{
				if (j == len)
					ans = max(ans, l);
				if (!(j == len && fail[j-1]+1))
					l = 0;
				j = fail[j-1]+1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
