#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 1001;

int T, N, Ans;
int S[MaxN];
int vis[1024],cas;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cas++;
		Ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &S[i]);
		int cnt=0;
		int ans=0;
		while(cnt<N){
			int temp=0,ret=0,flag=-1;
			for(int i=0;i<N;i++){
				if(vis[i]<cas){
					if(flag==-1){
						flag=S[i];
						vis[i]=cas;
						ret=1;
                        cnt++;
					}else if(flag==S[i]){
						vis[i]=cas;
                        if(temp>=2){ret=0;}
                        ret++;
						temp=0;
						cnt++;
					}else{
						temp++;
					}
				}
			}
			ans=max(ret,ans);
		}
		printf("%d\n",ans);			
	}
	return 0;
}

