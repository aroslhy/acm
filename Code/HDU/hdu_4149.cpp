#include<cstdio>
using namespace std;
int T, x[9], y[9], m;
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%d%d%d%d%d", &y[1], &y[2], &y[3], &y[4], &y[5], &y[6], &y[7], &y[8], &y[0]);
        m = 0;
        int p = 0;
        for (int i = 0; ; i++)
        {
            p = p^(1<<i);
            for (int j = 0; j <= 8; j++)
                x[j] = y[j]^m;
            if (x[0] == x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8])
                break;
            else if ((x[0]&p) == ((x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8])&p))
                continue;
            m = m^(1<<i);
            for (int j = 0; j <= 8; j++)
                x[j] = y[j]^m;
            if (x[0] == x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8])
                break;
            else if ((x[0]&p) == ((x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8])&p))
                continue;
        }
        printf("%d\n", m);
    }
    return 0;
}
