#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const long long INF = 0x7fffffffffffffff;
long long k;
char s[MAXN];
bool is[MAXN]; long long prm[MAXN];
int getprm(int n)
{
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i])
    {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < n; j += s)
        is[j] = 0;
        // 因为j是奇数，所以+奇数i后是偶数，不必处理！
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
    return k; // 返回素数的个数
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int cnt_prm = getprm(64);
//    for (int i = 0; i < cnt_prm; i++)
//        printf("%d\n", prm[i]);
    while (scanf("%s%lld", s, &k) != EOF)
    {
        long long x = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (isdigit(s[i]))
                x = x*k+(s[i]-'0');
            else if (isupper(s[i]))
                x = x*k+(s[i]-'A'+10);
            else if (islower(s[i]))
                x = x*k+(s[i]-'a'+36);
        }
//        printf("x = %lld\n", x);
        long long K = k, ans = INF;
        for (int i = 0; i < cnt_prm; i++)
            if (!(K%prm[i]))
            {
                long long ckp = 0, nkp = 0;
                while (!(K%prm[i]))
                {
                    K /= prm[i];
                    nkp++;
                }
                long long X = x;
                while (X)
                {
                    ckp += X/prm[i];
                    X /= prm[i];
                }
                ans = min(ans, ckp/nkp);
            }
        printf("%lld\n", ans);
    }
    return 0;
}
