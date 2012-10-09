//Oct 1, 2012 8:03:30 PM 	bigoceanlhy 	230B - T-primes 	GNU C++ 	Accepted 	296 ms 	1400 KB
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 1000000+5;
const double eps = 1e-8;
int N;
long long x;
bool is[MAXM]; int prm[MAXN];
int getprm(int n){
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < n; j += s)
            is[j] = 0;
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
    return k;
}
int main()
{
    int c = getprm(1000003);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cin>>x;
        long long t = sqrt(x+0.0)+eps;
        if (t*t == x && is[(int)t])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
