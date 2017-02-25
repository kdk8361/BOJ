#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n;
// d[i][j] = i번째 j가왔을 때 경우의 수 누적
int d[100000][3];

int main() {
	cin >> n;
	
	d[0][0] = 1;
	d[0][1] = 1;
	d[0][2] = 1;

	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
		d[i][1] = d[i - 1][0] + d[i - 1][2];
		d[i][2] = d[i - 1][0] + d[i - 1][1];
		for (int k = 0; k < 3; k++) {
			d[i][k] %= 9901;
		}
	}
	cout << (d[n - 1][0] + d[n - 1][1] + d[n - 1][2])%9901 << '\n';
	

	return 0;
}