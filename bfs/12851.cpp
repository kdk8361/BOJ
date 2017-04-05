#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>
#include <queue>
#include <vector>

#pragma warning(disable:4996) 
using namespace std;

int n, k;
bool c[100001];
int d[100001];

int f(int a, int b) {
	if (b == 0) return (a + 1);
	else if (b == 1) return (a - 1);
	else return (a * 2);
}

int main()
{
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	int ans = 2e9, cnt = 0;
	bool found = false;
	if (n == k) {
		printf("0\n1\n");
		return 0;
	}
	else {
		while (!q.empty()) {

			int size = q.size();
			for (int j = 0; j < size; j++) {
				int x = q.front();
				q.pop();
				c[x] = true;
				if (x == k) {
					ans = min(ans, cnt);
					d[cnt]++;
				}
				for (int i = 0; i < 3; i++) {
					int nx = f(x, i);
					if (nx > 100000 || nx < 0) continue;
					if (c[nx] == true) continue;
					q.push(nx);
				}
			}
			cnt++;
		}
	}
	printf("%d\n%d\n", ans, d[ans]);
	return 0;
}