#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, B, D, f, F;
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%d%d%d%d", &n, &B, &D, &f, &F) != EOF)
    {
        int ans = 1<<30;
        while (n--)
        {
            char line[200];
            scanf("%s", line);
            int t = 0;
            for (int i = 0; line[i] != '\0'; i++)
            {
                if (line[i] == 'A')
                    t += B+D+f;
                else if (line[i] == 'B')
                    t += 2*(B+D)+F;
                else
                    t += 3*(B+D)+2*F;
            }
            ans = min(ans, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
