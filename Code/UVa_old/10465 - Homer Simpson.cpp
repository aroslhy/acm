#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX= 10000+5;
int m[2], t;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d", &m[0], &m[1], &t) != EOF)
    {
        int burger = 0, beer = t, cnt = 0;
        sort(m, m+2);
        while (beer >= m[0])
            burger++, beer -= m[0], cnt++;
        int max_burger = burger, min_beer = beer;
        while (beer > 0 && cnt)
        {
            burger--, beer += m[0], cnt--;
            if (beer >= m[1])
                burger++, beer -= m[1];
            if (beer < min_beer)
                max_burger = burger, min_beer = beer;
        }
        if (min_beer)
            printf("%d %d\n", max_burger, min_beer);
        else
            printf("%d\n", max_burger);
    }
    return 0;
}
