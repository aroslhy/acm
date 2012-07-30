#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, K;
int car[4], loc;
char s[5];
long long com(int n, int r)
{// return C(n, r)
    if(n-r > r) r = n-r; // C(n, r) = C(n, n-r)
    long long s = 1;
    for(int i = 0, j = 1; i < r; i++)
    {
        s *= (long long)(n-i);
        for(; j <= r && s%(long long)j == 0; j++)
            s /= (long long)j;
    }
    return s;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &K);
    scanf("%s", s);
    if (!strcmp(s, "AA")) loc = 0;
    if (!strcmp(s, "AB")) loc = 1;
    if (!strcmp(s, "BA")) loc = 2;
    if (!strcmp(s, "BB")) loc = 3;
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", s);
        if (!strcmp(s, "AA")) car[0]++;
        if (!strcmp(s, "AB")) car[1]++;
        if (!strcmp(s, "BA")) car[2]++;
        if (!strcmp(s, "BB")) car[3]++;
    }
    long long ans = 0;
    for (int a = 0; a <= car[0]; a++)
        for (int b = 0; b <= car[1]; b++)
            for (int c = 0; c <= car[2]; c++)
                for (int d = 0; d <= car[3]; d++)
                {
                    if (a+b+c+d != K) continue;
                    int A = a, B = b, C = c, D = d;
                    if (loc == 0) A++;
                    if (loc == 1) B++;
                    if (loc == 2) C++;
                    if (loc == 3) D++;
                    if (B != C) continue;
                    if (loc == 0)
                        ans += com(A+B-1, a)*com(C+D-1, B-1);
                    if (loc == 1)
                        ans += com(A+B-1, a)*com(C+D-1, B-1);
                    if (loc == 2)
                        ans += com(A+B-1, a)*com(C+D-1, B-1);
                    if (loc == 3)
                        ans += com(A+B-1, a)*com(C+D-1, B);
                }
    if (ans > 0)
        printf("YES\n%lld\n", ans);
    else
        printf("NO\n");
    return 0;
}
