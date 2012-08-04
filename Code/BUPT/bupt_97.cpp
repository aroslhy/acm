#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000+5;
int T, N, V;
struct Node
{
    int b, w, h, inout;
    Node(){}
    Node (int B, int W, int H, int InOut)
    {
        b = B; w = W; h = H; inout = InOut;
    }
} tank[2*MAXN];
bool cmp(const Node x, const Node y)
{
    return x.b < y.b;
}
int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            int B, W, H, D;
            scanf("%d%d%d%d", &B, &D, &W, &H);
            tank[i<<1] = Node(B, W, H, 1);
            tank[(i<<1)^1] = Node(B+D, W, H, -1);
        }
        scanf("%d", &V);
        sort(tank, tank+(N<<1), cmp);
        int A = 0, v = 0;
        double lv = tank[0].b;
        for (int i = 0; i < (N<<1)-1; i++)
        {
            A += tank[i].inout*(tank[i].w*tank[i].h);
            v += A*(tank[i+1].b-tank[i].b);
            lv += tank[i+1].b-tank[i].b;
            if (v >= V)
            {
                lv -= (v-V)/(double)A;
                break;
            }
        }
        if (v < V)
            printf("OVERFLOW\n");
        else
            printf("%.2f\n", lv);
    }
    return 0;
}
