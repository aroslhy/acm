#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int N, p[MAXN], x[MAXN];
int e, head[MAXN], next[MAXN], v[MAXN];
long long d[MAXN][2];
void addedge(int x, int y) {
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void dfs(int u) {
	d[u][x[u]] = 1;
	for (int i = head[u]; i != -1; i = next[i]) {
		dfs(v[i]);
		d[u][1] = (d[v[i]][1]*d[u][0]%MOD+d[u][1]*(d[v[i]][0]+d[v[i]][1])%MOD)%MOD;
		d[u][0] = d[u][0]*(d[v[i]][0]+d[v[i]][1])%MOD;
	}
}
int main() {
	memset(head, -1, sizeof(head));
	cin>>N;
	for (int i = 1; i < N; i++) {
		cin>>p[i];
		addedge(p[i], i);
	}
	for (int i = 0; i < N; i++)
		cin>>x[i];
	dfs(0);
	cout<<d[0][1]<<'\n';
	return 0;
}
