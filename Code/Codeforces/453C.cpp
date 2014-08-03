#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e5+5, MAXM = 2e5+5;
int N, M, X, Y, root, x[MAXN], y[MAXN];
int e, head[MAXN], next[MAXM], v[MAXM];
bool vis[MAXN];
vector<int> path;
void addEdge(int x, int y) {
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void step(int u) {
	path.push_back(u);
	y[u] ^= 1;
}
void dfs(int u, int pa) {
	if (vis[u])
		return;
	vis[u] = true;
	step(u);
	for (int i = head[u]; i != -1; i = next[i])
		dfs(v[i], u);
	if (x[u] != y[u]) {
		if (u != root) {
			step(pa);
			step(u);
		} else {
			path.pop_back();
			y[u] ^= 1;
		}
	}
	if (pa)
		step(pa);
}
bool check() {
	for (int i = 1; i <= N; i++) if (x[i] != y[i])
		return false;
	return true;
}
int main() {
	e = 0;
	memset(head, -1, sizeof(head));
	cin>>N>>M;
	for (int i = 1; i <= M; i++) {
		cin>>X>>Y;
		addEdge(X, Y);
		addEdge(Y, X);
	}
	for (int i = 1; i <= N; i++) {
		cin>>x[i];
		if (x[i])
			root = i;
	}
	dfs(root, 0);
	if (check()) {
		cout<<path.size()<<'\n';
		if (path.size()) {
			for (int i = 0; i < path.size(); i++)
				cout<<path[i]<<(i+1 < path.size() ? ' ' : '\n');
		}
	} else
		cout<<-1<<'\n';
	return 0;
}
