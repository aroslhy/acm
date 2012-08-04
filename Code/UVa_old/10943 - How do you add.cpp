#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 100+5;
int N, K, f[MAX][MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &N, &K))
    {
        if (!N && !K) break;
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= K; i++)
            for (int j = 0; j <= N; j++)
                for (int k = 0; k <= j; k++)
                    f[i][j] = (f[i][j]+f[i-1][j-k])%1000000;
        printf("%d\n", f[K][N]);
    }
    return 0;
}
