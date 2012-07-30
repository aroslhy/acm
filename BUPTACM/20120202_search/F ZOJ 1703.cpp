#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char T[5], board[4][10];
int r_x[4], r_o[4], c_x[4], c_o[4], d_x[2], d_o[2];
void add_x(int i, int j) //��(i,j)��x
{
    board[i][j] = 'x';
    if (i == j)
        d_x[0]++;
    if (i+j == 3)
        d_x[1]++;
    r_x[i]++;
    c_x[j]++;
}
void del_x(int i, int j) //������(i,j)��x
{
    board[i][j] = '.';
    if (i == j)
        d_x[0]--;
    if (i+j == 3)
        d_x[1]--;
    r_x[i]--;
    c_x[j]--;
}
void add_o(int i, int j) //��(i,j)��o
{
    board[i][j] = 'o';
    if (i == j)
        d_o[0]++;
    if (i+j == 3)
        d_o[1]++;
    r_o[i]++;
    c_o[j]++;
}
void del_o(int i, int j) //������(i,j)��o
{
    board[i][j] = '.';
    if (i == j)
        d_o[0]--;
    if (i+j == 3)
        d_o[1]--;
    r_o[i]--;
    c_o[j]--;
}
bool Search(int x) //Search(1)��ʾ��ǰ����x����һ����x�Ƿ��ʤ��Search(0)��ʾ��ǰ����o����һ����x�Ƿ��ʤ
{
    if (x)
    {
        int cnt = 0; //��ʱΪx�Ļغϣ�������ĳ��x��3����x��ʤ
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
    bool flag_o = 1; //��o�Ļغϣ�����һ��oʹx���ܱ�ʤʱ��Ϊfalse����������o���·�����x��ʤʱ����true
    bool flag_x = 0; //��x�Ļغϣ�ֻҪ����x���·�ʹx��ʤ����true
    int cnt_ = 0; //ö�ٹ��ĺϷ��·��Ĵ���
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
    if (!cnt_) return 0; //cnt_Ϊ��������������Ϸ��������ʱ��Ϊo�Ļغ�
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
        bool flag = 0; //Ϊtrue�����forced win�·�
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (board[i][j] == '.' && !flag)
                {
                    add_x(i, j);
                    int cnt = 0; //��¼4��x����һ���ߵĸ���
                    for (int k = 0; k < 4; k++)
                        if (r_x[k] == 4) cnt++;
                    for (int k = 0; k < 4; k++)
                        if (c_x[k] == 4) cnt++;
                    for (int k = 0; k < 2; k++)
                        if (d_x[k] == 4) cnt++;
                    if (cnt || Search(0)) //cnt>0˵��������һ����x���Ѿ�Ӯ�ˣ�����Ҫ��dfs
                        flag = 1, printf("(%d,%d)\n", i, j);
                    del_x(i, j);
                }
        if (!flag) printf("#####\n");
    }
    return 0;
}
