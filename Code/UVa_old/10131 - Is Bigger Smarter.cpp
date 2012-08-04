#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 1000+5;
struct E {int W, S, num;} e[MAXN];
int dp[MAXN], front[MAXN];
int cmp(const void *a, const void *b)
{
    E *x = (E *)a; E *y = (E *)b;
    return x->W - y->W;
}
void print_e(int x)
{
    if (front[x])
        print_e(front[x]);
    if (x)
        printf("%d\n", e[x].num);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int cnt = 0;
    while (scanf("%d%d", &e[cnt+1].W, &e[cnt+1].S) != EOF)
        e[cnt+1].num = cnt+1, dp[cnt+1] = 1, cnt++;
    qsort(e+1, cnt, sizeof(E), cmp);
//    for (int i = 1; i <= cnt; i++)
//        printf("%d:%d %d, %d\n", i, e[i].W, e[i].S, e[i].num);
    int n = cnt ? 1 : 0, rear = cnt ? 1 : 0;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j < i; j++)
            if (e[i].W > e[j].W && e[i].S < e[j].S && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                if (dp[i] > n)
                    n = dp[i], rear = i;
                front[i] = j;
            }
//        printf("%d:%d\n", i, dp[i]);
    }
    printf("%d\n", n);
    print_e(rear);
    return 0;
}
