//2012-08-16 21:06:48	Accepted	4374	218MS	7372K	1964 B	C++	Aros
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100+5, MAXM = 10000+5;
const int INF = 0x3f3f3f3f;
int N, M, X, T, scr[MAXN][MAXM], Sum[MAXN], d[MAXN][MAXM];
int front, rear;
struct Node
{
    int profit, pos;
    Node(){}
    Node(int a, int b)
    {
        profit = a; pos = b;
    }
} mq[MAXM];
bool operator < (const Node a, const Node b)
{
    return a.profit < b.profit;
}
int main()
{
    while (scanf("%d%d%d%d", &N, &M, &X, &T) != EOF)
    {
        for (int i = 1; i <= N; i++)
        {
            Sum[i] = 0;
            for (int j = 1; j <= M; j++)
            {
                scanf("%d", &scr[i][j]);
                Sum[i] += scr[i][j];
            }
        }
        for (int j = 1; j <= M; j++)
            d[0][j] = j == X ? 0 : -INF;
        for (int i = 1; i <= N; i++)
        {
            int sum = Sum[i];
            front = rear = 0;
            for (int j = 1; j <= M; j++)
            {
                while (rear > front && d[i-1][j]+sum > mq[rear-1].profit)
                    rear--;
                mq[rear++] = Node(d[i-1][j]+sum, j);
                while (j-mq[front].pos > T)
                    front++;
                sum -= scr[i][j];
                d[i][j] = mq[front].profit-sum;
            }
            sum = Sum[i];
            front = rear = 0;
            for (int j = M; j >= 1; j--)
            {
                while (rear > front && d[i-1][j]+sum > mq[rear-1].profit)
                    rear--;
                mq[rear++] = Node(d[i-1][j]+sum, j);
                while (mq[front].pos-j > T)
                    front++;
                sum -= scr[i][j];
                d[i][j] = max(d[i][j], mq[front].profit-sum);
            }
        }
        int ans = 0;
        for (int j = 1; j <= M; j++)
            ans = max(ans, d[N][j]);
        printf("%d\n", ans);
    }
    return 0;
}
