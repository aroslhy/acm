#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000+5, MAXM = 1000+5;
int n, m, C;
vector<int> u[MAXM];
int b[MAXN];
int main()
{
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while (scanf("%d%d%d", &m, &n, &C) != EOF)
    {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= m; i++)
            u[i].clear();
        while (C--)
        {
            char cmd[5];
            scanf("%s", cmd);
            if (cmd[0] == 'B')
            {
                int ui, bi;
                scanf("%d%d", &ui, &bi);
                if (b[bi])
                    printf("The book is not in the library now\n");
                else if (u[ui].size() == 9)
                    printf("You are not allowed to borrow any more\n");
                else
                {
                    printf("Borrow success\n");
                    u[ui].push_back(bi);
                    b[bi] = ui;
                }
            }
            else if (cmd[0] == 'R')
            {
                int bi;
                scanf("%d", &bi);
                if (!b[bi])
                    printf("The book is already in the library\n");
                else
                {
                    printf("Return success\n");
                    for (int i = 0; i < (int)u[b[bi]].size(); i++)
                        if (u[b[bi]][i] == bi)
                        {
                            u[b[bi]].erase(u[b[bi]].begin()+i);
                            break;
                        }
                    b[bi] = 0;
                }
            }
            else if (cmd[0] == 'Q')
            {
                int ui;
                scanf("%d", &ui);
                if (!u[ui].size())
                    printf("Empty\n");
                else
                {
                    sort(u[ui].begin(), u[ui].end());
                    for (int i = 0; i < (int)u[ui].size(); i++)
                    {
                        printf("%d", u[ui][i]);
                        printf((i == (int)u[ui].size()-1) ? "\n" : " ");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}

