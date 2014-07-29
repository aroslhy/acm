#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 20, MAXN = MAX+5;
const int MOD = 1e9+7;
int N;
long long S, f[MAXN], inv[MAXN], ans;
long long modpow(long long a, int b) {
	long long res = 1;
	while (b) {
		if (b&1)
			res = res*a%MOD;
		a = a*a%MOD;
		b >>= 1;
	}
	return res;
}
long long com(long long n, long long m) {
	m = min(m, n-m);
	long long res = 1;
	for (int i = 0; i < m; i++)
		res = res*(n-i)%MOD*inv[m-i]%MOD;
	return res;
}
long long Lucas(long long n, long long m) {
	long long res = 1;
	while (n && m) {
		long long a = n%MOD, b = m%MOD;
		res = res*com(a, b)%MOD;
		n /= MOD, m /= MOD;
	}
	return res;
}
void dfs(int x, long long s, int c) {
	if (x == N) {
		long long r = S-s-c;
		if (r >= 0)
			ans = (ans+Lucas(r+N-1, N-1)*modpow(-1, c)+MOD)%MOD;
		return;
	}
	dfs(x+1, s, c);
	dfs(x+1, s+f[x], c+1);
}
int main() {
	for (int i = 0; i < MAX; i++)
		inv[i] = modpow(i, MOD-2);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> f[i];
	ans = 0;
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}
