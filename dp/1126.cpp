#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int n;
int a[51];
int d[51][250001];

// x번째 사용할 차례, 현재 높이차이 dif
int dp(int x, int dif) {
	if (x == n) {
		if(dif == 0) return 0;
		else return -1e9;
	}
	if (dif > 250000) return -1e9;
	if (d[x][dif] != -1) return d[x][dif];
	d[x][dif] = dp(x + 1, dif);								// 사용하지 않은경우
	d[x][dif] = max(d[x][dif], dp(x + 1, dif + a[x]));		// 높은 탑에 쌓은경우
	int dx = a[x] < dif ? a[x] : dif;
	d[x][dif] = max(d[x][dif], dp(x + 1, abs(dif - a[x])) + dx);
	return d[x][dif];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(d, -1, sizeof(d));
	int ans = dp(0, 0);
	if (ans == 0)
		cout << "-1\n";
	else
		cout << ans << '\n';
	return 0;
}