#include<stdio.h>
int n,a[30]={1,2,2,4,6,6,8,10,14,20,26,34,46,62,78,102,134,176,226,302,408,528,678,904,1182,1540,2012,2606,3410,4462};
int main()
{
freopen("input.txt","r",stdin);
while(scanf("%d",&n)&&n)
printf("%d\n",a[n-1]);
return 0;
}
