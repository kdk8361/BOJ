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

int i_size(long long a) {
	int cnt = 0;
	while (a > 0) {
		cnt++;
		a /= 10;
	}
	return cnt;
}

long long dp(long long a) {
	if (a <= 0) return 0;
	int k = i_size(a);
	long long tp = pow(10, k - 1);
	long long wp = k < 2 ? 0 : 25 * pow(100, (k - 2) / 2);
	long long ans = dp(a%tp) + int(a / tp);
	if (k % 2 == 0) {
		for (long long i = 1; i <= a / wp; i++) ans = min(ans, dp(a - i*wp) + i);
	}
	return ans;
}

int main() {
	int t;
	long long n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp(n) << '\n';

	}
	return 0;
}