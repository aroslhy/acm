#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX = 100000+5, INF = 0x3f3f3f3f;
char s[MAX], p[MAX], t[MAX];
int len_s, len_p, vis_s[26], vis_p[26];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%s%s", s, p);
    len_s = strlen(s);
    len_p = strlen(p);
    for (int i = 0; i < len_p; i++)
        vis_p[p[i]-'a']++;
    int ans = 0;
    for (int i = 0; i+len_p <= len_s; i++)
    {
        if (!i)
        {
            memset(vis_s, 0, sizeof(vis_s));
            for (int j = 0; j < len_p; j++)
                if (s[j] != '?')
                    vis_s[s[j]-'a']++;
        }
        else
        {
            if (s[i-1] != '?')
                vis_s[s[i-1]-'a']--;
            if (s[i+len_p-1] != '?')
                vis_s[s[i+len_p-1]-'a']++;
        }
        bool flag = 1;
        for (int j = 0; j < 26; j++)
            if (vis_s[j] > vis_p[j])
            {
                flag = 0;
                break;
            }
        if (flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
