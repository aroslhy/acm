// UESTC_DaPangZi	SPOJ AMR12G	Accepted	3482 KB	0 ms	C++ (g++ 4.0.0-8)	686 B	2013-08-05 17:46:58
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN = 50+5;
int T, N, M, K, add[MAXN];
char mat[MAXN][MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &K);
		multiset<int, greater<int> > st;
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", mat[i]+1);
			add[i] = 0;
			for (int j = 1; j <= M; j++) if (mat[i][j] == '*')
				add[i]++;
			ans += add[i];
			add[i] = M-add[i]*2;
			st.insert(add[i]);
		}
		while (K--)
		{
			multiset<int, greater<int> >::iterator it = st.begin();
			int x = *it;
			ans += x;
			st.erase(it);
			st.insert(-x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
