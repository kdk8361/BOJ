#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996) 
using namespace std;

int n;
string a[51];
int c[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {
	memset(c, -1, sizeof(c));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	c[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
			if (c[nx][ny] != -1) continue;
			if (nx == n - 1 && ny == n - 1) {
				printf("%d\n", c[x][y]);
				return 0;
			}
			if (a[nx][ny] == '1') {
				q.push_front(make_pair(nx, ny));
				c[nx][ny] = c[x][y];
			}
			else {
				q.push_back(make_pair(nx, ny));
				c[nx][ny] = c[x][y] + 1;
			}
		}

	}


	return 0;
}