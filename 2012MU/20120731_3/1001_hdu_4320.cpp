#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 1000000+5, MAXP = 80000+5;
int T;
long long A, B, prime[MAXP];
bool vis[MAXM];
int main()
{
    freopen("input.txt", "r", stdin);
    long long m = 1000000;
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= m; i++) if (!vis[i])
    {
        prime[cnt++] = i;
        if ((long long)i*i <= m)
        {
            for (int j = i*i; j <= m; j += i)
                vis[j] = 1;
        }
    }
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%I64d%I64d", &A, &B);
        bool flag = 1;
        for (int i = 0; i < cnt && flag && A > 1; i++)
        {
            if (!(A%prime[i]))
            {
                if (B%prime[i])
                    flag = 0;
                if (flag)
                {
                    while (!(A%prime[i]))
                        A /= prime[i];
                }
            }
        }
        if (A > 1 && B%A)
            flag = 0;
        printf("Case #%d: %s\n", cas, flag ? "YES" : "NO");
    }
    return 0;
}
