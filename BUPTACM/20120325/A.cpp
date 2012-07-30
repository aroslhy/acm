#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 50000+5;
const int MOD = 1000000007;
int N, M, K;
long long d[MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &N, &M, &K);
    int n = max(N, M);
    for (int i = 0; i <= n-K; i++)
        d[i][0] = 1;
    for (int i = 1; i <= n-K; i++)
        for (int j = 1; j <= i; j++)
        {
            d[i][j] = (d[i-1][j]+d[i-1][j-1])%MOD;
//            printf("%d,%d:%d\n", i, j, d[i][j]);
        }
    long long s1 = 0, s2 = 0;
    for (int i = K; i <= N-K; i++)
        for (int j = i+1; j <= N-K; j++)
            s1 = (s1+d[i-1][K-1]*d[N-j-1][K-1])%MOD;
    for (int i = K; i <= M-K; i++)
        for (int j = i+1; j <= M-K; j++)
            s2 = (s2+d[i-1][K-1]*d[M-j-1][K-1])%MOD;
    long long ans = (s1*s2)%MOD;
    printf("%I64d\n", ans);
    return 0;
}
