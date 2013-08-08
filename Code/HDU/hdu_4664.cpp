// 2013-08-08 19:41:13	Accepted	4664	453MS	200K	1166 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sg[] = {0, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7};
int T, N, n;
//bool vis[1000];
//int SG(int x)
//{
//	if (sg[x] != -1)
//		return sg[x];
//	memset(vis, 0, sizeof(vis));
//	for (int i = 1; i < x; i++)
//		vis[SG(i-1)^SG(x-i-1)] = 1;
//	for (int i = 0; ; i++) if (!vis[i])
//		return sg[x] = i;
//}
int main()
{
//	memset(sg, -1, sizeof(sg));
//	for (int i = 0; i < 34*4; i++)
//		printf("%d, ", SG(i));
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &n);
			if (n < 68)
				ans ^= sg[n];
			else
				ans ^= sg[(n-68)%34+68];
		}
		if (ans)
			printf("Carol\n");
		else
			printf("Dave\n");
	}
	return 0;
}
