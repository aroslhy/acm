#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000+5, MAXM = 100+5;
const int INF = 0x3f3f3f3f;
int p, q, n;
bool SG(int x, int y)
{
    if (x > y) swap(x, y);
    if (x == 0)
        return 0;
    bool flag = 1;
    int c = y/x;
    if (!SG(x, y-c*x))
        return 1;
    if (c > 1 && !SG(x, y-(c-1)*x))
        return 1;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &p, &q) && p && q)
    {
//        printf("%d\n", SG(p, q));
        printf(SG(p, q) ? "Stan wins\n" : "Ollie wins\n");
    }
    return 0;
}
