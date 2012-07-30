#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int M=100000007,Base=50000,lim=4;
int r[Base+10],dp[Base+10][5][5][5];
int h1,h2,h3,i;
int Min(int a,int b,int c){
	return min(a,min(b,c));
}
int tmp,t1,t2,t3;
void update(){
	tmp=Min(t1,t2,t3);
	if (t1-tmp<=lim&&t2-tmp<=lim&&t3-tmp<=lim)
    {
       dp[i+tmp][t1-tmp][t2-tmp][t3-tmp]+=dp[i][h1][h2][h3];
       if (dp[i+tmp][t1-tmp][t2-tmp][t3-tmp]>=M)
          dp[i+tmp][t1-tmp][t2-tmp][t3-tmp]-=M;
    }
}
void run(int x1,int x2,int x3,int y1,int y2,int y3){
	t1=h1+x1,t2=h2+x2,t3=h3+x3;
	if(y3==-1&&t1-t2==y1-y2) update();
	if(y2==-1&&t1-t3==y1-y3) update();
	if(y1==-1&&t2-t3==y2-y3) update();
	if(y1+1&&y2+1&&y3+1&&t1-t2==y1-y2&&t2-t3==y2-y3) update();
}
void solve(){
	run(2,2,0,0,0,-1);
	run(0,2,2,-1,0,0);
	run(1,2,1,1,2,1);
	run(1,2,1,1,1,1);
	run(3,1,0,2,1,-1);
	run(0,3,1,-1,2,1);
	run(0,1,3,-1,1,2);
	run(1,3,0,1,2,-1);
	run(1,1,2,1,1,2);
	run(2,1,1,1,1,1);
	run(3,1,0,3,1,-1);
	run(0,3,1,-1,3,1);
	run(1,3,0,0,0,-1);
	run(0,1,3,-1,0,0);
	run(2,1,1,2,1,1);
	run(1,1,2,1,1,1);
	run(1,3,0,1,3,-1);
	run(0,1,3,-1,1,3);
	run(3,1,0,0,0,-1);
	run(0,3,1,-1,0,0);
	run(1,2,1,1,1,0);
	run(2,2,0,1,2,-1);
	run(0,2,2,-1,1,2);
	run(1,2,1,1,2,2);
	run(2,2,0,2,1,-1);
	run(0,2,2,-1,2,1);
}
void init(){
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0]=1;
	for(i=0;i<=Base;i++){
		for(h1=0;h1<=lim;h1++)
			for(h2=0;h2<=lim;h2++)
				for(h3=0;h3<=lim;h3++){
					if(h1&&h2&&h3) continue;
                    if (dp[i][h1][h2][h3])
					solve();
				}
	}
	for(i=0;i<=Base;i++) r[i]=dp[i][0][0][0];
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",r[n]);
	}
	return 0;
}

