// 2013-08-22 18:52:54	Accepted	4699	1484MS	10960K	1092 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
const int MAXN = 1000000+5;
const int INF = 0x3f3f3f3f;
int Q, X, K;
int sum[MAXN], maxi[MAXN];
char cmd[5];
int main()
{
	while (scanf("%d", &Q) != EOF)
	{
		deque<int> que;
		int cur = 0;
		maxi[0] = -INF;
		que.push_back(INF);
		while (Q--)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'I')
			{
				scanf("%d", &X);
				que.push_back(X);
				cur++;
				sum[cur] = sum[cur-1]+X;
				maxi[cur] = max(maxi[cur-1], sum[cur]);
			}
			else if (cmd[0] == 'D')
			{
				que.pop_back();
				cur--;
			}
			else if (cmd[0] == 'L')
			{
				if (!cur)
					continue;
				que.push_front(que.back());
				que.pop_back();
				cur--;
			}
			else if (cmd[0] == 'R')
			{
				if (que.front() == INF)
					continue;
				que.push_back(que.front());
				que.pop_front();
				cur++;
				sum[cur] = sum[cur-1]+que.back();
				maxi[cur] = max(maxi[cur-1], sum[cur]);
			}
			else
			{
				scanf("%d", &K);
				printf("%d\n", maxi[K]);
			}
		}
	}
	return 0;
}
