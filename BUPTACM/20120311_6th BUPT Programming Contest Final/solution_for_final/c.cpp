#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<stack>
using namespace std;
typedef long long llong;
const double EPS=1e-9;
const double Pi=acos(-1.0);
int V[1010];
char st[1010];
int main()
{
    int i,N,T,Fst,Lst,Max;
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
          scanf("%d",&N);
          //cin.getline(st,1005);
		  getchar();
          Max=0;
          for (i=0;i<N;i++)
          {
              cin.getline(st,1005);
              V[i]=strlen(st);
              if (V[i]>Max)
                 Max=V[i];
          }
          Fst=-1;
          for (i=0;i<N;i++)
          {
              if (V[i]*2>=Max)
              {
                 Lst=i;
                 if (Fst<0)
                    Fst=i;
              }
          }
          printf("%d\n",Lst-Fst+1);
    }
    return 0;
}
