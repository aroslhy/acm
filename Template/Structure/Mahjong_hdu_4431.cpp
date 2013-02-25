#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 34;
const char *mahjong[] = {
	"1m", "2m", "3m", "4m", "5m", "6m", "7m", "8m", "9m",
	"1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s",
	"1p", "2p", "3p", "4p", "5p", "6p", "7p", "8p", "9p",
	"1c", "2c", "3c", "4c", "5c", "6c", "7c"
};
int T, cnt[MAX];
char tile[10];
int id(char *s)
{
	if (s[1] == 'm')
		return s[0]-'1';
	else if (s[1] == 's')
		return 9+s[0]-'1';
	else if (s[1] == 'p')
		return 18+s[0]-'1';
	else
		return 27+s[0]-'1';
}
//bool check_standard_dfs(int dep)
//{
//	if (dep == 5)
//		return 1;
//	bool res = 0;
//	if (!dep)
//	{
//		for (int i = 0; i < MAX && !res; i++) if (cnt[i] >= 2)
//		{
//			cnt[i] -= 2;
//			res = check_standard_dfs(dep+1);
//			cnt[i] += 2;
//		}
//	}
//	else
//	{
//		for (int i = 0; i < MAX && !res; i++)
//		{
//			if (cnt[i] >= 3)
//			{
//				cnt[i] -= 3;
//				res = check_standard_dfs(dep+1);
//				cnt[i] += 3;
//			}
//			if (i < 27 && i%9 <= 6 && cnt[i] >= 1 && cnt[i+1] >= 1 && cnt[i+2] >= 1)
//			{
//				for (int j = 0; j < 3; j++)
//					cnt[i+j]--;
//				res = check_standard_dfs(dep+1);
//				for (int j = 0; j < 3; j++)
//					cnt[i+j]++;
//			}
//		}
//	}
//	return res;
//}
bool check_standard()
{
	bool res = 0;
	for (int i = 0; i < MAX && !res; i++) if (cnt[i] >= 2)
	{
		int tmp[MAX], num = 0;
		memcpy(tmp, cnt, sizeof(cnt));
		tmp[i] -= 2;
		for (int j = 0; j < MAX; j++)
		{
			if (tmp[j] >= 3)
			{
				tmp[j] -= 3;
				num++;
			}
			if (j < 27 && j%9 < 7)
			{
				while (tmp[j] >= 1 && tmp[j+1] >= 1 && tmp[j+2] >= 1)
				{
					for (int k = 0; k < 3; k++)
						tmp[j+k]--;
					num++;
				}
			}
		}
		res = (num == 4);
	}
	return res;
}
bool check_ChiiToitsu()
{
	for (int i = 0; i < MAX; i++)
		if (cnt[i] && cnt[i] != 2)
			return 0;
	return 1;
}
bool check_KokushiMuso()
{
	int res = 0;
	for (int i = 0; i < 3; i++)
	{
		if (cnt[i*9+0] >= 1 && cnt[i*9+8] >= 1)
			res += cnt[i*9+0]+cnt[i*9+8];
		else
			return 0;
	}
	for (int i = 27; i < MAX; i++)
	{
		if (cnt[i] >= 1)
			res += cnt[i];
		else
			return 0;
	}
	return (res == 14);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 13; i++)
		{
			scanf("%s", tile);
			cnt[id(tile)]++;
		}
		vector<int> ans;
		for (int i = 0; i < MAX; i++) if (cnt[i] < 4)
		{
			cnt[i]++;
			if (check_KokushiMuso() || check_ChiiToitsu() || check_standard())
				ans.push_back(i);
			cnt[i]--;
		}
		if (ans.size())
		{
			printf("%d", (int)ans.size());
			for (int i = 0; i < (int)ans.size(); i++)
				printf(" %s", mahjong[ans[i]]);
			printf("\n");
		}
		else
			printf("Nooten\n");
	}
	return 0;
}
