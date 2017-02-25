#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int n, k;
int d[12];
vector<int> ans;

int go(int x, int y) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	int temp1, temp2;
	int res;
	if (y > d[x]) return -1;
	if (x >= 3) {
		temp1 = d[x - 1];
		temp2 = d[x - 2];
		if (y > temp1 + temp2) {
			ans.push_back(3);
			res = go(x - 3, y - (temp1 + temp2));
		}
		else if (y > temp1) {
			ans.push_back(2);
			res = go(x - 2, y - temp1);
		}
		else {
			ans.push_back(1);
			res = go(x - 1, y);
		}
	}
	else if (x == 2) {
		temp1 = d[x - 1];
		if (y > temp1) {
			ans.push_back(2);
			res = go(x - 2, y - temp1);
		}
		else {
			ans.push_back(1);
			res = go(x - 1, y);
		}
	}
	else if (x == 1) {
		ans.push_back(1);
		return 0;
	}
	

	return 0;
}

int main() {
	cin >> n >> k;
	
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	if (k > d[n]) {
		printf("-1\n");
		return 0;
	}
	go(n, k);
	int size = ans.size();
	for (int i = 0; i < size-1; i++) {
		printf("%d+", ans[i]);
	}
	printf("%d\n", ans[size - 1]);

	return 0;
}