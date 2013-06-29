// Jun 28, 2013 7:45:49 PM	bigoceanlhy	 322A - Ciel and Dancing	 GNU C++	Accepted	 15 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M;
int main()
{
	scanf("%d%d", &N, &M);
	printf("%d\n", N+M-1);
	for (int i = 1; i <= M; i++)
		printf("%d %d\n", 1, i);
	for (int i = 2; i <= N; i++)
		printf("%d %d\n", i, 1);
	return 0;
}
