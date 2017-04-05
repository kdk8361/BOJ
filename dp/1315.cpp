#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>

#pragma warning(disable:4996) 
using namespace std;

int n;
int s[101], in[101], p[101];
// d[s][in] = s, in���¿��� �� �� �ִ� �ִ� ����Ʈ ����
int d[1001][1001];
bool c[1001][1001];

int dp() {
	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			d[i][j] = 2 - i - j;
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (s[k] <= i || in[k] <= j) {
					d[i][j] += p[k];		// ������ i,j�� �� Ŭ���� ������ ����Ʈ���� ��� �߰������� ��.
					cnt++;
				}
			}
			c[i][j] = (i == j&&j == 1 || i > 1 && c[i - 1][j] && d[i - 1][j] > 0 || j > 1 && c[i][j - 1] && d[i][j - 1] > 0);
			if (c[i][j]) ans = max(ans, cnt);
		}
	}
	return ans;
}


int main()
{
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> in[i] >> p[i];
	cout << dp() << '\n';
	return 0;
}