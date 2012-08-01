#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const int INF = 0x3f3f3f3f;
int T, c, a[MAXN], p, d[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &c);
        for (int i = 1; i <= c; i++)
        {
            scanf("%d%d", &a[i], &p);
            d[i] = INF;
            int s = 10*p;
            for (int j = i; j; j--)
            {
                s += a[j]*p;
                d[i] = min(d[i], d[j-1]+s);
            }
        }
        printf("%d\n", d[c]);
    }
    return 0;
}
