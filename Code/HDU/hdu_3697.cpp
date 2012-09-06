//2012-09-06 18:27:58	Accepted	3697	31MS	212K	1126 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300+5;
int N, A[MAXN], B[MAXN];
int S, T;
bool vis[MAXN];
int main()
{
    while (scanf("%d", &N) && N)
    {
        S = 1000; T = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &A[i], &B[i]);
            S = min(S, A[i]);
            T = max(T, B[i]);
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            fill(vis+1, vis+1+N, 0);
            int cnt = 0;
            for (int cur = S+i; cur < T; cur += 5)
            {
                int chs = 0;
                for (int j = 1; j <= N; j++)
                    if (!vis[j] && A[j] <= cur && cur < B[j] && (!chs || B[j] < B[chs]))
                        chs = j;
                if (chs)
                {
//                    printf("%d:%d ", cur, chs);
                    vis[chs] = 1;
                    cnt++;
                }
            }
//            printf("\n");
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}
