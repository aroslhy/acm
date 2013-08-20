// 2013-08-14 16:18:30	Accepted	4584	0MS	264K	1295 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int MAXN = 40+5;
int N, M;
char mat[MAXN][MAXN];
int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (!N && !M)
			break;
		vector<pair<int, int> > VH, VC;
		for (int i = 0; i < N; i++)
		{
			scanf("%s", mat[i]);
			for (int j = 0; j < M; j++)
			{
				if (mat[i][j] == 'H')
					VH.push_back(make_pair(i, j));
				else if (mat[i][j] == 'C')
					VC.push_back(make_pair(i, j));
			}
		}
		vector<pair<int, int> >::iterator it1, it2;
		int mini = 100;
		for (it1 = VH.begin(); it1 != VH.end(); it1++)
			for (it2 = VC.begin(); it2 != VC.end(); it2++)
				mini = min(mini, abs((*it1).first-(*it2).first)+abs((*it1).second-(*it2).second));
		set<pair<pair<int, int>, pair<int, int> > > st;
		for (it1 = VH.begin(); it1 != VH.end(); it1++)
			for (it2 = VC.begin(); it2 != VC.end(); it2++) if (abs((*it1).first-(*it2).first)+abs((*it1).second-(*it2).second) == mini)
				st.insert(make_pair(make_pair((*it1).first, (*it1).second), make_pair((*it2).first, (*it2).second)));
		printf("%d %d %d %d\n", (*st.begin()).first.first, (*st.begin()).first.second, (*st.begin()).second.first, (*st.begin()).second.second);
	}
	return 0;
}
