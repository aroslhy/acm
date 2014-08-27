#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int N, M, W, a[MAXN];
int Tr[MAXN<<2], mark[MAXN<<2];
void Build(int idx, int L, int R) {
	if (L == R) {
		Tr[idx] = a[R];
		return;
	}
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	Build(left, L, mid);
	Build(right, mid+1, R);
	Tr[idx] = min(Tr[left], Tr[right]);
}
void PushDown(int idx) {
	int left = idx<<1, right = idx<<1|1;
	Tr[left] += mark[idx];
	mark[left] += mark[idx];
	Tr[right] += mark[idx];
	mark[right] += mark[idx];
	mark[idx] = 0;
}
void Update(int idx, int L, int R, int l, int r, int c) {
	if (l <= L && R <= r) {
		Tr[idx] += c;
		mark[idx] += c;
		return;
	}
	if (mark[idx])
		PushDown(idx);
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	if (l <= mid)
		Update(left, L, mid, l, r, c);
	if (mid < r)
		Update(right, mid+1, R, l, r, c);
	Tr[idx] = min(Tr[left], Tr[right]);
}
int Query(int idx, int L, int R) {
	if (L == R)
		return R;
	if (mark[idx])
		PushDown(idx);
	int mid = (L+R)>>1, left = idx<<1, right = idx<<1|1;
	if (Tr[left] == Tr[idx])
		return Query(left, L, mid);
	else
		return Query(right, mid+1, R);
}
int main() {
	cin>>N>>M>>W;
	for (int i = 1; i <= N; i++)
		cin>>a[i];
	Build(1, 1, N);
	for (int i = 1; i <= M; i++) {
		int pos = Query(1, 1, N);
		Update(1, 1, N, pos, min(pos+W-1, N), 1);
	}
	cout<<Tr[1]<<'\n';
	return 0;
}
