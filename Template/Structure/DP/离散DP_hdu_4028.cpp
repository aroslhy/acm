/*
题意：给你n个钟的指针，第i个指针转一圈的时间是i单位，问你从n个钟任选一些指针使得，全部指针第一次回到原来的位置是经过的时间大于等于m，求又多少种选法。
思路：显然时间是你选的指针的最小公倍数，但是好大，dp无从下手。看完神牛的题解才知道有一种dp叫做离散dp，就是直接保存有用的状态就好了，其他的不用，这样空间就可以满足了，因为其实状态数很少。状态设定很简单：dp[i][j]：i表示以i指针结尾，最小公倍数（lcm）为j的方案数。转移也很简单就是dp[i][j]=dp[i][j]+dp[i-1][j];离散用了map，STL太强了，只能这么感慨，map要注意lcm的转移；还有初始状态为dp[i][i]=1;要在更新这个状态的时候加进去：
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAX = 40, MAXN = MAX+5;
const int INF = 0x3f3f3f3f;
int T, N;
long long M;
struct cmp
{
	bool operator()(const long long a, const long long b)
	{
		return a > b;
	}
};
map<long long, long long, cmp> d[MAXN];
long long gcd(long long x, long long y)
{
	return !y ? x : gcd(y, x%y);
}
long long lcm(long long x, long long y)
{
	return x/gcd(x, y)*y;
}
int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= MAX; i++)
	{
		d[i] = d[i-1];
		d[i][i]++;
		map<long long, long long, cmp>::iterator p = d[i-1].begin();
		for (; p != d[i-1].end(); p++)
			d[i][lcm(p->first, i)] += p->second;
	}
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%I64d", &N, &M);
		long long ans = 0;
		map<long long, long long, cmp>::iterator p = d[N].begin();
		for (; p != d[N].end() && p->first >= M; p++)
			ans += p->second;
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
