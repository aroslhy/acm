#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 30+5, MAXM = 10000;
const int INF = 0x3f3f3f3f;
int T;
int n[5];
int s[5][33][28], S[28];
int ans;
void Search(int x)
{
    if (x == 4)
    {
        int tmp = 0;
        for (int j = 0; j < 26; j++)
            tmp += S[j]*S[j];
        ans = max(ans, tmp);
    }
    for (int i = 0; i < n[x]; i++)
    {
        for (int j = 0; j < 26; j++)
            S[j] += s[x][i][j];
        Search(x+1);
        for (int j = 0; j < 26; j++)
            S[j] -= s[x][i][j];
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        memset(s, 0, sizeof(s));
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &n[i]);
            for (int j = 0; j < n[i]; j++)
            {
                char str[1000];
                scanf("%s", str);
                int len = strlen(str);
                for (int k = 0; k < len; k++)
                {
                    s[i][j][str[k]-'a']++;
                }
            }
        }
        ans = 0;
        Search(0);
        printf("%d\n", ans);
    }
    return 0;
}
