// aroslhy	SGU 510	Accepted	1023 KB	140 ms	GNU CPP (MinGW, GCC 4)	791 B	2013-07-17 20:01:45
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int N;
char s[50];
string ans;
int check(char *s)
{
	set<string> st;
	for (int i = 0; s[i]; i++)
		for (int j = i; s[j]; j++)
		{
			string sub = string(s).substr(i, j-i+1);
			st.insert(sub);
		}
	return st.size();
}
void dfs(int x, int l)
{
	if (x == l)
	{
		s[x] = 0;
		if (check(s) == N)
			ans = string(s);
		return;
	}
	for (int i = 0; i <= x && ans.empty(); i++)
	{
		s[x] = 'a'+i;
		for (int i = x+1; i < l; i++)
			s[i] = 'a'+i;
		if (check(s) < N)
			continue;
		dfs(x+1, l);
	}
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		int l = 0;
		while (l*(l+1)/2 < N)
			l++;
		ans.clear();
		while (ans.empty())
			dfs(0, l++);
		printf("%s\n", ans.c_str());
	}
	return 0;
}
