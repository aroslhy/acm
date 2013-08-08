// UESTC_DaPangZi	SPOJ AMR12I	Accepted	3584 KB	0 ms	C++ (g++ 4.0.0-8)	1307 B	2013-08-05 19:09:03
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 20000+5;
int T, N, K, pre[MAXN], next[MAXN];
char s[MAXN];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s", &N, &K, s+1);
		for (int i = 1; i <= N; i++)
		{
			if (s[i] == s[i-1])
				pre[i] = pre[i-1]+1;
			else
				pre[i] = 1;
		}
		for (int i = N; i >= 1; i--)
		{
			if (s[i] == s[i+1])
				next[i] = next[i+1]+1;
			else
				next[i] = 1;
		}
		queue<pair<int, int> > Q;
		int ans = 0, p = 1;
		bool flag = 1;
		for (int i = 1; i <= N; i++) if (next[i] >= K)
		{
			ans += next[i]/K;
			if (i-1-p >= 0)
				Q.push(make_pair(p, i-1));
			p = i+next[i]/K*K;
			i = p-1;
		}
		if (p == 1)
			flag = 0;
		else
		{
			if (N-p >= 0)
				Q.push(make_pair(p, N));
			while (flag && !Q.empty())
			{
				int a = Q.front().first, b = Q.front().second;
				Q.pop();
				bool vis = 0, gao = 0;
				if (next[a]+min(a-1, K) >= K)
				{
					if (b-a+1 == next[a])
						vis = 1;
					ans++;
					a += next[a];
					gao = 1;
				}
				if (!vis && pre[b]+min(N-b, K) >= K)
				{
					ans++;
					b -= pre[b];
					gao = 1;
				}
				if (a <= b)
					Q.push(make_pair(a, b));
				if (!gao)
					flag = 0;
			}
		}
		if (flag)
			printf("%d\n", ans);
		else
			printf("%d\n", -1);
	}
	return 0;
}
