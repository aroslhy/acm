//1453 	Accepted 	1159ms 	2476kb 	G++	773B	2013-03-04 20:11:13 	bigoceanlhy
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100000+5;
int T, N, M, A[MAXN], B[MAXN], r[MAXN];
bool cmp(const int &a, const int &b)
{
	return B[a] < B[b];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &A[i], &B[i]);
			r[i] = i;
		}
		sort(r+1, r+N, cmp);
		priority_queue<int> pq;
		int ans = 0;
		for (int i = 1; (i < N || !pq.empty()) && M < B[0]; )
		{
			for (; i < N && B[r[i]] <= M; i++)
				pq.push(A[r[i]]);
			if (!pq.empty())
			{
				int x = pq.top(); pq.pop();
				M += x;
				ans++;
			}
		}
		if (M >= B[0])
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
