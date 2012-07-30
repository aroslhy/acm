#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char board[13][13];
int dir[8][2] =
{{-1,0},{0,-1},{-1,-1},{-1,1},
 {1,0}, {0,1}, {1,1},  {1,-1}};

char check(int x,int y)//ÃÃÂ¶ÃÂ·Â¶ÃÂ§ 
{
    return x >= 0 && x < 10 && y >= 0 && y < 10;    
}

int count(int x,int y)//ÃÃÂ¶ÃÃÂ»Â¸Ã¶ÃÃ¥ÃÃÂ¿ÃÂ²Â»Â¿ÃÃÃÃÃ»ÃÂ§ 
{
    if(board[x][y] == '.')  return 0;
    for(int i = 0; i < 4; i++)
    {
        int tmp = 0;
        int nx = x + dir[i][0], ny = y + dir[i][1];    
        while(check(nx, ny) && board[nx][ny] == board[x][y])
        {
            tmp++;
            nx += dir[i][0];    
            ny += dir[i][1];
        }
        
        nx = x + dir[i + 4][0], ny = y + dir[i + 4][1];
        while(check(nx, ny) && board[nx][ny] == board[x][y])
        {
            tmp++;
            nx += dir[i + 4][0];    
            ny += dir[i + 4][1];
        }
        
        if(tmp >= 4)    return 1;
    }    
    
    return 0;
}

int count()//Â¼ÃÃÃ£ÃÃ»Â¸Ã¶ÃÃ¥ÃÃÂ¿ÃÃÃÃÃ»ÃÂ§ÂµÃÃÃ¥ÃÃÃÃ½ 
{
    int ans = 0;
    for(int i = 0; i < 10; i++)    
        for(int j = 0; j < 10; j++)
            ans += count(i, j);
            
    return ans;
}

pair<int,int>q[110];
char inq[11][11];
int solve(int xx,int yy)//Â¼ÃÃÃ£ÃÃÂ¶Â¯(xx,yy)Â¿ÃÃÃÂ»Ã±ÂµÃÂµÃÃÃ®Â¶Ã Â·ÃÃÃ½ 
{
    int ans = 0;
    char c = board[xx][yy];
    board[xx][yy] = '.';
    memset(inq, 0, sizeof(inq));
    int tail = 0;
    q[tail++] = make_pair(xx, yy);
    inq[xx][yy] = 1;
    for(int head = 0; head < tail; head++)
    {
        int x = q[head].first, y = q[head].second;    
        board[x][y] = c;
        ans = max(ans, count());
        board[x][y] = '.'; 
        for(int i = 0; i < 2; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];    
            if(check(nx,ny)&&board[nx][ny]=='.'&&inq[nx][ny]==0)
            {
                inq[nx][ny] = 1;  
                q[tail++] = make_pair(nx,ny);  
            }
            
            nx = x + dir[i + 4][0], ny = y + dir[i + 4][1];
            if(check(nx,ny)&&board[nx][ny]=='.'&&inq[nx][ny]==0)
            {
                inq[nx][ny] = 1;  
                q[tail++] = make_pair(nx,ny);  
            }
        }
    }
    
    board[xx][yy] = c;
    return ans;
}

int max_move()//ÃÂ¶Â¾ÃÃÃÂ¶Â¯ÂµÃÃÃ¥ÃÃÂ£Â¬Â¼ÃÃÃ£ÃÃ®Â¶Ã ÂµÃÂµÃÂ·Ã 
{
    int ans = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(board[i][j] != '.')
                ans = max(ans, solve(i,j));
            
    return ans;    
}

int main()
{
    //freopen("data1.in", "r", stdin);
    //freopen("data1.out", "w", stdout);
    
    int start = clock();
    char cas = 0;
    while(scanf("%s", board[0]) == 1)
    {
        if(cas) puts("");
        printf("Case #%d: ", ++cas);
        for(int i = 1; i < 10; i++)
            scanf("%s", board[i]);    
         
        if(count() > 0)
        {
            puts("Waiting!");
            continue;    
        } 
        
	
        printf("%d\n", max_move());
    }
   // printf("time = %d\n", clock() - start);
    return 0;    
}
