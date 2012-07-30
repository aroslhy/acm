#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAX = 1000000+5, INF = 0x3f3f3f3f;
char s[MAX], S[2*MAX];
int p[2*MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (int cas = 1; ; cas++)
    {
        scanf("%s", s);
        if (!strcmp(s, "END")) break;
        int len = strlen(s);
        for (int i = 1; i <= 2*len+1; i++)
        {
            if (i%2)
                S[i] = '#';
            else
                S[i] = s[i/2-1];
        }
        int Len = 2*len+1;
        S[0] = '@'; S[Len+1] = '$';
        int id, mx = 0;
        int ans = 0;
        for (int i = 1; i <= Len; i++)
        {
            if (mx > i)
                p[i] = min(mx-i, p[id-(i-id)]);
            else
                p[i] = 1;
            while (S[i-p[i]] == S[i+p[i]])
                p[i]++;
            if (i+p[i] > mx)
            {
                mx = i+p[i];
                id = i;
            }
            ans = max(ans, p[i]-1);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
