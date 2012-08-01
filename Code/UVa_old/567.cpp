#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 20+5;
int d[MAX][MAX], N, A, B, cas = 0;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    bool flag = 1;
    while (flag)
    {
        memset(d, 63, sizeof(d));
        for (int I = 1; I < 20; I++)
        {
            int n;
            if (scanf("%d", &n) == EOF)
            {
                flag = 0;
                break;
            }
            d[I][I] = 0;
            while (n--)
            {
                int J; scanf("%d", &J);
                d[I][J] = d[J][I] = 1;
            }
        }
        if (!flag) break;
        d[20][20] = 0;
        for (int k = 1; k <= 20; k++)
            for (int i = 1; i <= 20; i++)
                for (int j = 1; j <= 20; j++)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        printf("Test Set #%d\n", ++cas);
        scanf("%d", &N);
        while (N--)
        {
            scanf("%d%d", &A, &B);
            printf("%2d to %2d: %d\n", A, B, d[A][B]);
        }
        printf("\n");
    }
    return 0;
}
