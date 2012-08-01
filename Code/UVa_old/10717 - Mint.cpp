#include<cstdio>
using namespace std;
const int MAXN = 50+5;
int n, t, table, coin[MAXN], w[230300+5];
int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x%y);
}
int lcm(int x, int y)
{
    return x/gcd(x, y)*y;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &t) && n && t)
	{
	    for (int i = 1; i <= n; i++)
            scanf("%d", &coin[i]);
        int count = 0;
        for (int a = 1; a <= n; a++)
            for (int b = a+1; b <= n; b++)
                for (int c = b+1; c <= n; c++)
                    for (int d = c+1; d <= n; d++)
                        w[++count] = lcm(lcm(coin[a], coin[b]), lcm(coin[c], coin[d]));
        while (t--)
        {
            scanf("%d", &table);
            int H = 0, L = 1<<30;
            for (int i = 1; i <= count; i++)
            {
                int k = table/w[i], l = table%w[i];
                if (!l)
                {
                    H = L = table;
                    break;
                }
                if (k*w[i] > H && k*w[i] <= table)
                    H = k*w[i];
                if ((k+1)*w[i] < L && (k+1)*w[i] >= table)
                    L = (k+1)*w[i];
            }
            printf("%d %d\n", H, L);
        }
	}
	return 0;
}
