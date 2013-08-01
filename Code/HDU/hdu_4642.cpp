// 2013-08-01 18:25:51	Accepted	4642	234MS	200K	327 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, M, mat;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				scanf("%d", &mat);
		printf("%s\n", mat ? "Alice" : "Bob");
	}
	return 0;
}
