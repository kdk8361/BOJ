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
int a[31];
int t;
int d[31][45001];
char s[2] = { 'N','Y' };

int dp(int x, int sum) {
	if (d[x][sum] != -1) return d[x][sum];
	if (sum == 15000) return 1;
	if (x >= n) return 0;
	int ans = dp(x + 1, sum + a[x]);
	ans |= dp(x + 1, sum - a[x]);
	ans |= dp(x + 1, sum);
	d[x][sum] = ans;
	return d[x][sum];
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> t;
	while (t--) {
		int p;
		cin >> p;
		if (p > 15000) cout << s[0] << ' ';
		else cout << s[dp(0, 15000 + p)] << ' ';
	}

	return 0;
}