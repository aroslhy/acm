#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int cnt[50000];
void dfs(int step,int ans)
{
    int i;
    if(step==7)
    {
        cnt[ans]++;
        return;
    }
    for(i=1;i<=6;i++)
        dfs(step+1,ans+i);
    return;
}
int main()
{
    //freopen("data1.in","r",stdin);
    //freopen("data1.out","w",stdout);
    int sum=6*6*6*6*6*6*6,i;
    memset(cnt,0,sizeof cnt);
    dfs(0,0);
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        if(N<=6*7 && N>=7)
            printf("%.4lf\n",(double)cnt[N]/(double)sum);
        else printf("0.0000\n");
    }
}
