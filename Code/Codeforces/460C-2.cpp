#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int N, M, W, a[MAXN], b[MAXN];
bool check(int x) {
	memset(b, 0, sizeof(b));
	int c = 0;
	for (int i = 1; i <= N; i++) {
		b[i] += b[i-1];
		int d = x-(a[i]+b[i]);
		if (d > 0) {
			c += d;
			b[i+1] += d;
			if (i+W <= N)
				b[i+W] -= d;
		}
		if (c > M)
			return false;
	}
	return true;
}
int main() {
	cin>>N>>M>>W;
	for (int i = 1; i <= N; i++)
		cin>>a[i];
	int ans, l = 1, r = 1e9+1e5+1;
	while (l < r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			l = mid+1;
		} else
			r = mid;
	}
	cout<<ans<<'\n';
	return 0;
}
