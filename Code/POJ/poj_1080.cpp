#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int T, len1, len2, d[MAXN][MAXN];
char g1[MAXN], g2[MAXN];
int sm[5][5] = {
    { 0,-3,-4,-2,-1},
    {-3, 5,-1,-2,-1},
    {-4,-1, 5,-3,-2},
    {-2,-2,-3, 5,-2},
    {-1,-1,-2,-2, 5}
};
int M[1<<8];
int main()
{
    freopen("input.txt", "r", stdin);
    M['-'] = 0; M['A'] = 1; M['C'] = 2; M['G'] = 3; M['T'] = 4;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s%d%s", &len1, g1, &len2, g2);
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++) if (i || j)
            {
                d[i][j] = -INF;
                if (i && j)
                    d[i][j] = max(d[i][j], d[i-1][j-1]+sm[M[g1[i-1]]][M[g2[j-1]]]);
                if (j)
                    d[i][j] = max(d[i][j], d[i][j-1]+sm[M['-']][M[g2[j-1]]]);
                if (i)
                    d[i][j] = max(d[i][j], d[i-1][j]+sm[M[g1[i-1]]][M['-']]);
//                printf("%d,%d:%d\n", i, j, d[i][j]);
            }
        printf("%d\n", d[len1][len2]);
    }
    return 0;
}
