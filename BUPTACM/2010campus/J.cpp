#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
using namespace std;
#include<stdio.h>
#include<string.h>
char q[1200000],p[1200000];
int next[1200000];
void getnext()
{
	int len=strlen(q),i,j,k=0,l;
	next[1]=0;
	for (l=2;l<=len;l++)
	{
		while (k>0&&q[k]!=q[l-1])k=next[k];
		if (q[k]==q[l-1])
		{
			k++;
		}
		next[l]=k;
	}
}
int kmp()
{
	int ans=0,i,n=strlen(p),m=strlen(q),l=0;
	getnext();
	for (i=0;i<n;i++)
	{
		while (l>0&&p[i]!=q[l])
{
			l=next[l];
}
		if (q[l]==p[i])l++;
		if (l==m)
		{
			ans++;
			return 1;
			l=next[l];
		}
	}
	return ans;
}
string ss[16],s[16];
char str[310000];
int dp[1<<16][16];
int a[16][16];
bool cmp(const string &x,const string &y)
{
	return x.length()<y.length();
}
int main()
{
	int i,j,k,n;
	while (scanf("%d",&n)!=EOF)
	{
		int sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%s",str);
			ss[i]=(string)str;
		}
		sort(ss,ss+n,cmp);
		int pp=0;
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
				strcpy(q,ss[i].c_str());
				strcpy(p,ss[j].c_str());
				if (kmp())break;
			}
			if (j==n)s[pp++]=ss[i];
		}
		n=pp;
		for (i=0;i<n;i++)
		{
			sum+=(int)s[i].length();
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (i==j)a[i][j]=0;
				else 
				{
					strcpy(q,s[j].c_str());
					strcat(q,s[i].c_str());
					int l=strlen(q);
					
					getnext();
					a[i][j]=next[l];
				}
			}
		}
		memset(dp,0,sizeof(dp));
		for (i=0;i<n;i++)
		{
			dp[1<<i][i]=0;
		}
		for (i=0;i<(1<<n);i++)
		{
			for (j=0;j<n;j++)
			{
				if (i&(1<<j))
				{
					for (k=0;k<n;k++)
					{
						if ((i&(1<<k)))continue;
						dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+a[j][k]);
					}
				}
			}
		}
		int ans=0;
		for (i=0;i<n;i++)
		{
			ans=max(ans,dp[(1<<n)-1][i]);
			//if (dp[(1<<n)-1][i]==3)printf("i=%d\n",i);
		}
		//printf("%d\n",ans);
		printf("%d\n",sum-ans);
	}
	return 0;
}

