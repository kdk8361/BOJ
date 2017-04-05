#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996) 
using namespace std;

string a, b;
int mod = 20150523;
int len;
int d[100001][3][2];
int p[100001];

int dp(int x, int s, int vs) {
	if (x == len) {
		if (s == 0) return 1;
		else return 0;
	}
	int nd = a[x] - '0';
	int& ans = d[x][s][vs];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i <= 9; i++) {
		int ns = vs || i < nd;
		if (!ns && i > nd) continue;
		if (i == 3 || i == 6 || i == 9) {
			if (ns) ans += p[len - 1 - x];
			else {
				int ta = 0;
				for (int t = x + 1; t < len; t++) ta = (ta * 10 + a[t] - '0') % mod;
				ta++;
				ans += ta;
			}
		}
		else ans += (dp(x + 1, (s + i) % 3, vs || i < nd) % mod);
		ans %= mod;
	}
	return ans;
}

int main()
{
	cin >> a >> b;
	int tp = 1;
	for (int i = 0; i <= 100000; i++) {
		tp %= mod;
		p[i] = tp;
		tp *= 10;
	}

	len = a.length();
	if (a[len - 1] != '0') a[len - 1] -= 1;
	else {
		a[len - 1] = '9';
		int temp = len - 2;
		while (a[temp] == '0' && temp >= 0) {
			a[temp] = '9';
			temp -= 1;
		}
		a[temp] -= 1;
	}

	memset(d, -1, sizeof(d));
	int lef = dp(0, 0, 0) % mod;

	a = b;

	memset(d, -1, sizeof(d));
	len = a.length();
	int righ = dp(0, 0, 0) % mod;

	cout << (righ - lef + mod) % mod << '\n';

	return 0;
}