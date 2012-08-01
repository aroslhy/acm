/*
ID: bigocea1
PROG: shopping
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
const int MAXN = 99+2, MAXM = 5+1;
const int INF = 0x3f3f3f3f;
int s, b, n[MAXN], C[MAXN][MAXM], K[MAXN][MAXM], R[MAXN], c[MAXM], k[MAXM], p[MAXM];
int d[MAXN][MAXM][MAXM][MAXM][MAXM][MAXM];
int match[1000];
int nk[MAXN][MAXM], np[MAXN];
int main()
{
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    scanf("%d", &s);
    for (int i = 1; i <= s; i++)
    {
        scanf("%d", &n[i]);
        for (int j = 1; j <= n[i]; j++)
            scanf("%d%d", &C[i][j], &K[i][j]);
        scanf("%d", &R[i]);
    }
    scanf("%d", &b);
    for (int i = 1; i <= b; i++)
    {
        scanf("%d%d%d", &c[i], &k[i], &p[i]);
        match[c[i]] = i;
    }
    for (int a1 = 0; a1 <= k[1]; a1++)
        for (int a2 = 0; a2 <= k[2]; a2++)
            for (int a3 = 0; a3 <= k[3]; a3++)
                for (int a4 = 0; a4 <= k[4]; a4++)
                    for (int a5 = 0; a5 <= k[5]; a5++)
                        d[0][a1][a2][a3][a4][a5] = a1*p[1]+a2*p[2]+a3*p[3]+a4*p[4]+a5*p[5];
    int cnt = 0;
    for (int i = 1; i <= s; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= n[i]; j++)
            if (!match[C[i][j]])
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            cnt++;
            for (int l = 1; l <= n[i]; l++)
                nk[cnt][match[C[i][l]]] = K[i][l];
            np[cnt] = R[i];
        }
    }
    for (int i = 1; i <= cnt; i++)
        for (int a1 = 0; a1 <= k[1]; a1++)
            for (int a2 = 0; a2 <= k[2]; a2++)
                for (int a3 = 0; a3 <= k[3]; a3++)
                    for (int a4 = 0; a4 <= k[4]; a4++)
                        for (int a5 = 0; a5 <= k[5]; a5++)
                        {
                            int &dp = d[i][a1][a2][a3][a4][a5];
//                            dp = a1*p[1]+a2*p[2]+a3*p[3]+a4*p[4]+a5*p[5]; !!!WRONG!!!
                            dp = d[i-1][a1][a2][a3][a4][a5];
                            for (int c = 1; ; c++)
                            {
                                if (a1 >= c*nk[i][1] && a2 >= c*nk[i][2] && a3 >= c*nk[i][3] && a4 >= c*nk[i][4] && a5 >= c*nk[i][5])
                                    dp = min(dp, d[i-1][a1-c*nk[i][1]][a2-c*nk[i][2]][a3-c*nk[i][3]][a4-c*nk[i][4]][a5-c*nk[i][5]]+c*np[i]);
                                else break;
                            }
//                            printf("%d, %d %d %d %d %d: %d\n", i, a1, a2, a3, a4, a5, dp);
                        }
    printf("%d\n", d[cnt][k[1]][k[2]][k[3]][k[4]][k[5]]);
    return 0;
}
