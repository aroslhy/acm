// 2013-07-31 15:16:15	Accepted	4628	93MS	556K	1167 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAX = 16, MAXN = MAX+5;
const int INF = 0x3f3f3f3f;
int T, N, d[1<<MAX];
char s[MAXN], t[MAXN];
bool chs[MAXN];
set<int> st;
void dfs(int x, int &u)
{
	if (x == N)
	{
		int l = 0;
		for (int i = 0; i < N; i++) if (u&(1<<(N-i-1)))
			t[l++] = s[i];
		bool flag = 1;
		for (int i = 0; i < l/2 && flag; i++) if (t[i] != t[l-i-1])
			flag = 0;
		if (flag)
			st.insert(u);
		return;
	}
	u &= ~(1<<(N-x-1));
	dfs(x+1, u);
	u |= 1<<(N-x-1);
	dfs(x+1, u);
}
int D(int u)
{
	if (d[u] != -1)
		return d[u];
	d[u] = INF;
	set<int>::iterator it1, it2;
	for (int i = 0; i < N; i++) if (u&(1<<(N-i-1)))
	{
		it1 = st.lower_bound(1<<(N-i-1));
		it2 = st.lower_bound(1<<(N-i));
		break;
	}
	for (; it1 != it2; it1++) if ((u|(*it1)) == u)
	{
		int v = u^(*it1);
		d[u] = min(d[u], D(v)+1);
	}
	return d[u];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		st.clear();
		memset(d, -1, sizeof(d));
		scanf("%s", s);
		N = strlen(s);
		int u = 0;
		dfs(0, u);
		d[0] = 0;
		printf("%d\n", D((1<<N)-1));
	}
	return 0;
}
