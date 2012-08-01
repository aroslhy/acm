#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 100000+5, MAXM = 12*16+5;
int b, d;
int gcd(int x, int y)
{
    return !y ? x : gcd(y, x%y);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d%d", &b, &d);
//    printf("%d\n", gcd(100, 64));
    int cnt2 = 0, cnt3 = 0, cnt11 = 0;
    int g;
    while ((g = gcd(b, d)) > 1)
        cnt2++, d /= g;
    if (!((b-1)%d) && d > 1)
        cnt3++, d /= b-1;
    else if (!((b+1)%d) && d > 1)
        cnt11++, d /= b+1;
    else
    {
        if ((g = gcd(b-1, d)) > 1)
        {
            int t = d/g;
            if (gcd(b-1, t) == 1)
                cnt3++, d /= g;
        }
        if ((g = gcd(b+1, d)) > 1)
        {
            int t = d/g;
            if (gcd(b+1, t) == 1)
                cnt11++, d /= g;
        }
    }
    if (d > 1)
        printf("7-type\n");
    else if (cnt2 && !cnt3 && !cnt11)
        printf("2-type\n%d\n", cnt2);
    else if (!cnt2 && cnt3 && !cnt11)
        printf("3-type\n");
    else if (!cnt2 && !cnt3 && cnt11)
        printf("11-type\n");
    else
        printf("6-type\n");
    return 0;
}
