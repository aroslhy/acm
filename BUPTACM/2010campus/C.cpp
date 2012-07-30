#include <stdio.h>
#include <string.h>
#include <math.h>
struct cis
{
    int b,h,w,d;
    void read()
    {
        scanf("%d%d%d%d",&b,&h,&w,&d);
    }
    double calv(double _h)
    {
        return w*d*(_h-b);
    }
};
struct cis c[50050];
double maxh,minh;
int n,T,v;
int equal(double a,double b)
{
    if(fabs(a-b)<1e-6)
    return 1;
    else return 0;
}
double cal(double h)
{
    int i;
    double nowv=0;
    for (i=0;i<n;i++)
    {
        if(c[i].b<h)
        {
            if(c[i].b+c[i].h<h)
            nowv += c[i].calv(c[i].h+c[i].b);
            else
            nowv += c[i].calv(h);
        }
    }
    return nowv;
}
int ok(double h)
{
    int i;
    double nowv = cal(h);
    if(equal(nowv,v))
    return 0;
    if(nowv<v)
    return 1;
    else return 0;
}


double bsearch()
{
    int i,j;
    double l,r,mid;

    l = minh;
    r = maxh;
    while(r-l>1e-4)
    {
        mid = (r+l)*0.5;
        if(ok(mid))
        l = mid;
        else r = mid;
    }


    return mid;
}
int main()
{
    int i,j;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        maxh = -1;
        minh = 0x7fffffff;
        int sum=0;
        for (i=0;i<n;i++)
        {
            c[i].read();
            if(c[i].h+c[i].b>maxh)
            maxh = c[i].h+c[i].b;
            if(c[i].b<minh)
            minh = c[i].b;
            sum+=c[i].h*c[i].d*c[i].w;
        }
        scanf("%d",&v);
        if(v>sum)
        {
            printf("OVERFLOW\n");
            continue;
        }
        if(v==sum)
        {
            printf("%.2f\n",maxh);
            continue;
        }

        double ans = bsearch();
        printf("%.2f\n",ans);
    }
}

