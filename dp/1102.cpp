#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#pragma warning(disable:4996) 
using namespace std;

int n, p, len;
int a[17][17];
string s;
int d[65537];

vector<int> result;

int one_cnt(int x) {
	int cnt = 0;
	while (x > 0) {
		if (x & 1) cnt += 1;
		x >>= 1;
	}
	return cnt;
}

//key = 발전소 가동상태
int dp(int key) {
	int cnt = one_cnt(key);
	if (cnt >= p) return 0;
	if (d[key] != -1) return d[key];
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		//가동중인 발전기에서만 다른 발전기를 가동시킬 수 있으므로
		if (!(key&(1 << (len - 1 - i)))) continue;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			//가동하려는 발전기가 켜져있으면 pass
			if (key&(1 << (len - 1 - j))) continue;
			ans = min(ans, dp(key | (1 << (len - 1 - j))) + a[i][j]);
		}
	}
	d[key] = ans;
	return d[key];
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	cin >> s;
	cin >> p;
	len = s.length();
	int key = 0;
	for (int i = 0; i < len; i++) key += s[i] == 'Y' ? 1 << (len - 1 - i) : 0;

	int ans = dp(key);
	if (ans == 1e9) printf("-1\n", ans);
	else printf("%d\n", dp(key));

	return 0;
}