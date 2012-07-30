#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 2000;
int n,k;
char s[maxn];
int  a[maxn],b[maxn];
int f[maxn][maxn];
int ssum[maxn],tsum[maxn];
inline void print(int x,int y)
{
	if(x<n&&f[x+1][y])
	{
	//	print(x+1,y);
		printf("1");
		print(x+1,y);
		return ;
	}
	if(y<n&&f[x][y+1])
	{
	//	print(x,y+1);
		printf("2");
		print(x,y+1);
		return ;
	}
}
int main()
{
	int i,j;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		//cin>>s;
		scanf("%s",s);
		for(i = 0;i<n;i++)
			a[i+1] = s[i]-'0';
		//cin>>s;
		scanf("%s",s);
		for(i = 0;i<n;i++)
			b[i+1] = s[i]-'0';
		memset(f,0,sizeof(f));
		memset(ssum,0,sizeof(ssum));
		memset(tsum,0,sizeof(tsum));
		for(i = 1;i<=n;i++)
			ssum[i] = ssum[i-1]+a[i],tsum[i] = tsum[i-1]+b[i];
		//f[0][0] = 1;
		if(abs(2*n-2*ssum[n]-2*tsum[n])>k)
		{
            printf("Poor Alice\n");
            continue;
        }
        else f[n][n] = 1;
		for(i = n;i>=0;i--)
			for(j = n;j>=0;j--)
				if(f[i][j])
				{
					if(j-1>=0&&abs(i+j-1-2*ssum[i]-2*tsum[j-1])<=k)
						f[i][j-1] = 1;
					if(i-1>=0&&abs(i+j-1-2*ssum[i-1]-2*tsum[j])<=k)
						f[i-1][j] = 1;
				}
		if(!f[0][0])
		{
			printf("Poor Alice\n");
			continue;
		}
		print(0,0);
		printf("\n");
	}
	return 0;
}
