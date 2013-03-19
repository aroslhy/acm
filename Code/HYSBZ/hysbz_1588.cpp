// bigoceanlhy	1588	Accepted	1468 kb	212 ms	C++/Edit	829 B	2013-03-18 19:54:29
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int INF = 2147483647;
int N, x;
int main()
{
	scanf("%d%d", &N, &x);
	set<int> st;
	set<int>::iterator it;
	st.insert(x);
	int ans = x;
	for (int i = 1; i < N; i++)
	{
		if (scanf("%d", &x) == EOF)
			x = 0;
		if (st.find(x) == st.end())
		{
			int d = INF;
			it = st.lower_bound(x);
			if (it != st.begin())
			{
				it--;
				d = min(d, abs(x-(*it)));
			}
			it = st.upper_bound(x);
			if (it != st.end())
				d = min(d, abs(x-(*it)));
			ans += d;
			st.insert(x);
		}
	}
	printf("%d\n", ans);
	return 0;
}
