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

bool c[1000001];
int k;
string n;

int main() {
	cin >> n >> k;

	queue<string> q;

	int len = n.length();
	int ans = 0;
	if (len == 1 || (len == 2 && n[1] == '0')) ans = -1;
	else {
		q.push(n);
		while (!q.empty() && k > 0) {
			memset(c, false, sizeof(c));
			int size = q.size();
			for (int i = 0; i < size; i++) {
				string s = q.front();
				q.pop();
				string temp;
				for (int j = 0; j < len - 1; j++) {
					for (int l = j + 1; l < len; l++) {
						if (j == 0 && s[l] == '0') continue;
						temp = s;
						swap(temp[j], temp[l]);
						int a = stoi(temp);
						if (c[a]) continue;
						c[a] = true;
						q.push(temp);
					}
				}
			}
			k--;
		}
	}
	if (ans != -1) while (!q.empty()) { ans = max(ans, stoi(q.front())); q.pop(); }

	printf("%d\n", ans);


	return 0;
}