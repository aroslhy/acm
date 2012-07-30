#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int MAXN = 50+5, MAXM = 120*120+5;
int T, N, M;
char E[MAXN][MAXN], A[MAXN][MAXN];
map<string, bool> vis;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        vis.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%s", E[i]);
        for (int i = 0; i < N; i++)
            scanf("%s", A[i]);
        scanf("%d", &M);
        for (int i = 1; i <= M; i++)
        {
            char s[50];
            scanf("%s", s);
            vis[(string)s] = 1;
        }
        char partx[4][1000];
        memset(partx, 0, sizeof(partx));
        int cur[4] = {0,0,0,0};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (A[i][j] == '*')
                {
                    partx[0][cur[0]] = (E[i][j] != '.') ? E[i][j] : ' ';
                    cur[0]++;
                }
                if (A[N-j-1][i] == '*')
                {
                    partx[1][cur[1]] = (E[i][j] != '.') ? E[i][j] : ' ';
                    cur[1]++;
                }
                if (A[N-i-1][N-j-1] == '*')
                {
                    partx[2][cur[2]] = (E[i][j] != '.') ? E[i][j] : ' ';
                    cur[2]++;
                }
                if (A[j][N-i-1] == '*')
                {
                    partx[3][cur[3]] = (E[i][j] != '.') ? E[i][j] : ' ';
                    cur[3]++;
                }
            }
//        for (int i = 0; i < 4; i++)
//        {
//            printf("%s\n", partx[i]);
//        }
        char ans[4000], line[4000];
        ans[0] = 'z'+1;
        for (int i = 0; i < 4; i++)
        {
            char p = ' ';
            int now = 0;
            for (int j = i; j < i+4; j++)
            {
                int k = j%4;
                for (int l = 0; l < cur[k]; l++)
                    if (partx[k][l] != ' ' || p != ' ')
                    {
                        line[now++] = partx[k][l];
                        p = partx[k][l];
                    }
            }
            if (line[now-1] == ' ')
                now--;
            line[now] = 0;
//            printf("%d: %s\n", i, line);
            bool flag = 1;
            for (int j = 0; j < now && flag; )
            {
                char w[50];
                sscanf(line+j, "%s", w);
                if (!vis[string(w)])
                    flag = 0;
                else
                    j += strlen(w)+1;
            }
            if (flag && strcmp(line, ans) < 0)
                strcpy(ans, line);
        }
        printf("Case #%d: ", cas);
        if (ans[0] <= 'z')
            printf("%s\n", ans);
        else
            printf("FAIL TO DECRYPT\n");
    }
    return 0;
}

