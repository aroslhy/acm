//2012-09-12 19:40:37	Accepted	4287	62MS	4152K	1131 B	G++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5000+5, MAXM = 6+5;
int T, N, M;
int qur[MAXN], key[1<<8], cnt[1000000];
char dic[MAXM], test[MAXM];
int main()
{
    key['a'] = 2; key['b'] = 2; key['c'] = 2;
    key['d'] = 3; key['e'] = 3; key['f'] = 3;
    key['g'] = 4; key['h'] = 4; key['i'] = 4;
    key['j'] = 5; key['k'] = 5; key['l'] = 5;
    key['m'] = 6; key['n'] = 6; key['o'] = 6;
    key['p'] = 7; key['q'] = 7; key['r'] = 7; key['s'] = 7;
    key['t'] = 8; key['u'] = 8; key['v'] = 8;
    key['w'] = 9; key['x'] = 9; key['y'] = 9; key['z'] = 9;
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            scanf("%d", &qur[i]);
        for (int i = 0; i < M; i++)
        {
            scanf("%s", dic);
            int h = 0;
            for (int j = 0; dic[j]; j++)
                h = h*10+key[dic[j]];
            cnt[h]++;
        }
        for (int i = 0; i < N; i++)
            printf("%d\n", cnt[qur[i]]);
    }
    return 0;
}
