#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
int vis[10],ok;
void dfs(int ans,int step,int x)
{
    int i;
    if(step==8)
    {
        if(ans%x==0)
        {
            ok=1;
        }
        return;
    }
    for(i=1;i<=8;i++)if(!vis[i])
    {
        vis[i]=1;
        dfs(ans*10+a[i],step+1,x);
        vis[i]=0;
    }
    return;
}
int main()
{
    //freopen("data1.in","r",stdin);
    //freopen("data1.out","w",stdout);
    int T,x,i;
    for(cin>>T;T--;)
    {
        for(i=1;i<=8;i++)
            scanf("%d",&a[i]);
        scanf("%d",&x);
        memset(vis,0,sizeof vis);
        ok=0;
        for(i=1;i<=8;i++)if(a[i]!=0)
        {
            vis[i]=1;
            dfs(a[i],1,x);
            vis[i]=0;
        }
        if(ok)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
