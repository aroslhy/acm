//2012-09-24 15:33:02	Accepted	4414	0MS	264K	2058 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50+5;
int N, cnt[4][MAXN][MAXN];
char mat[MAXN][MAXN];
int main()
{
    while (scanf("%d", &N) && N)
    {
        memset(mat, 0, sizeof(mat));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= N; i++)
            scanf("%s", mat[i]+1);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (mat[i][j] == '#')
                {
                    cnt[0][i][j] = cnt[0][i][j-1]+1;
                    cnt[2][i][j] = cnt[2][i-1][j]+1;
                }
                else
                    cnt[0][i][j] = cnt[2][i][j] = 0;
                if (mat[N-i+1][N-j+1] == '#')
                {
                    cnt[1][N-i+1][N-j+1] = cnt[1][N-i+1][N-j+2]+1;
                    cnt[3][N-i+1][N-j+1] = cnt[3][N-i+2][N-j+1]+1;
                }
                else
                    cnt[1][N-i+1][N-j+1] = cnt[3][N-i+1][N-j+1] = 0;
            }
        int ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                int n = cnt[0][i][j];
                if (n > 1 && n == cnt[1][i][j] && n == cnt[2][i][j] && n == cnt[3][i][j])
                {
                    bool flag = 1;
                    for (int k = 1; k < n && flag; k++)
                    {
                        if (mat[i-k][j-1] == '#' || mat[i-k][j+1] == '#')
                            flag = 0;
                        if (mat[i+k][j-1] == '#' || mat[i+k][j+1] == '#')
                            flag = 0;
                        if (mat[i-1][j-k] == '#' || mat[i+1][j-k] == '#')
                            flag = 0;
                        if (mat[i-1][j+k] == '#' || mat[i+1][j+k] == '#')
                            flag = 0;
                    }
                    if (flag)
                        ans++;
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
