// Jun 24, 2013 5:38:17 AM	bigoceanlhy	 319A - Malek Dance Club	 GNU C++	Accepted	 15 ms	 0 KB
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100+5;
const long long MOD = 1000000007;
long long pow2[MAXN];
char x[MAXN];
int main()
{
	scanf("%s", x);
	int n = strlen(x);
	pow2[0] = 1;
	for (int i = 1; i < n; i++)
		pow2[i] = (pow2[i-1]*2)%MOD;
	long long d = pow2[n-1], ans = 0;
	for (int i = 0; i < n; i++) if (x[i] == '1')
		ans = (ans+pow2[n-i-1]*d)%MOD;
	cout<<ans<<'\n';
	return 0;
}
