
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int MV=200010;

struct point{
    int x,y,flag,id;
    bool operator<(const point& t)const{
        if(x!=t.x)return x<t.x;
        return flag < t.flag;
    }
}p[MV];

int y[MV], pos[MV];

int main(){
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int n, T;
    scanf("%d", &T);
    while(T--){
    	scanf("%d", &n);
        if(n==0)break;
        for( int i=0;i<n;i++){
            scanf("%d%d",&p[2*i].x,&p[2*i].y);
            p[2*i].flag=0;

            scanf("%d%d",&p[2*i+1].x,&p[2*i+1].y);
            p[2*i+1].flag=1;

            p[2*i].id=p[2*i+1].id=i;
        }
        n*=2;
        sort(p,p+n);

        int cnt=0;

        for(int i=0;i<n;i++){
            if(p[i].flag == 0){
                    pos[p[i].id] = lower_bound(y+1, y+1+cnt, p[i].y) - y ;
            } else {
                int tp = pos[p[i].id];
                if(tp > cnt)y[++cnt] = p[i].y;
                else y[tp] = min(y[tp], p[i].y);
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
