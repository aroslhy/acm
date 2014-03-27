#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 26;
const int MAXN = 1000+5, MAXM = 20+5, MAXK = MAX+5;
int T, N, r[MAXN], ind[MAXK], outd[MAXK];
int e, head[MAXK], u[MAXN], v[MAXN], w[MAXN], next[MAXN];
char word[MAXN][MAXM];
bool vis[MAXN];
vector<int> V;
bool cmp(const int &a, const int &b) {
	return strcmp(word[a], word[b]) > 0;
}
void addedge(int x, int y, int z) {
	u[e] = x; v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void dfs(int x, int pre) {
	for (int i = head[x]; i != -1; i = next[i]) if (!vis[i]) {
		vis[i] = 1;
		dfs(v[i], i);
	}
	if (pre != -1)
		V.push_back(w[pre]);
}
int check()
{
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < MAX; i++) {
		if (abs(outd[i]-ind[i]) == 1)
			cnt1++;
		else if (abs(outd[i]-ind[i]) > 1)
			cnt2++;
	}
	if (cnt2 || cnt1 > 2)
		return -1;
	if (!cnt1) {
		for (int i = 0; i < MAX; i++) if (outd[i])
			return i;
	}
	else {
		for (int i = 0; i < MAX; i++) if (outd[i]-ind[i] == 1)
			return i;
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", word[i]);
			r[i] = i;
		}
		sort(r, r+N, cmp);
		memset(outd, 0, sizeof(outd));
		memset(ind, 0, sizeof(ind));
		e = 0;
		memset(head, -1, sizeof(head));
		for (int k = 0; k < N; k++) {
			int i = r[k], x = word[i][0]-'a', y = word[i][strlen(word[i])-1]-'a';
			addedge(x, y, i);
			outd[x]++; ind[y]++;
		}
		int s = check();
		if (s == -1)
			printf("***\n");
		else {
			memset(vis, 0, sizeof(vis));
			V.clear();
			dfs(s, -1);
			if (V.size() < N)
				printf("***\n");
			else {
				reverse(V.begin(), V.end());
				for (int i = 0; i < V.size(); i++)
					printf("%s%c", word[V[i]], i+1 < N ? '.' : '\n');
			}
		}
	}
	return 0;
}
