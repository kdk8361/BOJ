#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n, m;
int a[51][51];
int t[51][51];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &t[i][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
			if (a[i][j] != t[i][j]) {
				ans += 1;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						int temp = !a[i + k][j + l];
						a[i + k][j + l] = temp;
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != t[i][j]) ans = -1;
		}
	}
	cout << ans << '\n';

	return 0;
}