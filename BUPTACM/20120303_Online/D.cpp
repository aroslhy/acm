#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 10000;
const int INF = 0x3f3f3f3f;
int T;
int N, d[MAXN];
char s[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        d[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            int x = s[i-1]-'0';
            d[i] = d[i-1];
            if (i-2 >= 0 && s[i-2] != '0')
                d[i] = (d[i]+d[i-2])%1234567;
            x += 100*(s[i-3]-'0')+10*(s[i-2]-'0');
            if (i-3 >= 0 && s[i-3] != '0' && x <= 255)
                d[i] = (d[i]+d[i-3])%1234567;
//            printf("%d:%d\n", i, d[i]);
        }
        printf("%d\n", d[len]);
    }
    return 0;
}
