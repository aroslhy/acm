#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000+5, MAXM = 200000+5;
int T, N, X, Y, Z;
int e, head[MAXN], next[MAXM], v[MAXM];
int cnt[MAXN];
long long w[MAXM], ans;
void addedge(int x, int y, int z)
{
	v[e] = y; w[e] = z;
	next[e] = head[x]; head[x] = e++;
}
void dfs(int u, int fa = 0)
{
	cnt[u] = 1;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa)
	{
		dfs(v[i], u);
		ans += min(cnt[v[i]], N-cnt[v[i]])*2*w[i];
		cnt[u] += cnt[v[i]];
	}
}

void call_dfs()
{
	const int STACK_SIZE = 1<<23;
	static char stack[STACK_SIZE];
	int bak;
	__asm__ __volatile__
	(
		"movl %%esp, %0\n\t"
		"movl %1, %%esp\n\t":
		"=g"(bak):
		"g"(stack+STACK_SIZE-1):
	);

	dfs(1);

	__asm__ __volatile__
	(
		"movl %0, %%esp\n\t":
		:
		"g"(bak):
	);
}

int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		e = 0;
		memset(head, -1, sizeof(head));
		scanf("%d", &N);
		for (int i = 1; i < N; i++)
		{
			scanf("%d%d%d", &X, &Y, &Z);
			addedge(X, Y, Z);
			addedge(Y, X, Z);
		}
		ans = 0;
		call_dfs();
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
