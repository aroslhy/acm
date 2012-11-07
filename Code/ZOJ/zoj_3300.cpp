//2012-11-07 12:40:33 	Accepted 	3300 	C++ 	0 	180 	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 9;
int tile, cnt[MAX];
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
			if (j < 7)
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
	while (scanf("%d", &tile) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		cnt[tile-1]++;
		for (int i = 1; i < 13; i++)
		{
			scanf("%d", &tile);
			cnt[tile-1]++;
		}
		vector<int> ans;
		for (int i = 0; i < MAX; i++) if (cnt[i] < 4)
		{
			cnt[i]++;
			if (check_standard())
				ans.push_back(i);
			cnt[i]--;
		}
		for (int i = 0; i < (int)ans.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%d", ans[i]+1);
		}
		printf("\n");
	}
	return 0;
}
