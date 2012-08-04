#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAXN = 50000+5;
char R[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%s", R) != EOF)
    {
        int len = strlen(R), m = -1;
        long long sum = 0;
        int c = R[0] == '-' ? -1 : 1;
        for (int i = 0; i < len; i++)
        {
            int x = 0;
            if (isdigit(R[i]))
                x = R[i]-'0';
            else if (isupper(R[i]))
                x = R[i]-'A'+10;
            else if (islower(R[i]))
                x = R[i]-'a'+36;
            sum += x*c;
            m = max(m, x);
        }
//        printf("sum = %lld\n", sum);
        bool flag = 0;
        for (int N = 2; N <= 62 && !flag; N++)
            if (!(sum%(N-1)) && N > m)
            {
                printf("%d\n", N);
                flag = 1;
            }
        if (!flag)
            printf("such number is impossible!\n");
    }
    return 0;
}
