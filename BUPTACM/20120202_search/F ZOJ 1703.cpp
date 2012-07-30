#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char T[5], board[4][10];
int r_x[4], r_o[4], c_x[4], c_o[4], d_x[2], d_o[2];
void add_x(int i, int j) //在(i,j)下x
{
    board[i][j] = 'x';
    if (i == j)
        d_x[0]++;
    if (i+j == 3)
        d_x[1]++;
    r_x[i]++;
    c_x[j]++;
}
void del_x(int i, int j) //撤销在(i,j)下x
{
    board[i][j] = '.';
    if (i == j)
        d_x[0]--;
    if (i+j == 3)
        d_x[1]--;
    r_x[i]--;
    c_x[j]--;
}
void add_o(int i, int j) //在(i,j)下o
{
    board[i][j] = 'o';
    if (i == j)
        d_o[0]++;
    if (i+j == 3)
        d_o[1]++;
    r_o[i]++;
    c_o[j]++;
}
void del_o(int i, int j) //撤销在(i,j)下o
{
    board[i][j] = '.';
    if (i == j)
        d_o[0]--;
    if (i+j == 3)
        d_o[1]--;
    r_o[i]--;
    c_o[j]--;
}
bool Search(int x) //Search(1)表示当前局面x走下一步，x是否必胜；Search(0)表示当前局面o走下一步，x是否必胜
{
    if (x)
    {
        int cnt = 0; //此时为x的回合，若存在某行x冲3，则x必胜
        for (int k = 0; k < 4; k++)
            if (r_x[k] == 3 && r_o[k] == 0)
                cnt++;
        for (int k = 0; k < 4; k++)
            if (c_x[k] == 3 && c_o[k] == 0)
                cnt++;
        for (int k = 0; k < 2; k++)
            if (d_x[k] == 3 && d_o[k] == 0)
                cnt++;
        if (cnt) return 1;
    }
    bool flag_o = 1; //在o的回合，存在一步o使x不能必胜时就为false，对于所有o的下法都有x必胜时，才true
    bool flag_x = 0; //在x的回合，只要存在x的下法使x必胜，就true
    int cnt_ = 0; //枚举过的合法下法的次数
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == '.' && flag_o && !flag_x)
            {
                cnt_++;
                if (x)
                {
                    add_x(i, j);
                    if (Search(0)) flag_x = 1;
                    del_x(i, j);
                }
                else
                {
                    add_o(i, j);
                    if (!Search(1)) flag_o = 0;
                    del_o(i, j);
                }
            }
    if (!cnt_) return 0; //cnt_为零则棋盘满了游戏结束，此时必为o的回合
    return x ? flag_x : flag_o;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (fgets(T, 5, stdin))
    {
        if (T[0] == '$') break;
        for (int i = 0; i < 4; i++)
            fgets(board[i], 10, stdin);
        memset(r_x, 0, sizeof(r_x));
        memset(r_o, 0, sizeof(r_o));
        memset(c_x, 0, sizeof(c_x));
        memset(c_o, 0, sizeof(c_o));
        memset(d_x, 0, sizeof(d_x));
        memset(d_o, 0, sizeof(d_o));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 'x')
                    add_x(i, j);
                if (board[i][j] == 'o')
                    add_o(i, j);
            }
        bool flag = 0; //为true则存在forced win下法
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (board[i][j] == '.' && !flag)
                {
                    add_x(i, j);
                    int cnt = 0; //记录4个x连成一条线的个数
                    for (int k = 0; k < 4; k++)
                        if (r_x[k] == 4) cnt++;
                    for (int k = 0; k < 4; k++)
                        if (c_x[k] == 4) cnt++;
                    for (int k = 0; k < 2; k++)
                        if (d_x[k] == 4) cnt++;
                    if (cnt || Search(0)) //cnt>0说明下完这一步后x就已经赢了，不需要再dfs
                        flag = 1, printf("(%d,%d)\n", i, j);
                    del_x(i, j);
                }
        if (!flag) printf("#####\n");
    }
    return 0;
}
