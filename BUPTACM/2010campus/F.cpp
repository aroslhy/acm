#include <iostream>

#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

const int maxn =1000; 

struct Task{

       int  p , pid , subid ,t; 

};

int N , M ;

vector<Task> list; 
bool cmp (Task a , Task b){ 
     if(a.p != b.p ){
        return a.p > b.p;
     }else if(a.pid != b.pid){
	return a.pid < b.pid; 
     }else{
     	return a.subid < b.subid;
     }
}
void solve(){
     sort(list.begin(),list.end() , cmp);
     int que[maxn];
     for(int i = 0; i < M ; i++){
          que[i] = 0; 
    }
     int p;
     for(int i = 0 ; i < list.size()  ;i  ++){
        //cout << " node " << list[i].pid << " " << list[i].subid << "  " <<list[i].p << " " << list[i].p << endl;	
	p = -1 ;        
	for(int j =  0 ; j  < M ; j++){
           if(p==-1 || que[j]<que[p])
              p = j;	
	}
	que[p] += list[i].t; 
     }
     p = -1 ;        
     for(int j =  0 ; j  < M ; j++){
           if(p==-1 || que[j] > que[p])
             p = j;	
     }
     cout << que[p] << endl;
}

int main(){

    int T;
    //freopen("data1.in","r",stdin);
   // freopen("data1.out","w",stdout);

    cin >> T ; 

    while(T--){

         cin>> N >> M;

         list.clear();

         for(int i = 0 ; i <  N ; i++){

             int n  , pri;

             cin >>n >> pri;

             for(int j = 0  ; j  < n ; j++){

  		Task tip;                   
 		cin >> tip.t;
	        tip.p = pri;
		tip.pid = i;
		tip.subid=j;
		list.push_back(tip);

             }  

         }
         solve();

    }

    return 0; 

}

