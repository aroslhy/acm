#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAXN = 100+5, INF = 0x3f3f3f3f;
int T, n;
string s[MAXN], t, p, q;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int len = INF;
        for (int i = 1; i <= n; i++)
        {
            cin>>s[i];
            if (len > (int)s[i].length())
            {
                len = s[i].length();
                t = s[i];
            }
        }
        int ans = 0;
        for (int i = len; i > 0 && !ans; i--)
            for (int j = 0; j+i <= len; j++)
            {
                p.assign(t, j, i);
                q = "";
                for (int k = i-1; k >= 0; k--)
                    q += p.substr(k, 1);
                bool flag = 1;
                for (int k = 1; k <= n; k++)
                    if (s[k].find(p) == -1 && s[k].find(q) == -1)
                    {
                        flag = 0;
                        break;
                    }
                if (flag)
                {
                    ans = i;
                    break;
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
