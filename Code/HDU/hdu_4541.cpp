// 2013-03-31 22:16:09	Accepted	4541	0MS	224K	1146 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 100;
int T, N, M;
int len[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 7, 10, 10, 12, 11, 11, 10, 12, 12, 11, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 0, 0, 0, 0, 0};
int main()
{
	vector<int> vec[10];
	for (int i = 0; i < MAX; i++) if (len[i] < 10)
		vec[len[i]].push_back(i);
	for (int i = 1; i < MAX; i++) if (len[i]+6 < 10)
		vec[len[i]+6].push_back(MAX+i);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &N, &M);
		if (M <= vec[N].size())
		{
			if (vec[N][M-1] > MAX)
				printf("Case #%d: %d0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n", cas, vec[N][M-1]-100);
			else
				printf("Case #%d: %d\n", cas, vec[N][M-1]);
		}
		else
			printf("Case #%d: -1\n", cas);
	}
	return 0;
}
