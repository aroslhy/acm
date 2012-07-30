#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, K, H, P[40], timeleft[(1<<20)];
long long M;

struct node
{
	int num;
	long long cost;
	node(long long cc=0, int nn = 0):cost(cc), num(nn) {}
} left[(1<<19)+20], right[(1<<19)+20];
bool operator<(const node& a, const node& b)
{
	if (a.cost == b.cost) return a.num > b.num;
	return a.cost < b.cost;
}
bool sm2(const node& a, const node& b)
{
	if (a.cost == b.cost) return a.num < b.num;
	return a.cost > b.cost;
}

int main()
{
	int i, j, k, num;
	long long cost = 0;
	while (scanf("%d%d%lld", &N, &K, &M) != EOF)
	{
		right[0] = -1;
		for (i = 0; i < N; ++i)
			scanf("%d", P+i);
		H = N / 2;
		for (i = 0; i < (1<<H); ++i)
		{
			cost = 0;
			num = 0;
			for (j = 0; j < H; ++j)
				if ((i >> j) & 1)
					cost += P[j], ++num;
			left[i] = node(cost, num);
		}
		for (i = 0; i < (1<<(N-H)); ++i)
		{
			cost = 0;
			num = 0;
			for (j = 0; j < N-H; ++j)
				if ((i>>j)&1)
					cost += P[H+j], ++num;
			right[i] = node(cost, num);
		}
		sort(left, left+(1<<H));
		sort(right, right+(1<<(N-H)), sm2);
		int ans = 0, lb=0, rb=0;
		right[0].cost = (1ll << 60);
		right[(1<<N-H)] = node(-(1ll<<60), 0x3fffffff);
		for (i = 0; i < (1<<H); ++i)
		{
			if (left[i].cost > M) break;
			while (right[rb].cost >= M - left[i].cost)
				++rb;
			while (right[lb].cost > M - left[i].cost)
				++lb;
			while (lb < rb && right[lb].num + left[i].num < K)
				++lb;
			ans += rb - lb;
		}
		printf("%d\n", ans);
	}
	return 0;
}

