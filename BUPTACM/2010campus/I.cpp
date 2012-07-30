#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int p,t;
        scanf("%d%d",&p,&t);
        printf("%d\n",(p-1)/gcd(p-1,t));
    }
    return 0;
}

