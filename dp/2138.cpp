#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n;
int a[100001];
int t[100001];
//d[n] = a[n], t[n]�� �����ϰ� ����� ���� �ּ� Ƚ��
int d[100001];

// x��° ����ġ�� ������. x-1,x,x+1 ���� bitmask�� ����
int dp(int x, int cur) {
	int f = cur >> 1;		// a[x-1]
	int s = cur & 1;		// a[x]
	int temp = 1e9;
	if (x == 1) {
		temp = dp(x + 1, a[x] << 1 + a[x + 1]);				// �ȴ���
		temp = min(temp, dp(x + 1, (!a[x] << 1) + !a[x + 1]) + 1);		//����
	}
	else if (x == n) {
		if (t[x - 1] == f && t[x] == s) {
			return 0;
		}
		else if (t[x - 1] == !f && t[x] == !s) {
			return 1;
		}
		else return 1e9;
	}
	else {
		if (t[x - 1] != f) {
			temp = min(temp, dp(x + 1, (!s << 1) + !a[x + 1]) + 1);		// ����
		}
		else {
			temp = min(temp, dp(x + 1, (s << 1) + a[x + 1]));					// �ȴ���
		}
	}
	d[x] = temp;
	return d[x];
}

int main() {
	cin >> n;
	/*
	v[0] = �״��
	v[1] = ��
	v[2] = ��
	v[3] = �޿�
	*/
	vector<int> v[4];
	v[0].push_back(0); v[1].push_back(0); v[2].push_back(0); v[3].push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &a[i]);
		for (int j = 0; j < 4; j++) {
			v[j].push_back(a[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &t[i]);
	}
	v[1][1] = !v[1][1];
	v[1][2] = !v[1][2];
	
	v[2][n - 1] = !v[2][n - 1];
	v[2][n] = !v[2][n];
	
	v[3][1] = !v[3][1];
	v[3][2] = !v[3][2];
	v[3][n - 1] = !v[3][n - 1];
	v[3][n] = !v[3][n];
	
	int cnt[4] = { 0,1,1,2 };
	for (int i = 1; i <= n - 2; i++) {
		for (int k = 0; k < 4; k++) {
			if (v[k][i] != t[i]) {
				cnt[k] += 1;
				v[k][i] = !v[k][i];
				v[k][i + 1] = !v[k][i + 1];
				v[k][i + 2] = !v[k][i + 2];
			}
		}
	}
	int result = 1e9;
	
	for (int k = 0; k < 4; k++) {
		if (v[k][n - 1] == t[n - 1] && v[k][n] == t[n])
			result = min(result, cnt[k]);
	}
	if (result == 1e9) result = -1;
	cout << result << '\n';
	/*int ans = dp(1, a[0] << 1 + a[1]);
	if (ans == 1e9) cout << "-1" << '\n';
	else cout << ans << '\n';*/
	return 0;
}