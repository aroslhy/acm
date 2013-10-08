// 2013-09-28 19:29:19	Accepted	4763	187MS	9052K	1496 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 1000000+5;
int T, extend[MAXN], next[MAXN];
char s[MAXN];
void get_next(char *pat)
{
	next[0] = strlen(pat);
	int k = 0;
	while (pat[k+1] && pat[k] == pat[k+1])
		k++;
	next[1] = k;
	for (int id = 1, i = 2; pat[i]; i++)
	{
		int u = i-id;
		if (next[u]+i >= next[id]+id)
		{
			int j = next[id]+id-i;
			if (j < 0)
				j = 0;
			while (pat[j+1] && pat[j] == pat[j+i])
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
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		ext_kmp(s, s);
		int len = strlen(s), ans = 0;
		set<int> st;
		for (int i = 0; i < len; i++) if (extend[i] == len-i)
			st.insert(i);
		for (int i = 1; i < len; i++)
		{
			int mini = min(i, extend[i]), maxi = max(i+mini, len-mini);
			set<int>::iterator it = lower_bound(st.begin(), st.end(), maxi);
			if (it != st.end())
				ans = max(ans, extend[*it]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
