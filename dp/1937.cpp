#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n;
int a[501][501];
// d[x][y][w] = x,y에서 w방향으로 갔을 때 최장 생존일
int d[501][501];
bool c[501][501];

// 상하좌우
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dp(int x, int y) {
	if (d[x][y] != 1) return d[x][y];
	d[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>n || ny>n) continue;
		if (a[nx][ny] > a[x][y]) {
			d[x][y] = max(d[x][y], dp(nx, ny) + 1);
		}
	}
	return d[x][y];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			d[i][j] = 1;
		}
	}
	memset(c, false, sizeof(c));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(d[i][j] == 1)
				ans = max(ans, dp(i, j));
		}
	}
	cout << ans << '\n';
	return 0;
}