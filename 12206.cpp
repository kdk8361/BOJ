#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#pragma warning(disable:4996) 
using namespace std;

int t, n;

int s[10] = { 126,48,109,121,51,91,95,112,127,123 };
string sr[10] = { "1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011" };


/*
abcdefg
9 : 1111011 = 1 2 8 16 32 64   = 123
8 : 1111111 = 1 2 4 8 16 32 64 = 127
7 : 1110000 = 16 32 64         = 112
6 : 1011111 = 1 2 4 8 16 64    = 95
5 : 1011011 = 1 2 8 16 64      = 91
4 : 0110011 = 1 2 16 32        = 51
3 : 1111001 = 1 8 16 32 64     = 121
2 : 1101101 = 1 4 8 32 64      = 109
1 : 0110000 = 16 32            = 48
0 : 1111110 = 2 4 8 16 32 64   = 126
*/

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int a[6] = { 0, };
		cin >> n;
		int c[7] = { 0, };
		for (int j = 0; j < n; j++) {
			int temp;
			for (int k = 6; k >= 0; k--) {
				scanf("%1d", &temp);
				c[6 - k] |= temp;				//filter originated by input
				if (temp) a[j] += 1 << k;		//10진수화
			}
		}
		//if (!(i == 7 || i == 12 || i == 14 || i == 16 || i == 22 || i == 31 || i == 35 || i == 41 || i == 42 || i == 44 || i == 45 || i == 50 || i == 53 || i == 60 || i == 69 || i == 70 || i == 75 || i == 96)) continue;
		printf("Case #%d: ", i);

		int filter = 0;
		for (int j = 0; j < 7; j++) if (c[j]) filter += 1 << (6 - j);	//filter
		vector<int> tem(n);
		vector<pair<int, int>> q;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < n; k++) {
				tem[k] = s[(j - k + 10) % 10] ^ a[k];	//j부터 아래로 n개에서 input과 다른 segment를 확인
				tem[k] &= filter;						//결과를 filtering
			}
			bool er = true;
			for (int k = 1; k < n; k++) {
				if (tem[k] != tem[k - 1]) er = false;	//
			}
			if (er) q.push_back(make_pair(tem[0], j));
		}
		if (n == 1) {
			queue<int> res;
			for (int j = 0; j < 10; j++) {
				if ((a[0] ^ s[j] & filter) == 0) res.push(j);
			}
			if (res.size() == 1) {
				for (int j = 0; j < 7; j++) {
					if (c[j]) cout << sr[(res.front() - n + 10) % 10][j];
					else printf("0");
				}
				printf("\n");
			}
			else {
				printf("ERROR!\n");
			}
		}
		else {
			sort(q.begin(), q.end());
			int ori_filter = 0;
			for (int j = q[0].second; j > q[0].second - n; j--)
				ori_filter |= s[(j + 10) % 10];
			ori_filter = 127 - ori_filter;
			if ((ori_filter&s[(q[0].second - n + 10) % 10] & (127 - filter)))
				printf("ERROR!\n");
			else {
				if (q.size() == 1) {
					for (int j = 0; j < 7; j++) {
						if (c[j]) cout << sr[(q[0].second - n + 10) % 10][j];
						else printf("0");
					}
					printf("\n");
				}
				else {
					if (q[0].first == q[1].first) printf("ERROR!\n");
					else {
						for (int j = 0; j < 7; j++) {
							if (c[j]) cout << sr[(q[0].second - n + 10) % 10][j];
							else printf("0");
						}
						printf("\n");
					}
				}
			}
		}
	}


	return 0;
}