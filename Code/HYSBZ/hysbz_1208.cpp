// bigoceanlhy	1208	Accepted	940 kb	224 ms	C++/Edit	784 B	2013-03-25 20:01:06
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int MOD = 1000000;
int N, A, a, x;
int main()
{
	scanf("%d", &N);
	multiset<int> st;
	multiset<int>::iterator it[3];
	int ans = 0;
	while (N--)
	{
		scanf("%d%d", &a, &x);
		if ((A > 0 && a) || (A < 0 && !a))
		{
			it[0] = st.lower_bound(x);
			if (it[0] != st.begin())
			{
				it[1] = it[0];
				it[2] = it[1]--;
				if (abs(*it[1]-x) <= abs(*it[2]-x))
					it[0] = it[1];
				else
					it[0] = it[2];
			}
			ans = (ans+abs(*it[0]-x))%MOD;
			st.erase(*it[0]);
		}
		else
			st.insert(x);
		a ? A-- : A++;
	}
	printf("%d\n", ans);
	return 0;
}
