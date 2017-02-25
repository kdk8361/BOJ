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

// n���̶� �ϰ� �ڽ��� 0�̸� 1,3,5,,,,,,n-1��°�� �Ǽ����� 
// ¦����ŭ ������ �ְ� �ڽŰ� �Ǽ������� ����� ���� n/2
int main() {
	cin >> n;
	n /= 2;
	d[0] = 1;			// �ٷ� ���̶� ����Ǵ� ��츦 ����
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