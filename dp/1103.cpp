#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <stack>
#pragma warning(disable:4996) 
using namespace std;

int n, m;
string a[51];
int d[51][51];
bool c[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dp(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) return 0;
	if (c[x][y]) return 2e9;
	if (d[x][y] != -1) return d[x][y];
	if (a[x][y] == 'H') return 0;
	int ans = 0;
	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		ans = max(ans, dp(x + dx[i] * (a[x][y] - '0'), y + dy[i] * (a[x][y] - '0')) + 1);
	}
	d[x][y] = ans;
	c[x][y] = false;
	return d[x][y];
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = dp(0, 0);
	cout << (ans >= 2e9 ? -1 : ans) << '\n';

	return 0;
}