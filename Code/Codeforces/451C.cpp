#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T;
long long N, K, d1, d2;
bool check(long long a, long long b, long long c) {
	if (a < 0 || b < 0 || c < 0)
		return false;
	long long maxi = max(a, max(b, c));
	long long d = maxi*3-a-b-c;
	return N-K-d >= 0 && (N-K-d)%3 == 0;
}
int main() {
	// freopen("put.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		cin >> N >> K >> d1 >> d2;
		bool flag = false;
		long long y = K-d1*2-d2;
		if (y >= 0 && y%3 == 0) {
			long long x1 = y/3, x2 = x1+d1, x3 = x2+d2;
			flag = flag||check(x1, x2, x3);
		}
		y = K-d1*2+d2;
		if (y >= 0 && y%3 == 0) {
			long long x1 = y/3, x2 = x1+d1, x3 = x2-d2;
			flag = flag||check(x1, x2, x3);
		}
		y = K+d1*2-d2;
		if (y >= 0 && y%3 == 0) {
			long long x1 = y/3, x2 = x1-d1, x3 = x2+d2;
			flag = flag||check(x1, x2, x3);
		}
		y = K+d1*2+d2;
		if (y >= 0 && y%3 == 0) {
			long long x1 = y/3, x2 = x1-d1, x3 = x2-d2;
			flag = flag||check(x1, x2, x3);
		}
		printf("%s\n", flag ? "yes" : "no");
	}
	return 0;
}
