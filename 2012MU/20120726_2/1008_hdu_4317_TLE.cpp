#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10+5, MAXM = 20+5, MAXP = (1<<10)+5;
const int INF = 0x7fffffff;
int N, p[MAXN], d[MAXM][MAXP], b[MAXM];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d", &N) != EOF)
    {
        memset(b, 0, sizeof(b));
        memset(d, -1, sizeof(d));
        int L = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &p[i]);
            for (int j = 0; (1<<j) <= p[i]; j++)
            {
                if (p[i]&(1<<j))
                    b[j] ^= (1<<i);
                L = max(L, j+1);
            }
        }
        for (int i = 0; i <= L; i++)
        {
            for (int u = 0; u < (1<<N); u++)
            {
                if(!i)
                {
                    int A = 0, B = b[i]^u, add = 0;
                    bool flag = 1;
                    for (int j = 0; j < N; j++)
                    {
                        if (((b[i]&(1<<j)) && (u&(1<<j))))
                            A ^= (1<<j);
                        if (B&(1<<j))
                            flag = !flag;
                        if (u&(1<<j))
                            add += (1<<i);
                    }
                    if (flag)
                        d[i][A] = (d[i][A]+1) ? min(d[i][A], add) : add;
                }
                else
                {
                    for (int v = 0; v < (1<<N); v++) if (d[i-1][v]+1)
                    {
                        int A = 0, B = b[i]^u^v, add = 0;
                        bool flag = 1;
                        for (int j = 0; j < N; j++)
                        {
                            if (((b[i]&(1<<j)) && (u&(1<<j))) || ((b[i]&(1<<j)) && (v&(1<<j))) || ((u&(1<<j)) && (v&(1<<j))))
                                A ^= (1<<j);
                            if (B&(1<<j))
                                flag = !flag;
                            if (u&(1<<j))
                                add += (1<<i);
                        }
                        if (flag)
                            d[i][A] = (d[i][A]+1) ? min(d[i][A], add+d[i-1][v]) : add+d[i-1][v];
                    }
                }
            }
        }
//        for (int i = 0; i <= L; i++)
//            for (int u = 0; u < (1<<N); u++) if (d[i][u]+1)
//                printf("%d,%d:%d\n", i, u, d[i][u]);
        if (d[L][0]+1)
            printf("%d\n", d[L][0]);
        else
            printf("impossible\n");
    }
    return 0;
}
