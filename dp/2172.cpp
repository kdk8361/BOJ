#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int ar[21][21];
int N, L;
// d[n][x1][y1][x2][y2] = x1,y1 -> x2,y2로 가는 n길이의 팰린드롬 갯수
int d[21][21][21][21][21] = { 0, };
// dx, dy -> 12시부터 시계방향
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int dp(int n, int x1, int y1, int x2, int y2) {
	if (n > L || n < 1) return 0;
	if (x1<1 || y1<1 || x2<1 || y2<1 || x1>N || x2>N || y1>N || y2>N) return 0;
	if (ar[x1][y1] != ar[x2][y2]) return 0;
	if (d[n][x1][y1][x2][y2] != -1) return d[n][x1][y1][x2][y2];
	d[n][x1][y1][x2][y2] = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		for (int k = 0; k < 8; k++)
		{
			int nx2 = x2 + dx[k];
			int ny2 = y2 + dy[k];
			if (ar[nx1][ny1] == ar[nx2][ny2] && nx1 >= 1 && nx1 <= N && ny1 >= 1 && ny1 <= N && nx2 >= 1 && nx2 <= N && ny2 >= 1 && ny2 <= N)
			{
				d[n][x1][y1][x2][y2] += dp(n - 2, nx1, ny1, nx2, ny2);
			}
		}
	}
	return d[n][x1][y1][x2][y2];
}

int main()
{
	cin >> N >> L;
	memset(d, -1, sizeof(d));
	memset(ar, -1, sizeof(ar));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ar[i][j];
			d[1][i][j][i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 1 || ny >= 1 || nx <= N || ny <= N) {
					if(ar[i][j] == ar[nx][ny])
						d[2][i][j][nx][ny] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int l = 3; l <= L; l++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					for (int m = 1; m <= N; m++) {
						dp(l, i, j, k, m);
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int m = 1; m <= N; m++) {
					if (d[L][i][j][k][m] != -1)
						ans += d[L][i][j][k][m];
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}	