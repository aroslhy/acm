#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const double eps=1e-8;
const double pi=atan(1.0)*4;

double sqr(double x){
	return x*x;
}

struct Point{
	double x,y;
	int num;
	Point(double xx=0,double yy=0){
		x=xx;
		y=yy;
	}
	Point operator-(const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
	Point operator+(const Point &p)const{
		return Point(x+p.x,y+p.y);
	}
	double operator /(const Point &p)const{
		return x*p.y-y*p.x;
	}
	bool operator <(const Point &p)const{
		if(fabs(x-p.x)>eps)return x<p.x;else return y<p.y; 
	}
	double operator *(const Point &p)const{
		return x*p.x+y*p.y;
	}
	double len2(){
		return sqr(x)+sqr(y);
	}
}c1,c2,m,mid,a[4];

int sgn(double x){
	if(x<-eps)return -1;else if(x>eps)return 1;else return 0;
}

bool isSame(Point p1,Point p2){
	return fabs(p1.x-p2.x)<eps && fabs(p1.y-p2.y)<eps;
}

bool between(Point p0,Point p1,Point p2){
	if(sgn((p0-p1)*(p2-p1))<=0 || sgn((p0-p2)*(p1-p2))<=0)return false;
	//cout<<"yes"<<endl;
	return true;
}

double dis(Point p0,Point p1,Point p2){
	if(!between(p0,p1,p2))return min(sqrt((p0-p1).len2()),sqrt((p0-p2).len2()));
	return fabs((p1-p0)/(p2-p0))/sqrt((p1-p2).len2());
}

bool checkRec(Point a[],Point p){
	int now=0,temp;
	for(int i=0;i<=3;++i){
		temp=sgn((p-a[i])/(p-a[i+1]));
		//if(temp<0)return false;
		if(temp==0)continue;
		if(now!=0 && now!=temp)return false;
		now=temp;
	}
	return true;
}

void make(Point &p,double r){
	double temp=sqrt(p.len2()/sqr(r));
	p.x/=temp;
	p.y/=temp;
}

void solve(){
	scanf("%lf%lf%lf%lf%lf%lf",&c1.x,&c1.y,&c2.x,&c2.y,&m.x,&m.y);
	double temp,seta,r,d,d1,d2,mind;
	bool inRec;
	scanf("%lf%lf",&r,&d);
	mid=c2-c1;
	swap(mid.x,mid.y);
	mid.x=-mid.x;
	if(fabs(mid.x)<eps && fabs(mid.y)<eps)mid.x=1; 
	make(mid,r);
	a[0]=c1-mid;
	a[1]=c2-mid;
	a[2]=c2+mid;
	a[3]=c1+mid;
	a[4]=a[0];
	if(isSame(c1,c2))inRec=false;else inRec=checkRec(a,m);
	d1=sqrt((m-c1).len2());
	d2=sqrt((m-c2).len2());
	//cout<<d1<<" "<<d2<<endl;
	/*if(!isSame(c1,c2))*/mind=min(dis(m,a[0],a[1]),dis(m,a[2],a[3]));/*else mind=min(sqrt((m-a[1]).len2()),sqrt((m-a[2]).len2()));*/
	//cout<<mind<<endl;
	if(!inRec && d1>r+eps && d2>r+eps){
		mind=min(mind,fabs(r-d1));
		mind=min(mind,fabs(r-d2));
	}else if(!inRec){
		temp=min(d1,d2);
		mind=min(mind,r-temp);
	}
	//cout<<mind<<endl;
	if(mind-eps<d){
		printf("It is life.\n");
		return;
	}
	if(inRec || d1<r+eps || d2<r+eps){
		printf("%.2f\n",pi*d*2.0);
		return;
	}              
	if(between(m,a[0],a[3])){
		temp=min(d1,d2);
		seta=asin(r/temp)*2;
		printf("%.2f\n",seta*d*2.0);
		return;
	}
	seta=acos((c1-m)*(c2-m)/(d1*d2))+asin(r/d1)+asin(r/d2);
	//cout<<seta<<endl;
	printf("%.2f\n",seta*d*2.0);
}

int main(){
	int t,i=0;
	scanf("%d",&t);
	while(t-->0){
		//printf("Case %d: ",++i);
		solve();
	}
}
