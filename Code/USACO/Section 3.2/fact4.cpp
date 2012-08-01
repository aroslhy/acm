/*
ID: bigocea1
PROG: fact4
LANG: C++
*/
#include<cstdio>
using namespace std;
int N;
int main()
{
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
	scanf("%d", &N);
	int n2 = 0, n5 = 0, ans = 1;
	for (int i = 1; i <= N; i++)
	{
	    ans *= i;
	    int a = i;
	    while (!(a%2))
            n2++, a /= 2;
	    int b = i;
	    while (!(b%5))
            n5++, b /= 5;
        while (n2 && n5)
            ans /= 10, n2--, n5--;
        ans %= 100000;
	}
	printf("%d\n", ans%10);
	return 0;
}
