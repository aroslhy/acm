//2012-08-22 17:40:01	Accepted	4021	78MS	268K	2389 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000+5;
const int INF = 0x3f3f3f3f;
int T, t[2][24], cnt[2], lz[2];
vector<int> brd[2][2];
int main()
{
//    freopen("onlinejudge.in", "r", stdin);
//    freopen("onlinejudge.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        for (int j = 0; j < 2; j++)
        {
            brd[j][0].clear(); brd[j][1].clear();
            cnt[j] = 0;
            for (int i = 0; i < 24; i++)
                scanf("%d", &t[j][i]);
            if (t[j][0] == 0)
                swap(t[j][0], t[j][3]);
            else if (t[j][2] == 0)
                swap(t[j][2], t[j][3]);
            else if (t[j][1] == 0)
                swap(t[j][1], t[j][6]);
            else if (t[j][7] == 0)
                swap(t[j][7], t[j][6]);
            else if (t[j][16] == 0)
                swap(t[j][16], t[j][17]);
            else if (t[j][22] == 0)
                swap(t[j][22], t[j][17]);
            else if (t[j][21] == 0)
                swap(t[j][21], t[j][20]);
            else if (t[j][23] == 0)
                swap(t[j][23], t[j][20]);
            for (int i = 0; i < 24; i++)
            {
                if (i == 0 || i == 1 || i == 2 || i == 7 || i == 16 || i == 21 || i == 22 || i == 23)
                    brd[j][0].push_back(t[j][i]);
                else if (t[j][i] == 0)
                {
                    if (3 <= i && i <= 6)
                        lz[j] = 0;
                    else if (8 <= i && i <= 11)
                        lz[j] = 1;
                    else if (12 <= i && i <= 15)
                        lz[j] = 2;
                    else if (17 <= i && i <= 20)
                        lz[j] = 3;
                }
                else
                {
                    for (int k = 0; k < (int)brd[j][1].size(); k++)
                        if (brd[j][1][k] > t[j][i])
                            cnt[j]++;
                    brd[j][1].push_back(t[j][i]);
                }
            }
        }
        bool flag = ((cnt[0]+lz[0])%2 == (cnt[1]+lz[1])%2);
        for (int i = 0; i < 8 && flag; i++)
            if (brd[0][0][i] != brd[1][0][i])
                flag = 0;
        printf("%s\n", !flag ? "Y" : "N");
    }
    return 0;
}
