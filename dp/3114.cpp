#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>


#pragma warning (disable:4996)
using namespace std;
int r, c;

int d[1501][1501] = { 0, };
// asum[i][j] = i�� 1~j���� app��
int asum[1501][1501] = { 0, };
// bsum[i][j] = j�� 1~i���� ban��
int bsum[1501][1501] = { 0, };

// ������, �Ʒ�, �����ʾƷ�
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
// ������ = �������� ���ٳ��� x,y -> x,y+1 -> bsum(x-1,y+1)
// �Ʒ� = �Ʒ��� �޻�� x,y -> x+1,y -> asum(x+1,y-1)
// �밢�� = �밢���� ���ٳ��� + �޻�� x,y -> x+1,y+1 -> bsum(x,y+1) + asum(x+1,y)
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
	//	// ������ => d[x][y] = max(d[x][y], dp(x,y+1) + 0*asum[x][y] + 1*bsum[x-1][y+1]
	//	// �Ʒ� => d[x][y] = max(d[x][y], dp(x+1,y) + 1*asum[x+1][y-1] + 0*bsum[x][y]
	//	// �밢�� => d[x][y] = max(d[x][y], dp(x+1,y+1) + 1*asum[x+1][y] + 1*bsum[x][y+1]
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