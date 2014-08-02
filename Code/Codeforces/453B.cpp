#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100+5, MAX = 16, MAXB = 59, ALL = (1<<MAX)-1;
const int prm[MAX] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int N, a, d[MAXN][1<<MAX], p[MAXN][1<<MAX], st[MAXB];
void print_path(int n, int x) {
	if (!n)
		return;
	print_path(n-1, x^st[p[n][x]]);
	cout<<p[n][x]<<(n < N ? ' ' : '\n');
}
int main() {
	for (int i = 0; i < MAXB; i++)
		for (int j = 0; j < MAX; j++) if (!(i%prm[j]))
			st[i] ^= 1<<j;
	cin>>N;
	memset(d, 0x3f, sizeof(d));
	d[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		cin>>a;
		for (int b = 1; b < MAXB; b++)
			for (int u = 0; u <= ALL; u++) if (!(u&st[b])) {
				int v = u^st[b], r = d[i-1][u]+abs(a-b);
				if (r < d[i][v]) {
					d[i][v] = r;
					p[i][v] = b;
				}
			}
	}
	int mini = INF, x;
	for (int u = 0; u <= ALL; u++) if (d[N][u] < mini) {
		x = u;
		mini = d[N][u];
	}
	print_path(N, x);
	return 0;
}
