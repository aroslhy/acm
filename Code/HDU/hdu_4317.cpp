#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10+5, MAXM = 20+5, MAXP = (1<<10)+5;
const int INF = 0x3f3f3f3f;
int N, p[MAXN], d[MAXM][MAXP], b[MAXM], cnt[MAXP], c, s;
void dfs(int x)
{
    if (x == 10)
    {
        cnt[s] = c;
        return;
    }

    s = (s|(1<<x))^(1<<x);
    dfs(x+1);

    s = (s|(1<<x));
    c++;
    dfs(x+1);
    c--;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    dfs(0);
    while (scanf("%d", &N) != EOF)
    {
        memset(b, 0, sizeof(b));
        memset(d, 0x3f, sizeof(d));
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
        for (int a = 0; a < (1<<N); a++)
        {
            int u = a&b[0], B = b[0]^a;
            if (!(cnt[B]%2))
                d[0][u] = min(d[0][u], cnt[a]);
        }
        for (int i = 1; i <= L; i++)
            for (int a = 0; a < (1<<N); a++)
                for (int v = 0; v < (1<<N); v++) if (d[i-1][v]+1)
                {
                    int u = (a&b[i])|(b[i]&v)|(v&a), B = b[i]^a^v;
                    if (!(cnt[B]%2))
                        d[i][u] = min(d[i][u], d[i-1][v]+cnt[a]*(1<<i));
                }
//        for (int i = 0; i <= L; i++)
//            for (int u = 0; u < (1<<N); u++) if (d[i][u] < INF)
//                printf("%d,%d:%d\n", i, u, d[i][u]);
        if (d[L][0] < INF)
            printf("%d\n", d[L][0]);
        else
            printf("impossible\n");
    }
    return 0;
}
