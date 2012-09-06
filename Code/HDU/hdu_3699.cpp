//2012-09-06 18:36:16	Accepted	3699	250MS	212K	1951 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 8+5;
int T, X[5], a[3], ans;
char s[3][MAXN], t[MAXN];
bool hav[5], vis[10];
void dfs(int x)
{
    if (x == 5)
    {
        fill(a, a+3, 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; s[i][j]; j++)
                a[i] = a[i]*10+X[s[i][j]-'A'];
            sprintf(t, "%d", a[i]);
            if (strlen(t) != strlen(s[i]))
                return;
        }
//        for (int i = 0; i < 5; i++)
//            printf("%c:%d ", 'A'+i, X[i]);
//        printf("\n");
//        for (int i = 0; i < 3; i++)
//            printf("%d ", a[i]);
//        printf("\n");
        if (a[0]+a[1] == a[2])
        {
//            printf("%d + %d = %d\n", a[0], a[1], a[2]);
            ans++;
        }
        if (a[0]-a[1] == a[2])
        {
//            printf("%d - %d = %d\n", a[0], a[1], a[2]);
            ans++;
        }
        if ((long long)a[0]*a[1] == (long long)a[2])
        {
//            printf("%d * %d = %d\n", a[0], a[1], a[2]);
            ans++;
        }
        if ((long long)a[0] == (long long)a[2]*a[1] && a[1])
        {
//            printf("%d / %d = %d\n", a[0], a[1], a[2]);
            ans++;
        }
        return;
    }
    if (hav[x])
    {
        for (int i = 0; i < 10; i++)
            if (!vis[i])
            {
                vis[i] = 1;
                X[x] = i;
                dfs(x+1);
                vis[i] = 0;
            }
    }
    else
        dfs(x+1);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(hav, 0, sizeof(hav));
        for (int i = 0; i < 3; i++)
        {
            scanf("%s", s[i]);
            for (int j = 0; s[i][j]; j++)
                hav[s[i][j]-'A'] = 1;
        }
        ans = 0;
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}
