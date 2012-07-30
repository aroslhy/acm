#include <iostream>
#include <cstdio>
using namespace std;
int map[405][405];
void solve()
{
	int r,u;
	scanf("%d%d",&r,&u);
	for(int i = 0;i < r;i++)
		for(int j = 0;j < r;j++)
		{
			if(i == j)
				map[i][j] = 0;
			else
				map[i][j] = 50000000;
		}
	for(int i = 0;i < u;i++)
	{
		int K,L;
		scanf("%d%d",&K,&L);
		for(int j = 0;j < L;j++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			map[a][b] = map[b][a] = min(c,map[a][b]);
		}
	}
	for(int k = 0;k < r;k++)
		for(int i = 0;i < r;i++)
			for(int j = 0;j < r;j++)
				map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
	int q;
	scanf("%d",&q);
	for(int i = 0;i < q;i++)
	{
		char opt[10];
		scanf("%s",opt);
		if(opt[0] == 'a')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			map[a][b] = map[b][a] = min(map[a][b],c);
			for(int j = 0;j < r;j++)
				for(int k = 0;k < r;k++)
					map[k][j] = min(map[k][j],min(map[k][a] + map[b][j] + c,map[k][b] + map[a][j] + c));
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",(map[a][b] == 50000000) ? -1 : map[a][b]);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i = 1;i <= t;i++)
	{
		printf("Case :%d\n",i);
		solve();
	}
}

