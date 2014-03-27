#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 500000+5;
int T, N, a[MAXN];
bool cmp(const int &a, const int &b) {
	return abs(a) < abs(b);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		sort(a, a+N, cmp);
		int ans = 0;
		if (N) {
			ans = 1;
			bool flag = a[0] < 0;
			for (int i = 1; i < N; i++) if (a[i] < 0 != flag) {
				ans++;
				flag = a[i] < 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
