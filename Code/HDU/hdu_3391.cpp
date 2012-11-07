//2012-11-07 12:42:07	Accepted	3391	15MS	276K	1549 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 27;
const char *mahjong[] = {
	"1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s",
	"1b", "2b", "3b", "4b", "5b", "6b", "7b", "8b", "9b",
	"1c", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c"
};
int T, cnt[MAX];
char tile[10];
int id(char *s)
{
	if (s[1] == 's')
		return s[0]-'1';
	else if (s[1] == 'b')
		return 9+s[0]-'1';
	else
		return 18+s[0]-'1';
}
bool check_standard()
{
	bool res = 0;
	for (int i = 0; i < MAX && !res; i++) if (cnt[i] >= 2)
	{
		int num = 0, tmp[MAX];
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
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
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
			if (check_standard())
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
			printf(" None\n");
	}
	return 0;
}
