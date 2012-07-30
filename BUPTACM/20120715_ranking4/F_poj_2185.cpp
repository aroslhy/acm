#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10000+5, MAXM = 75+5;
const int INF = 0x3f3f3f3f;
int R, C;
int fail[MAXN], cntr[MAXM], cntc[MAXN];
char mat[MAXN][MAXM];
void get_fail_r(int x)
{
    int len = C+1;
    fail[0] = -1;
    for (int i = 1, j = -1; i < len; i++)
    {
        while (j != -1 && mat[x][j+1] != mat[x][i])
            j = fail[j];
        if (mat[x][j+1] == mat[x][i])
            j++;
        fail[i] = j;
//        printf("%d:%d\n", i, C-(fail[i-1]+1));
    }
    int t = C;
    while ((t = fail[t-1]+1))
    {
        cntr[C-t]++;
//        printf("%d:%d\n", x, C-t);
    }
}
void get_fail_c(int x)
{
    int len = R+1;
    fail[0] = -1;
    for (int i = 1, j = -1; i < len; i++)
    {
        while (j != -1 && mat[j+1][x] != mat[i][x])
            j = fail[j];
        if (mat[j+1][x] == mat[i][x])
            j++;
        fail[i] = j;
//        printf("%d:%d\n", i, R-(fail[i-1]+1));
    }
    int t = R;
    while ((t = fail[t-1]+1))
    {
        cntc[R-t]++;
//        printf("%d:%d\n", x, R-t);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &R, &C);
    int ansr = C, ansc = R;
    for (int i = 0; i < R; i++)
    {
        scanf("%s", mat[i]);
        get_fail_r(i);
//        printf("row %d: %d\n", i, lenr[i]);
    }
    for (int i = 0; i < C; i++)
    {
        get_fail_c(i);
//        printf("col %d: %d\n", i, lenc[i]);
    }
    for (int i = 1; i < C; i++) if (cntr[i] == R)
    {
        ansr = i;
        break;
    }
    for (int i = 1; i < R; i++) if (cntc[i] == C)
    {
        ansc = i;
        break;
    }
    printf("%d\n", ansr*ansc);
    return 0;
}
