//2012-10-04 19:53:56	Accepted	4333	140MS	2060K	1735 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int T;
int extend[MAXM], next[MAXN], fail[MAXN];
char a[MAXN], aa[MAXM];
void get_next(char *pat)
{
	next[0] = strlen(pat);
	int k = 0;
	while (pat[k+1] && pat[k] == pat[k+1])
		k++;
    next[1] = k;
	for(int id = 1, i = 2; pat[i]; i++)
	{
		int u = i-id;
		if (next[u]+i >= next[id]+id)
		{
			int j = next[id]+id-i;
			if (j < 0)
                j = 0;
			while (pat[j+i] && pat[j] == pat[j+i])
                j++;
			next[i] = j;
			id = i;
		}
		else
			next[i] = next[u];
	}
}
void ext_kmp(char *str, char *pat)
{
	get_next(pat);
	int k = 0;
	while (str[k] && pat[k] && str[k] == pat[k])
		k++;
	extend[0] = k;
	for (int id = 0, i = 1; str[i]; i++)
	{
		int u = i-id;
		if (i+next[u] < extend[id]+id)
			extend[i] = next[u];
		else
		{
			int j = extend[id]+id-i;
			if (j < 0)
                j = 0;
			while (str[j+i] && str[j+i] == pat[j])
                j++;
			extend[i] = j;
			id = i;
		}
	}
}
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
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%s", a);
		int len = strlen(a);
		strcpy(aa, a);
		strcpy(aa+len, a);
		ext_kmp(aa, a);
		get_fail(a);
		int cir = len-fail[len-1]-1, cnt = 0;
		if (len%cir)
			cir = len;
		for (int i = 0; i < cir; i++)
			if (extend[i] < len && aa[i+extend[i]] < a[extend[i]])
				cnt++;
		printf("Case %d: %d %d %d\n", cas, cnt, 1, cir-cnt-1);
	}
	return 0;
}
