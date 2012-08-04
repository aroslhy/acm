#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5;
int T, N, Q, x, y, cas = 0, ci[MAXN], cj[MAXN];
bool f[MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(f, 0, sizeof(f));
        memset(ci, 0, sizeof(ci));
        memset(cj, 0, sizeof(cj));
        scanf("%d", &N); getchar();
        for (int i = 0; i < N; i++)
        {
            char line[MAXN];
            fgets(line, MAXN, stdin);
            for (int j = 0; j < N; j++)
            {
                if (line[j] == 'b')
                    f[i+1][j+1] = 1;
                else
                    f[i+1][j+1] = 0;
            }
        }
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++)
        {
            scanf("%d%d", &x, &y);
            ci[x]++; cj[y]++;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (f[i][j] && (ci[i]+cj[j])%2)
                    ans++;
                else if (!f[i][j] && !((ci[i]+cj[j])%2))
                    ans++;
            }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
