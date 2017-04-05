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
int lef[2001];
int righ[2001];
int d[2001][2001];

// left, right
int dp(int x, int y) {
	if (d[x][y] != -1) return d[x][y];
	if (x == n || y == n) return 0;
	int ans = 0;
	//왼쪽카드만
	ans = max(ans, dp(x + 1, y));
	//양쪽다
	ans = max(ans, dp(x + 1, y + 1));
	//오른쪽카드만
	if (lef[x] > righ[y]) ans = max(ans, dp(x, y + 1) + righ[y]);
	d[x][y] = ans;
	return d[x][y];
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> n;

	for (int i = 0; i < n; i++) cin >> lef[i];
	for (int i = 0; i < n; i++) cin >> righ[i];

	cout << dp(0, 0);

	return 0;
}