#include<cstdio>
#include<cctype>
using namespace std;
bool field[6][6];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int count = 0, ans = 17;
bool Goal()
{
	bool t = field[0][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (t != field[i][j])
				return 0;
	return 1;
}
void Flip(int x, int y)
{
	field[x][y] = !field[x][y];
	for (int i = 0; i < 4; i++)
		if (0 <= x+d[i][0] && x+d[i][0] < 4 && 0 <= y+d[i][1] && y+d[i][1] < 4)
			field[x+d[i][0]][y+d[i][1]] = !field[x+d[i][0]][y+d[i][1]];
}
void Search(int x)
{
	if (x >= 16)
	{
		if (Goal())
			ans = count < ans ? count : ans;
		return;
	}
	for (int k = 0; k < 2; k++)
	{
		if (k)
		{
			Flip(x/4, x%4);
			count++;
		}
		Search(x+1);
		if (k)
		{
			Flip(x/4, x%4);
			count--;
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			char t;
			do
				scanf("%c", &t);
			while (!isalpha(t));
			if (t == 'b')
				field[i][j] = 1;
			else if (t == 'w')
				field[i][j] = 0;
		}
	Search(0);
	if (ans <= 16)
		printf("%d\n", ans);
	else
		printf("Impossible\n");
	return 0;
}
