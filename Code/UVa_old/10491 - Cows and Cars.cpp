#include<cstdio>
using namespace std;
double NCOWS, NCARS, NSHOW;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%lf%lf%lf", &NCOWS, &NCARS, &NSHOW) != EOF)
	    printf("%.5lf\n", (NCOWS*NCARS+NCARS*NCARS-NCARS)/(NCOWS+NCARS)/(NCOWS+NCARS-NSHOW-1));
	return 0;
}
