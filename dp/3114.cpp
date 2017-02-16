#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>


#pragma warning (disable:4996)
using namespace std;
int r, c;

int d[1501][1501] = { 0, };
// asum[i][j] = i행 1~j까지 app합
int asum[1501][1501] = { 0, };
// bsum[i][j] = j열 1~i까지 ban합
int bsum[1501][1501] = { 0, };

// 오른쪽, 아래, 오른쪽아래
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
// 오른쪽 = 오른쪽의 위바나나 x,y -> x,y+1 -> bsum(x-1,y+1)
// 아래 = 아래의 왼사과 x,y -> x+1,y -> asum(x+1,y-1)
// 대각선 = 대각선의 위바나나 + 왼사과 x,y -> x+1,y+1 -> bsum(x,y+1) + asum(x+1,y)
int bx[] = { -1,0,0 };
int by[] = { 1,0,1 };
int ax[] = { 0,1,1 };
int ay[] = { 0,-1,0 };
// 1,1 -> r,c
int dp(int x, int y) {
	if (x > r || y > c) return -1e9;
	if (x == r && y == c) return 0;

	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	int right = dp(x, y + 1) + bsum[x - 1][y + 1];
	int down = dp(x + 1, y) + asum[x + 1][y - 1];
	int diag = dp(x + 1, y + 1) + asum[x + 1][y] + bsum[x][y + 1];
	d[x][y] = max(max(right, down), diag);
	//for (int i = 0; i < 3; i++)
	//{
	//	int nx = x + dx[i];
	//	int ny = y + dy[i];
	//	
	//	d[x][y] = max(d[x][y], dp(nx, ny) + dx[i] * asum[x + ax[i]][x + ay[i]] + dy[i] * bsum[x + bx[i]][y + by[i]]);
	//	// 오른쪽 => d[x][y] = max(d[x][y], dp(x,y+1) + 0*asum[x][y] + 1*bsum[x-1][y+1]
	//	// 아래 => d[x][y] = max(d[x][y], dp(x+1,y) + 1*asum[x+1][y-1] + 0*bsum[x][y]
	//	// 대각선 => d[x][y] = max(d[x][y], dp(x+1,y+1) + 1*asum[x+1][y] + 1*bsum[x][y+1]
	//}
	return d[x][y];
}

int main(void)
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			int temp;
			scanf(" %c%d", &c, &temp);

			int app = 0, ban = 0;
			if (c == 'A')
				app = temp;
			else
				ban = temp;

			asum[i][j] += asum[i][j - 1] + app;
			bsum[i][j] += bsum[i - 1][j] + ban;
		}
	}
	memset(d, -1, sizeof(d));
	printf("%d\n", dp(1, 1));
	return 0;
}