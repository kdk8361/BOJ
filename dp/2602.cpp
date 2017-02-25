#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

string key;
string br[2];
int klen;
int len;
int d[101][2][21];
// ki = 다음에 사용해야 할 키 인덱스, x = index, y = 0 : dev or 1 : ang
int dp(int ki, int x, int y) {
	if (ki >= klen) return 1;
	if (x >= len) return 0;
	if (d[x][y][ki] != 0) return d[x][y][ki];
	int ans = 0;
	for (int i = x; i < len; i++)
	{
		if (br[y][i] == key[ki]) {
			ans += dp(ki + 1, i + 1, !y);
		}
	}
	d[x][y][ki] = ans;
	return d[x][y][ki];
}

int main() {
	cin >> key;
	cin >> br[0];
	cin >> br[1];
	klen = key.length();
	len = br[0].length();
	int ans = 0;
	
	ans += dp(0, 0, 0);
	ans += dp(0, 0, 1);
	

	cout << ans << '\n';
	return 0;
}