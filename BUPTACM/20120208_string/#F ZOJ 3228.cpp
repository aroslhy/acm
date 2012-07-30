#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAX = 1e5+5, INF = 0x3f3f3f3f, MAXHASH = 10000;
int T, N, type;
char A[MAX], a[MAX];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; ; cas++)
    {
        if (scanf("%s%d", A, &N) == EOF) break;
        printf("Case %d\n", cas);
        for (int n = 1; n <= N; n++)
        {
            scanf("%d%s", &type, a);
            int lenA = strlen(A), lena = strlen(a);
            long long HA = 0, Ha = 0, h = 1;
            for (int i = 1; i < lena; i++)
                h *= 26;
            for (int i = 0; i < lena; i++)
                Ha = 26*Ha+(a[i]-'a');
            for (int i = 0; i < lena; i++)
                HA = 26*HA+(A[i]-'a');
            int ans = 0;
            if (!type)
            {
                for (int i = lena; i <= lenA; i++)
                {
                    if (HA == Ha) ans++;
                    HA = 26*(HA-h*(A[i-lena]-'a'))+(A[i]-'a');
                }
            }
            else
            {
                for (int i = lena; i <= lenA; )
                {
                    if (HA == Ha)
                    {
                        ans++;
                        HA = 0;
                        for (int j = 0; j < lena; j++)
                            HA = 26*HA+(A[i+j]-'a');
                        i += lena;
                    }
                    else
                    {
                        HA = 26*(HA-h*(A[i-lena]-'a'))+(A[i]-'a');
                        i++;
                    }
                }
            }
            printf("%d\n", ans);
        }
        printf("\n");
    }
    return 0;
}
