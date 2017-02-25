#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n;
int a[1001];
// d[start][end] = start ~ end 사이에 건배할 수 있는 쌍의 최대 개수int d[1001][1001];
int d[1001][1001];

int dp(int s, int e) {
	if (s >= e) return 0;
	if (s >= n) return 0;
	int &ans = d[s][e];
	if (ans != -1) return ans;
	//printf("%d %d\n", s, e);
	ans = 0;
	for (int i = s + 1; i <= e; i++) {
		if (a[i] == a[s]) {
			ans = max(ans, 1 + dp(s + 1, i - 1) + dp(i + 1, e));
		}
		else
		{
			ans = max(ans, dp(s, i - 1) + dp(i, e));
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1])
			d[i][i + 1] = 1;
	}
	memset(d, -1, sizeof(d));
	dp(0, n - 1);

	cout << d[0][n - 1] << '\n';

	return 0;
}