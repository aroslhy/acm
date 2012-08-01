#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 500*2+5, MAXM = 500*500+5;
const int INF = 0x3f3f3f3f;
int x[2][3], y[2][3], X[2][3];
long long L[2], l, D;
void find(long long p, long long q)
{
    long long mid = ((p+q)>>1);
    memcpy(y, x, sizeof(x));
    for (int i = 0; i < 2; i++)
    {
        l = L[i]-mid;
        while (l)
        {
            int a = y[i][1]-y[i][0], b = y[i][2]-y[i][1];
            if (a > b)
            {
                int g = l >= (a-1)/b ? (a-1)/b : l;
                y[i][1] -= g*b;
                y[i][2] -= g*b;
                l -= g;
            }
            else if (a < b)
            {
                int g = l >= (b-1)/a ? (b-1)/a : l;
                y[i][0] += g*a;
                y[i][1] += g*a;
                l -= g;
            }
        }
    }
    if (memcmp(y[0], y[1], 3*sizeof(int)))
    {
        if (p != q)
            find(p, mid);
    }
    else
    {
        D = mid;
        if (p != q)
            find(mid+1, q);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%d%d%d%d%d%d", &x[0][0], &x[0][1], &x[0][2], &x[1][0], &x[1][1], &x[1][2]) != EOF)
    {
        sort(x[0], x[0]+3);
        sort(x[1], x[1]+3);
        memcpy(X, x, sizeof(x));
        memset(L, 0, sizeof(L));
        for (int i = 0; i < 2; i++)
            for (;;)
            {
                int a = X[i][1]-X[i][0], b = X[i][2]-X[i][1];
                if (a > b)
                {
                    L[i] += (a-1)/b;
                    X[i][1] -= ((a-1)/b)*b; X[i][2] -= ((a-1)/b)*b;
                }
                else if (a < b)
                {
                    L[i] += (b-1)/a;
                    X[i][0] += ((b-1)/a)*a; X[i][1] += ((b-1)/a)*a;
                }
                else break;
            }
        if (memcmp(X[0], X[1], 3*sizeof(int)))
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        D = 0;
        find(0, min(L[0], L[1]));
//        printf("%lld %lld %lld\n", L[0], L[1], D);
        printf("%I64d\n", L[0]+L[1]-2*D);
//        printf("%lld\n", L[0]+L[1]-2*D);
    }
    return 0;
}
