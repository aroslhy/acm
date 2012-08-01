#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 65000+5;
long long n; bool isprime[MAXN];
long long cal(long long a, long long m)
{
    if (m == 1) return a;
    long long tmp = cal(a, m/2);
    if (m%2)
        return a*tmp%n*tmp%n;
    else
        return tmp*tmp%n;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	for (int i = 2; i <= MAXN; i++)
	{
	    bool flag = 1;
	    for (int j = 2; j*j <= i; j++)
            if (isprime[j] && i%j == 0)
            {
                flag = 0;
                break;
            }
        if (flag)
            isprime[i] = 1;
	}
	while (scanf("%lld", &n) && n)
	{
	    if (!n) break;
        bool flag = 1;
	    if (!isprime[n])
	    {
	        for (long long a = 2; a <= n-1; a++)
	            if (cal(a, n) != a)
	            {
	                flag = 0;
	                break;
	            }
	    }
        else flag = 0;
        if (flag)
//            printf("%lld\n", n);
            printf("The number %lld is a Carmichael number.\n", n);
        else
            printf("%lld is normal.\n", n);
	}
	return 0;
}
