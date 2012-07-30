#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 1000+5;
int T, N, P[MAXN];
bool cmp(const int a, const int b)
{
    return a > b;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &P[i]);
        sort(P+1, P+1+N, cmp);
        int p1 = 0, p2, ans = 0;
        for (int i = N; i > 0; i--)
        {
            if (i%2)
            {
                p2 = P[i];
                ans ^= p2-p1-1;
            }
            else
                p1 = P[i];
        }
        if (ans)
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
