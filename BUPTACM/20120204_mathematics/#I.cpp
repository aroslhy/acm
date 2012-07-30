#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
long long N;
int prime[7610000];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int c = 0;
    for (int i = 2; i <= (1<<27); i++)
    {
        bool flag = 1;
        for (int j = 1; j <= c; j++)
            if (i%prime[j] == 0)
            {
                flag = 0;
                break;
            }
        if (flag) prime[++c] = i;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &N);
        bool flag = 1;
        for (long long i = 1; i*i <= N; i++)
        {
            if (N%(long long)prime[(int)i] == 0)
            {
                printf("%d\n", prime[(int)i]);
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("Prime\n");
    }
    return 0;
}
