//2012-10-16 12:28:39 	Accepted 	3662 	C++ 	670 	436 	Aros
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 1000+5;
const int MOD = 1000000007;
int N, M, K;
int pri[200], mark[MAXN], cnt;
int d[2][MAXN][1<<5];
map<int,int> prime, yin;
void init()
{
	int i,j;
	cnt=0;
	for(i=0;i<MAXN;i++)
		mark[i]=i;
	for(i=2;i<MAXN;i++)
	{
		if(mark[i]==i)
			pri[cnt++]=i;
		for(j=0;j<cnt&&pri[j]*i<MAXN;j++)
		{
			mark[pri[j]*i]=pri[j];
			if(i%pri[j]==0)
				break;
		}
	}
}
int find(int n)
{
	int i=0;
	for (map<int, int>::iterator it = prime.begin(); it != prime.end(); it++)
	{
		if(it->first==n)
		{
			return i;
		}
		i++;
	}
}
void Handle(int n)
{
	int i,j,nn;
	nn=n;
	for(i=0;i<cnt;i++)
	{
		if(nn%pri[i]==0)
		{
			int s=0;
			while(nn%pri[i]==0)
			{
				s++;
				nn/=pri[i];
			}
			prime[pri[i]]=s;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			int num=i;
			int ss=0;
			for(j=0;j<cnt&&pri[j]<=i;j++)
			{
				if(num%pri[j]==0)
				{
					int s=0;
					while(num%pri[j]==0)
					{
						s++;
						num/=pri[j];
					}
					if(s==prime[pri[j]])
						ss+=1<<find(pri[j]);
				}
			}
			yin[i]=ss;
		}
	}
}

int main()
{
	init();
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		prime.clear();
		yin.clear();
		Handle(M);
//		for (map<int, int>::iterator it = prime.begin(); it != prime.end(); it++)
//			printf("%d %d\n", it->first, it->second);
//		for (map<int, int>::iterator it = yin.begin(); it != yin.end(); it++)
//			printf("%d %d\n", it->first, it->second);
		int num = prime.size(), tot = (1<<num)-1;
//		printf("num = %d,tot=%d\n", num,tot);
		int s = 0, t = 1;
		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= tot; k++)
				d[t][j][k] = 0;
		d[t][0][0] = 1;
		for (int i = 0; i < K; i++)
		{
			swap(s, t);
			for (int j = 0; j <= N; j++)
				for (int k = 0; k <= tot; k++)
					d[t][j][k] = 0;
			for (int j = 0; j < N; j++)
				for (int k = 0; k <= tot; k++) if (d[s][j][k])
					for (map<int, int>::iterator it = yin.begin(); it != yin.end(); it++) if (j+it->first <= N)
						d[t][j+it->first][k|it->second] = (d[t][j+it->first][k|it->second]+d[s][j][k])%MOD;
//			for (int j = 0; j < N; j++)
//				for (int k = 0; k <= tot; k++) if (d[t][j][k])
//					printf("%d,%d,%d:%d\n", i+1, j, k, d[t][j][k]);
		}
		printf("%d\n", d[t][N][tot]);
	}
	return 0;
}
