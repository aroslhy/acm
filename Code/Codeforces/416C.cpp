#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000+5;
int N, K, c, p, f[MAXN][MAXN];
pair<pair<int, int>, int> cp[MAXN];
pair<int, int> r[MAXN], d[MAXN][MAXN];
void print_ans(int i, int j) {
	if (!i)
		return;
	print_ans(i-1, f[i][j]-1);
	if (f[i][j])
		printf("%d %d\n", cp[f[i][j]].second, r[i].second);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &c, &p);
		cp[i] = make_pair(make_pair(c, p), i);
	}
	sort(cp+1, cp+1+N);
	scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &c);
		r[i] = make_pair(c, i);
	}
	sort(r+1, r+1+K);
	for (int i = 1; i <= K; i++)
		for (int j = 1; j <= N; j++) {
			d[i][j] = d[i][j-1];
			f[i][j] = f[i][j-1];
			int tmp = d[i-1][j-1].second+cp[j].first.second;
			if (cp[j].first.first <= r[i].first && tmp > d[i][j].second) {
				d[i][j] = make_pair(d[i-1][j-1].first+1, tmp);
				f[i][j] = j;
			}
		}
	printf("%d %d\n", d[K][N].first, d[K][N].second);
	print_ans(K, N);
	return 0;
}