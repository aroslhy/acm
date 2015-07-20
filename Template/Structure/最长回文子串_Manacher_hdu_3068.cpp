// http://blog.csdn.net/ggggiqnypgjg/article/details/6645824
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 220000+5;
char s[MAXN];
int p[MAXN];
int Manacher(char *s) {
	int id, mx = 0, maxi = 0;
	for (int i = 1; s[i]; i++) {
		p[i] = (i < mx ? min(p[id*2-i], mx-i) : 1);
		while (s[i+p[i]] == s[i-p[i]])
			p[i]++;
		if (i+p[i] > mx)
			id = i, mx = i+p[i];
		maxi = max(maxi, p[i]-1);
	}
	return maxi;
}
int main() {
	while (scanf("%s", s+1) != EOF) {
		int len = strlen(s+1)*2+1;
		for (int i = len; i > 0; i--)
			s[i] = (i%2 ? '#' : s[i/2]);
		s[0] = '^', s[len+1] = 0;
		// for (int i = 1; i <= len; i++)
		// 	printf(" %c%c", s[i], (s[i+1] ? ' ' : '\n'));
		int ans = Manacher(s);
		// for (int i = 1; i <= len; i++)
		// 	printf("%2d%c", p[i], (s[i+1] ? ' ' : '\n'));
		printf("%d\n", ans);
	}
	return 0;
}
