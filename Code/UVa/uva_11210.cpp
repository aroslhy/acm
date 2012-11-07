//11210 	Chinese Mahjong 	Accepted 	C++ 	0.036 	2012-11-07 04:45:45
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int MAX = 34;
const char *mahjong[] = {
	"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
	"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
	"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"
};
int hand[14], cnt[MAX];
char tile[10];
map<string, int> dp;
bool check_standard_dfs(int dep)
{
	if (dep == 5)
		return 1;
	bool res = 0;
	if (!dep)
	{
		for (int i = 0; i < MAX && !res; i++) if (cnt[i] >= 2)
		{
			cnt[i] -= 2;
			res = check_standard_dfs(dep+1);
			cnt[i] += 2;
		}
	}
	else
	{
		for (int i = 0; i < MAX && !res; i++)
		{
			if (cnt[i] >= 3)
			{
				cnt[i] -= 3;
				res = check_standard_dfs(dep+1);
				cnt[i] += 3;
			}
			if (i < 27 && i%9 <= 6 && cnt[i] >= 1 && cnt[i+1] >= 1 && cnt[i+2] >= 1)
			{
				for (int j = 0; j < 3; j++)
					cnt[i+j]--;
				res = check_standard_dfs(dep+1);
				for (int j = 0; j < 3; j++)
					cnt[i+j]++;
			}
		}
	}
	return res;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		dp.insert(make_pair(mahjong[i], i));
	for (int cas = 1; scanf("%s", tile); cas++)
	{
		if (tile[0] == '0')
			break;
		memset(cnt, 0, sizeof(cnt));
		hand[0] = dp[tile];
		cnt[hand[0]]++;
		for (int i = 1; i < 13; i++)
		{
			scanf("%s", tile);
			hand[i] = dp[tile];
			cnt[hand[i]]++;
		}
		vector<int> ans;
		for (int i = 0; i < 34; i++) if (cnt[i] < 4)
		{
			cnt[i]++;
			if (check_standard_dfs(0))
				ans.push_back(i);
			cnt[i]--;
		}
		printf("Case %d:", cas);
		if (ans.size())
		{
			for (int i = 0; i < (int)ans.size(); i++)
				printf(" %s", mahjong[ans[i]]);
			printf("\n");
		}
		else
			printf(" Not ready\n");
	}
	return 0;
}
