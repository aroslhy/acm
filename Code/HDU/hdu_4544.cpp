// 2013-03-31 22:32:38	Accepted	4544	265MS	2356K	1185 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100000+5;
int N, M, B[MAXN], D[MAXN], P[MAXN], r[MAXN];
bool cmp(const int &a, const int &b)
{
	return D[a] > D[b];
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		for (int i = 0; i < N; i++)
			scanf("%d", &B[i]);
		sort(B, B+N);
		for (int i = 0; i < M; i++)
			scanf("%d", &D[i]);
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &P[i]);
			r[i] = i;
		}
		sort(r, r+M, cmp);
		priority_queue<int, vector<int>, greater<int> > pq;
		long long ans = 0;
		bool flag = 1;
		for (int i = N-1, j = 0; i >= 0 && flag; i--)
		{
			while (j < M && D[r[j]] >= B[i])
				pq.push(P[r[j++]]);
			if (!pq.empty())
			{
				ans += (long long)pq.top();
				pq.pop();
			}
			else
				flag = 0;
		}
		if (flag)
			printf("%I64d\n", ans);
		else
			printf("No\n");
	}
	return 0;
}
