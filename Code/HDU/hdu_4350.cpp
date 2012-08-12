//2012-08-12 12:51:58	Accepted	4350	31MS	220K	648 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 52, MAXN = MAX+5;
int T, a[MAXN], N, L, R;
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        for (int i = 0; i < MAX; i++)
            scanf("%d", &a[i]);
        scanf("%d%d%d", &N, &L, &R);
        int m = (long long)N*(R-L+1)%R;
        printf("Case #%d:", cas);
        for (int i = 0; i < MAX; i++)
            printf(" %d", a[(i < R) ? (i-m+R)%R : i]);
        printf("\n");
    }
    return 0;
}
