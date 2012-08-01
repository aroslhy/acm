#include<cstdio>
#include<cstring>
using namespace std;
int n, f, a[800000], b[800000];
bool vis[10];
int isspecial(int x)
{
    memset(vis, 0, sizeof(vis));
    while (x)
    {
        int b = x%10;
        if (vis[b])
            return 0;
        else
            vis[b] = 1;
        x /= 10;
    }
    return 1;
}
int BSearch(int l, int r)
{
    if (l+1 == r)
        return b[l];
    int m = (l+r)/2;
    if (a[m] > n)
        return BSearch(l, m);
    else if (a[m] < n)
        return BSearch(m, r);
    else
        return b[m];
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    f = 0;
    int count = 0;
    for (int i = 2; i <= 10000000; i++)
        if (isspecial(i-1))
        {
            f++;
//            printf("%d %d\n", i, f[i]);
            count++;
            a[count] = i;
            b[count] = f;
        }
    while (scanf("%d", &n) != EOF)
    {
        if (n <= 1)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", BSearch(1, count+1));
    }
    return 0;
}
