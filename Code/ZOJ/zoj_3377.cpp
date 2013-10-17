// 2013-10-17 09:50:38	 Accepted	3377	C++	390	1500	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 5+5;
int N, M;
char mat[MAXN][MAXN];
map<int, bool> mp;
bool dfs(int x)
{
	map<int, bool>::iterator it = mp.find(x);
	if (it != mp.end())
		return it->second;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) if (x&(1<<(i*M+j)))
		{
			for (int k = 1; j+k < M; k++) if (!(x&(1<<(i*M+j+k))))
			{
				if (k > 1)
				{
					int y = x;
					for (int l = j; l <= j+k; l++)
						y ^= 1<<(i*M+l);
					if (!dfs(y))
					{
						mp.insert(make_pair(x, 1));
						return 1;
					}
				}
				break;
			}
			for (int k = 1; i+k < N; k++) if (!(x&(1<<((i+k)*M+j))))
			{
				if (k > 1)
				{
					int y = x;
					for (int l = i; l <= i+k; l++)
						y ^= 1<<(l*M+j);
					if (!dfs(y))
					{
						mp.insert(make_pair(x, 1));
						return 1;
					}
				}
				break;
			}
			for (int k = 1; j-k >= 0; k++) if (!(x&(1<<(i*M+j-k))))
			{
				if (k > 1)
				{
					int y = x;
					for (int l = j; l >= j-k; l--)
						y ^= 1<<(i*M+l);
					if (!dfs(y))
					{
						mp.insert(make_pair(x, 1));
						return 1;
					}
				}
				break;
			}
			for (int k = 1; i-k >= 0; k++) if (!(x&(1<<((i-k)*M+j))))
			{
				if (k > 1)
				{
					int y = x;
					for (int l = i; l >= i-k; l--)
						y ^= 1<<(l*M+j);
					if (!dfs(y))
					{
						mp.insert(make_pair(x, 1));
						return 1;
					}
				}
				break;
			}
		}
	mp.insert(make_pair(x, 0));
	return 0;
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		int root = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%s", mat[i]);
			for (int j = 0; j < M; j++) if (mat[i][j] == 'e')
				root ^= 1<<(i*M+j);
		}
		mp.clear();
		if (dfs(root))
			printf("Tewi first\n");
		else
			printf("Reisen first\n");
	}
	return 0;
}
