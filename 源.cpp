#include <stdio.h>
#include <string.h>

#define Maxin 75
int minstep, w, h, to[4][2] = { { -1, 0 }, { 1, 0 },{0, -1}, { 0, 1 } };//上下左右四个方向
char board[Maxin + 2][Maxin + 2];//储存卡片状态
bool mark[Maxin + 2][Maxin + 2];//标记该处是否已被经过

void Search(int nowx, int nowy, int endx, int endy, int step,int f)
{
	if (step > minstep) return;
	if (nowx == endx && nowy == endy){
		if (minstep > step)
			minstep = step;
		return;
	}

	for (int i = 0; i < 4; i++){
		int x = nowx + to[i][0];
		int y = nowy + to[i][1];

		if ((x > -1) && (x<h + 2) && (y>-1) && (y < w + 2)
			&& (
			((board[x][y] == ' ') && (mark[x][y] == false))
			|| ((x == endx) && (y == endy) && (board[x][y] == 'x'))
				)){
			mark[x][y] = true;
			if (f == i)
				Search(x, y, endx, endy, step, i);
			else
				Search(x, y, endx, endy, step+1, i);
			mark[x][y] = false; 
		}
	}

}

int main()
{
	scanf_s("%d %d", &w, &h);

	int i, j;
	for (i = 0; i < Maxin + 2; i++)board[0][i] = board[i][0] = ' ';
	for (i = 1; i <= h; i++){
		getchar();
		for (j = 1; j <= w; j++)board[i][j] = getchar();
	}
	for (i = 0; i <= w; i++)
		board[h + 1][i + 1] = ' ';
	for (i = 0; i <= w; i++)
		board[i + 1][w + 1] = ' ';

	int beginx, beginy, endx, endy, count = 0;
	while (scanf_s("%d %d %d %d", &beginx, &beginy, &endx, &endy) && beginx>0)
	{
		memset(mark, false, sizeof(mark));
		count++;
		minstep = 5000;
		Search(beginx, beginy, endx, endy, 0, -1);
		if (minstep < 5000)
			printf("No%d: %d\n\n", count, minstep);
		else
			printf("No%d: impossible\n\n", count);
	}
	getchar();
	return 0;
}