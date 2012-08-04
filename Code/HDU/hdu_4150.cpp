#include<cstdio>
#include<cstring>
using namespace std;
int T;
char inc[1000000+5], ind[5+5];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", inc, ind);
        int len1 = strlen(inc), len2 = strlen(ind), ans = 0;
        for (int i = 0; i < len1; i++)
            if (!strncmp(inc+i, ind, len2))
            {
                ans++;
                i += len2-1;
            }
        printf("%d\n", ans);
    }
    return 0;
}
