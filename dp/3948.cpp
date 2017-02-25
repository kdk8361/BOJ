#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

long long t;
long long d[21];
long long c[21][21] = { 0, };

long long dp(int x) {
	if (d[x] != -1) return d[x];
	d[x] = 0;
	for (int i = 1; i <= x; i += 2) {
		d[x] += c[x - 1][i - 1] * dp(i - 1)*dp(x - i);
	}
	return d[x];
}

void combination() {
	c[0][0] = 1;
	for (int i = 1; i <= 20; i++) {
		c[i][0] = 1; c[i][i] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

int main() {
	cin >> t;
	memset(d, -1, sizeof(d));
	d[0] = d[1] = d[2] = 1;
	combination();
	/*for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			printf("%ld ", c[i][j]);
		}
		printf("\n");
	}*/
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else cout << 2*dp(n) << '\n';
	}
	return 0;
}