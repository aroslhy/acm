#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class PastingPaintingDivOne {
public:
	vector<long long> countColors(vector <string>, int);
	void update(vector<long long> &V, char &x, int y)
	{
		if (x == 'R')
			V[0] += y;
		else if (x == 'G')
			V[1] += y;
		else if (x == 'B')
			V[2] += y;
	}
};

vector<long long> PastingPaintingDivOne::countColors(vector <string> clipboard, int T) {
	int n = clipboard.size(), m = clipboard[0].size();
	vector<long long> ans;
	ans.push_back(0);
	ans.push_back(0);
	ans.push_back(0);
	for (int i = 0; i < n; i++)
		for (int k = 0; i+k < n && k < m; k++)
			if (clipboard[i+k][k] != '.')
			{
				update(ans, clipboard[i+k][k], T);
				for (int l = min(n-i, m)-1; l > k; l--)
				{
					for (int p = 0; p+l < min(n-i, m) && p < T; p++)
						if (clipboard[i+l+p][l+p] != '.')
						{
							update(ans, clipboard[i+l+p][l+p], 1);
							break;
						}
				}
				break;
			}
	for (int j = 1; j < m; j++)
		for (int k = 0; j+k < m && k < n; k++)
			if (clipboard[k][j+k] != '.')
			{
				update(ans, clipboard[k][j+k], T);
				for (int l = min(n, m-j)-1; l > k; l--)
				{
					for (int p = 0; p+l < min(n, m-j) && p < T; p++)
						if (clipboard[l+p][j+l+p] != '.')
						{
							update(ans, clipboard[l+p][j+l+p], 1);
							break;
						}
				}
				break;
			}
	return ans;
}
