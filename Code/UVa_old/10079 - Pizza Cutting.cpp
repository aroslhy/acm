#include<stdio.h>
long long N;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%lld", &N) && N >= 0)
        printf("%lld\n", 1+N*(N+1)/2);
    return 0;
}
