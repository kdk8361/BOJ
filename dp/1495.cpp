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

int n, s, m;
int a[101];
bool d[101][1001];

int main() {
	memset(d, false, sizeof(d));
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	d[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j + a[i] <= m && d[i - 1][j + a[i]] == true)  d[i][j] = true;
			if (j - a[i] >= 0 && d[i - 1][j - a[i]] == true) d[i][j] = true;
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) if (d[n][i]) ans = max(ans, i);
	cout << ans << '\n';
	return 0;
}