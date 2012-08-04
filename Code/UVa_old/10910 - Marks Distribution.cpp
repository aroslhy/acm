#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 70+5;
int K, N, T, P, f[MAX][MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d%d%d", &N, &T, &P);
        T -= N*P;
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= N; i++)
            f[i][0] = 1;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= T; j++)
            {
                for (int k = 0; k <= j; k++)
                    f[i][j] += f[i-1][j-k];
//                printf("%d,%d:%d\n", i, j, f[i][j]);
            }
        printf("%d\n", f[N][T]);
    }
    return 0;
}
