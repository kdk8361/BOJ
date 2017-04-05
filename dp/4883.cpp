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

int n;
long long a[100001][3];
long long d[100001][3];

int main() {
	int cnt = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		d[1][0] = 2e13;	d[1][1] = a[1][1]; d[1][2] = a[1][1] + a[1][2];
		d[2][0] = d[1][1] + a[2][0]; d[2][1] = min(d[2][0], min(d[1][1], d[1][2])) + a[2][1]; d[2][2] = min(d[1][1], min(d[1][2], d[2][1])) + a[2][2];
		for (int i = 3; i <= n; i++) {
			d[i][0] = min(d[i - 1][0], d[i - 1][1]) + a[i][0];
			d[i][1] = min(d[i][0], min(d[i - 1][0], min(d[i - 1][1], d[i - 1][2]))) + a[i][1];
			d[i][2] = min(d[i][1], min(d[i - 1][1], d[i - 1][2])) + a[i][2];
		}
		cout << cnt << ". " << d[n][1] << '\n';
		cnt++;
	}
	return 0;
}