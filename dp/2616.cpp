#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n, k;
int a[50001];
// d[n][i] = n�� ����������� i������ �� �� ������ ��
int d[3][50000];

int dp(int m, int x) {
	if (m >= 3) return 0;
	if (x > n) return 0;
	if (x > n - k + 1) return 0;
	if (d[m][x] != -1) return d[m][x];
	// x���� ����
	d[m][x] = dp(m + 1, x + k);
	for (int i = 0; i < k; i++) d[m][x] += a[x + i];
	// �����ʰ� �ǳʶڴ�
	d[m][x] = max(d[m][x], dp(m, x + 1));
	return d[m][x];
}

int main() {
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	int ans = dp(0, 0);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) printf("%d ", d[j][i]);
		printf("\n");
	}*/
	cout << ans << '\n';
	return 0;
}