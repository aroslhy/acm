#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10005, MAXL = 20;
char dic[MAXN][MAXL], cnt_dic, che[MAXL];
struct Out {char str[MAXL];} out[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (cnt_dic = 0;; cnt_dic++)
    {
        scanf("%s", dic[cnt_dic]);
        if (dic[cnt_dic][0] == '#')
            break;
    }
    for (;;)
    {
        scanf("%s", che);
        if (che[0] == '#')
            break;
        int l = strlen(che);
        int cnt_out = 0;
        bool cor = 0;
        for (int i = 0; i < cnt_dic; i++)
        {
            int li = strlen(dic[i]);
            if (l - li == 0)
            {
                int cnt = 0;
                for (int j = 0; j < li; j++)
                    if (che[j] == dic[i][j])
                        cnt++;
                if (cnt == l)
                {
                    cor = 1;
                    break;
                }
                else if (cnt+1 == l)
                {
                    strcpy(out[cnt_out++].str, dic[i]);
                    continue;
                }
            }
            else if (l - li == -1)
            {
                int cnt = 0;
                for (int j = 0; j < li; j++)
                    if (che[cnt] == dic[i][j])
                        cnt++;
                if (cnt == l)
                {
                    strcpy(out[cnt_out++].str, dic[i]);
                    continue;
                }
            }
            else if (l - li == 1)
            {
                int cnt = 0;
                for (int j = 0; j < l; j++)
                    if (che[j] == dic[i][cnt])
                        cnt++;
                if (cnt == li)
                {
                    strcpy(out[cnt_out++].str, dic[i]);
                    continue;
                }
            }
        }
        if  (cor)
            printf("%s is correct", che);
        else
        {
            printf("%s:", che);
            for (int j = 0; j < cnt_out; j++)
                printf(" %s", out[j].str);
        }
        printf("\n");
    }
    return 0;
}
