#include <cstdio>
#include <cmath>
int N;
int main() {
	for (int cas = 1; scanf("%d", &N) && N > 0; cas++) {
		printf("Case %d: %d\n", cas, int(ceil(log(N)/log(2))));
	}
	return 0;
}
