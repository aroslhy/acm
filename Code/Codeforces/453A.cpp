#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
int M, N;
long double power(long double a, int b) {
	long double res = 1;
	while (b) {
		if (b&1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}
int main() {
	cin >> M >> N;
	long double ans = M;
	for (int i = 1; i < M; i++) {
		ans -= power(i*1.0/M, N);
	}
	cout << setiosflags(ios::fixed) << setprecision(6) << ans << endl;
	return 0;
}
