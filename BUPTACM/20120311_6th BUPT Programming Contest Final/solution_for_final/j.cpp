#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

#define ZERO 1e-8

struct POINT
{
	double x,y;
	void read(){scanf("%lf%lf", &x,&y);}
	void print() {printf("p : %.3lf %.3lf\n", x, y);}
};
struct LINE
{
	double a,b,c;
};
struct SEGMENT
{
	POINT s,e;
};
struct CIRCLE
{
	POINT c;
	double r;
};

CIRCLE cir;
int T;
SEGMENT edge[4];
POINT edgep[4];
double maxd;
POINT st, ed;

int sig(double tmp)
{
	if(fabs(tmp) < ZERO)
		return 0;
	return tmp > 0 ? 1 : -1;
}
double dist(POINT a ,POINT b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool issamep(POINT a, POINT b)
{
	return sig(a.x-b.x) == 0 && sig(a.y-b.y) == 0;
}
POINT move(POINT s, POINT e, double d)
{
	double dis = dist(s,e);
	POINT ret;
	ret.x = d/dis*(e.x-s.x) + s.x;
	ret.y = d/dis*(e.y-s.y) + s.y;
	return ret;
}
LINE makeline(POINT a, POINT b)
{
	LINE l;
	int sign = 1;
	l.a = b.y-a.y;
	if(sig(l.a) < 0)	sign = -1, l.a = sign*l.a;
	l.b = sign*(a.x-b.x);
	l.c = sign*(a.y*b.x-a.x*b.y);
	return l;
}
bool llcross(POINT &p, LINE l1, LINE l2)
{
	double d = l1.a*l2.b-l2.a*l1.b;
	if(sig(d) == 0)	return false;
	p.x = (l2.c*l1.b-l1.c*l2.b)/d;
	p.y = (l2.a*l1.c-l1.a*l2.c)/d;
	return true;
}
bool pins(POINT p, SEGMENT seg)
{
	return sig(p.x-min(seg.s.x, seg.e.x)) >= 0 &&
		   sig(p.x-max(seg.s.x, seg.e.x)) <= 0 &&
		   sig(p.y-min(seg.s.y, seg.e.y)) >= 0 &&
		   sig(p.y-max(seg.s.y, seg.e.y)) <= 0;
}
bool cross(POINT &p, POINT q, double k, SEGMENT s)
{
	LINE l,m;
	l.a = k, l.b = -1.0, l.c = q.y-k*q.x;
	m = makeline(s.s, s.e);
	if(llcross(p, l, m) && pins(p, s))
		return true;
	return false;
}
int gao()
{
	double dis = maxd;
	//ç¹æ®æåµï¼æ æç
	if(sig(ed.x-st.x) == 0)
	{
		if(sig(20-maxd) > 0)
		{
			cir.c.x = 2.5, cir.c.y = sig(maxd-10.0) > 0 ? 20.0-maxd : maxd;
			cir.r = min(2.5, min(10.0-cir.c.y, cir.c.y));
			return 1;
		}
		else
			return 0;
	}

	double k[2];
	k[0] = (ed.y-st.y)/(ed.x-st.x);
	k[1] = -k[0];
	int kidx = 0;
	int eidx = 1;
	POINT p;
	while(1)
	{
		for(int i = 0; i < 4; i++)
			if(((1<<i) & eidx) == 0 && cross(p, st, k[kidx%2], edge[i]))
			{
				eidx = 1<<i;
				break;
			}
//		p.print();
		double dd = dist(p, st);
		if(sig(dis - dd) <= 0)
		{
//			printf("dis = %.3lf\n", dis);
			cir.c = move(st, p, dis);
			cir.r = min(min(5.0-cir.c.x, cir.c.x), min(10.0-cir.c.y, cir.c.y));
			return 1;
		}
		else
		{
			if(eidx & 1)	return 0;
			dis -= dd;
			if(issamep(p, edgep[2]))
				st = p, eidx = 3;
			else if(issamep(p, edgep[3]))
				st = p, eidx = 6;
			else
			{
				st = p;
				kidx++;
			}
		}
	}
}
void init()
{
	st.x = 2.5, st.y = 0;
	edgep[0].x = 0.0, edgep[0].y = 0.0;
	edgep[1].x = 5.0, edgep[1].y = 0.0;
	edgep[2].x = 5.0, edgep[2].y = 10.0;
	edgep[3].x = 0.0, edgep[3].y = 10.0;
	for(int i = 0; i < 4; i++)
		edge[i].s = edgep[i],edge[i].e = edgep[(i+1)%4];
}
int main()
{
	scanf("%d", &T);
	init();
	while(T--)
	{
		scanf("%lf", &maxd);
		st.x=2.5,st.y = 0;
		ed.read();
		int ret = gao();
		if(ret)	printf("%.3lf %.3lf %.3lf\n", cir.c.x, cir.c.y, cir.r);
		else	printf("-1\n");
	}
	return 0;
}
