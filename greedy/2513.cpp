#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

int n, k, s;
int a[100005];

int main() {
	cin >> n >> k >> s;
	int righ = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cin >> a[temp];
		righ = max(righ, temp);
	}
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < s;) {
		if (a[i] == 0) {
			i++; continue;
		}
		if (sum + a[i] >= k) {
			if (sum == 0) {
				ans += (a[i] / k)*(s - i) * 2;
				a[i] %= k;
			}
			else {
				a[i] = sum + a[i] - k;
				sum = 0;
			}
		}
		else {
			if (sum == 0) ans += (s - i) * 2;
			sum += a[i];
			a[i] = 0;
		}
	}
	sum = 0;
	for (int i = righ; i > s;) {
		if (a[i] == 0) {
			i--; continue;
		}
		if (sum + a[i] >= k) {
			if (sum == 0) {
				ans += (a[i] / k)*(i - s) * 2;
				a[i] %= k;
			}
			else {
				a[i] = sum + a[i] - k;
				sum = 0;
			}
		}
		else {
			if (sum == 0) ans += (i - s) * 2;
			sum += a[i];
			a[i] = 0;
		}
	}

	cout << ans << '\n';

	return 0;
}