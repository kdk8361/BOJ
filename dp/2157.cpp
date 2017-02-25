#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n, m, k;
// d[t][cnt] = t까지 cnt번 거쳐서 가는 점수의 최대치
int d[301][301];


int main() {
	cin >> n >> m >> k;
	memset(d, -1, sizeof(d));
	vector<pair<int, int> > v[301];
	while(k--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	// n에 cnt,score
	
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	d[1][1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int t = v[x].at(i).first;
			int sc = v[x].at(i).second;
			if (t > x) {
				if (d[t][cnt + 1] < d[x][cnt] + sc) {
					q.push(make_pair(t, cnt + 1));
					d[t][cnt + 1] = max(d[t][cnt + 1], d[x][cnt] + sc);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		ans = max(ans, d[n][i]);
	}
	cout << ans << '\n';
	return 0;
}