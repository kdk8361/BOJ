#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n;
long long d[5001];

// n명이라 하고 자신이 0이면 1,3,5,,,,,,n-1명째와 악수가능 
// 짝수만큼 떨어져 있고 자신과 악수가능한 경우의 수는 n/2
int main() {
	cin >> n;
	n /= 2;
	d[0] = 1;			// 바로 옆이랑 연결되는 경우를 위해
	d[1] = 1;
	long long mod = 987654321;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i] += (d[j] % mod * d[i - j - 1] % mod) % mod;
			d[i] %= mod;
		}
	}
	cout << d[n] << '\n';
	return 0;
}