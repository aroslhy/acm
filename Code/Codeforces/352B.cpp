#include<cstdio>
#include<set>
#include<map>
#include<vector>
using namespace std;
int N, a;
int main()
{
	scanf("%d", &N);
	map<int, set<int> > con;
	map<int, set<int> >::iterator it;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		it = con.find(a);
		if (it == con.end())
			it = con.insert(make_pair(a, set<int>())).first;
		it->second.insert(i);
	}
	vector<pair<int, int> > ans;
	for (it = con.begin(); it != con.end(); it++)
	{
		if (it->second.size() == 1)
			ans.push_back(make_pair(it->first, 0));
		else
		{
			set<int>::iterator it2 = it->second.begin();
			int p = *it2++, d = *it2-p;
			p = *it2++;
			for (; it2 != it->second.end(); it2++)
			{
				if (*it2-p == d)
					p = *it2;
				else
					break;
			}
			if (it2 == it->second.end())
				ans.push_back(make_pair(it->first, d));
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
