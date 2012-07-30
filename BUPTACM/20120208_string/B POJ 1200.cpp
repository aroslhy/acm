#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 16e6+5;
int N, NC, P[1<<8];
char s[MAX];
bool vis1[1<<8], vis2[MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &NC);
    getchar();
    gets(s);
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (!vis1[s[i]])
        {
            vis1[s[i]] = 1;
            P[s[i]] = cnt++;
        }
    int h = 1;
    for (int i = 1; i < N; i++)
        h *= NC;
    int H = 0;
    for (int i = 0; i < N; i++)
        H = NC*H+P[s[i]];
    int ans = 0;
    for (int i = N; ; i++)
    {
        if (!vis2[H])
            vis2[H] = 1, ans++;
        if (i == len) break;
        H = NC*(H-h*P[s[i-N]])+P[s[i]];
    }
    printf("%d\n", ans);
    return 0;
}
