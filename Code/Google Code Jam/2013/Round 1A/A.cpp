#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int T;
long double R, t;
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
//		scanf("%Lf%Lf", &R, &t);
		cin>>R>>t;
		long long l = 0, r = 1LL<<33, ans;
		while (l < r)
		{
			long long mid = (l+r)>>1;
			long double n = mid;
			long double A = 2*n*n+(2*R-1)*n;
			if (A <= t)
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid;
		}
//		printf("Case #%d: %lld\n", cas, ans);
		cout<<"Case #"<<cas<<": "<<ans<<"\n";
	}
	return 0;
}
