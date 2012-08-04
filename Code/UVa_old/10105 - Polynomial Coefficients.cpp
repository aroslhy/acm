#include<cstdio>
using namespace std;
int k, n, ni;
int P(int m, int n)
{
    int res = 1;
    for (int i = m; i > m-n; i--)
        res *= i;
    return res;
}
int C(int m, int n)
{
    return P(m, n)/P(n, n);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &k) != EOF)
	{
        int ans = 1;
	    for (int i = 1; i <= k; i++)
	    {
            scanf("%d", &ni);
            ans *= C(n, ni);
            n -= ni;
	    }
	    printf("%d\n", ans);
	}
	return 0;
}
