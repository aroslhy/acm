#include <stdio.h>
#define mini(a,b) (a<b?a:b)
struct{
	int v,next;
}edge[20000];
int headg[20000],cost[20000],k[20000][3],mark[20000];
int edgeN;
void add(int u,int v){
	edge[edgeN].v=v;
	edge[edgeN].next=headg[u];
	headg[u]=edgeN++;
    return;
}
void dfs(int w){
	int delt,i,tmpv;
    mark[w]=1;
    k[w][2]=cost[w];
    k[w][0]=0;
    delt=0x3fffffff;
    for(i=headg[w];~i;i=edge[i].next){
	    if(mark[edge[i].v]) continue;
	    dfs(edge[i].v);
	    k[w][2]+=mini(mini(k[edge[i].v][0],k[edge[i].v][1]),k[edge[i].v][2]);
	    k[w][0]+=mini(k[edge[i].v][2],k[edge[i].v][1]);
	    if(k[w][0]>0x3fffffff) k[w][0]=0x3fffffff;
	    if((tmpv=k[edge[i].v][2]-mini(k[edge[i].v][2],k[edge[i].v][1]))<delt) delt=tmpv;
	}
	k[w][1]=k[w][0]+delt;
	return;
}
main(){
	int tot,n,m,i,u,v;
	while(~scanf("%d%d",&n,&m)){
    	for(i=0;i<n;i++){
	        scanf("%d",&cost[i]);
	        mark[i]=0;
	        headg[i]=-1;
    	}
    	edgeN=0;
    	while(m--){
			scanf("%d%d",&u,&v);
		    add(u-1,v-1);
		    add(v-1,u-1);
		}
    	tot=0;
    	for(i=0;i<n;i++){
		    if(mark[i]==0){
			    dfs(i);
			    tot+=mini(k[i][2],k[i][1]);
			}
		}
		printf("%d\n",tot);
    }
    return 0;
}

