/*
ID: bigocea1
PROG: inflate
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAX = 10000+5;
int M, N, p[MAX], m[MAX], dp[MAX];
int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++)
        scanf("%d%d", &p[i], &m[i]);
    for (int i = 1; i <= N; i++)
        for (int j = m[i]; j <= M; j++)
            dp[j] = max(dp[j], dp[j-m[i]]+p[i]);
    printf("%d\n", dp[M]);
	return 0;
}
