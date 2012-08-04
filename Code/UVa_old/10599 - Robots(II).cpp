#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int MAX = 100+5;
int T, row, col;
bool grid[MAX][MAX];
struct DP {int N, C;} dp[MAX][MAX];
void print_ans(int x, int y)
{
    if (x > row || y > col) return;
    if (grid[x][y])
    {
        printf(" %d", col*(x-1)+y);
        if (dp[x][y+1].N == dp[x][y].N-1)
            print_ans(x, y+1);
        else
            print_ans(x+1, y);
    }
    else if (dp[x][y].N == dp[x][y+1].N)
        print_ans(x, y+1);
    else
        print_ans(x+1, y);
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &row, &col))
	{
	    if (row == -1 && col == -1) break; T++;
	    memset(grid, 0, sizeof(grid));
	    int a, b;
	    while (scanf("%d%d", &a, &b))
	    {
	        if (!a && !b) break;
	        grid[a][b] = 1;
	    }
	    memset(dp, 0, sizeof(dp));
        for (int i = row; i >= 1; i--)
            for (int j = col; j >= 1; j--)
            {
                if (dp[i][j+1].N > dp[i+1][j].N)
                {
                    dp[i][j] = dp[i][j+1];
                    if (grid[i][j]) dp[i][j].N++;
                }
                else if (dp[i][j+1].N < dp[i+1][j].N)
                {
                    dp[i][j] = dp[i+1][j];
                    if (grid[i][j]) dp[i][j].N++;
                }
                else
                {
                    dp[i][j].N = dp[i][j+1].N;
                    if (grid[i][j]) dp[i][j].N++;
                    dp[i][j].C = dp[i][j+1].C+dp[i+1][j].C;
                    if (dp[i][j].N-1 == dp[i+1][j+1].N && grid[i][j] || dp[i][j].N == dp[i+1][j+1].N)
                        dp[i][j].C = dp[i][j].C-dp[i+1][j+1].C;
                }
                if (grid[i][j] && dp[i][j].N == 1) dp[i][j].C = 1;
//                printf("%d,%d:%d,%d\n", i, j, dp[i][j].N, dp[i][j].C);
            }
        printf("CASE#%d: ", T);
        printf("%d %d", dp[1][1].N, dp[1][1].C);
        print_ans(1, 1);
        printf("\n");
	}
	return 0;
}
