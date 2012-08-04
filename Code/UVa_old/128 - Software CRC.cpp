#include<cstdio>
#include<cstring>
using namespace std;
const int MAXL = 1024+5;
char line[MAXL];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (fgets(line, MAXL, stdin))
	{
	    if (line[0] == '#') break;
	    int len = strlen(line)-1;
	    long long S = 0;
	    for (int i = 0; i < len; i++)
	        S = (256*S+line[i])%34943;
        S = (34943-((256*256*S)%34943))%34943;
//        printf("%d\n", S);
        char ans[4];
        for (int i = 0; i < 4; i++)
        {
            if (S%16 >= 10)
                ans[i] = 'A'+S%16-10;
            else
                ans[i] = '0'+S%16;
            S /= 16;
        }
        printf("%c%c %c%c\n", ans[3], ans[2], ans[1], ans[0]);
	}
	return 0;
}
