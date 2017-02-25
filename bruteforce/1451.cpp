#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n, m;
int a[101][101];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	long long ans = 0;
	// 나뉘는 위치 i,j를 정한다.
	// i,j를 기점으로 직사각형 4개의 합을 구한다.
	//  1 2
	//  3 4
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
			for (int k = 0; k < i; k++) {
				for (int l = 0; l < j; l++) {
					sum1 += a[k][l];
				}
			}
			for (int k = 0; k < i; k++) {
				for (int l = j; l < m; l++) {
					sum2 += a[k][l];
				}
			}
			for (int k = i; k < n; k++) {
				for (int l = 0; l < j; l++) {
					sum3 += a[k][l];
				}
			}
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					sum4 += a[k][l];
				}
			}
			ans = max(ans, (sum1 + sum2)*sum3*sum4);
			ans = max(ans, (sum1 + sum3)*sum2*sum4);
			ans = max(ans, (sum2 + sum4)*sum1*sum3);
			ans = max(ans, (sum3 + sum4)*sum1*sum2);
			
			//printf("%d %d %d %d\n", sum1, sum2, sum3, sum4);
		}
	}
	
	// 세로로 세개 x1, x2
	for (int i = 1; i < m - 1; i++) {
		for (int j = i; j < m; j++) {
			long long sum1, sum2, sum3;
			sum1 = sum2 = sum3 = 0;
			for (int l = 0; l < n; l++) {
				for (int k = 0; k < i; k++) {
					sum1 += a[l][k];
				}
				for (int k = i; k < j; k++) {
					sum2 += a[l][k];
				}
				for (int k = j; k < m; k++) {
					sum3 += a[l][k];
				}
			}
			ans = max(ans, sum1*sum2*sum3);
		}
	}
	
	// 가로로 세개 y1, y2
	for (int i = 1; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			long long sum1, sum2, sum3;
			sum1 = sum2 = sum3 = 0;
			for (int l = 0; l < m; l++) {
				for (int k = 0; k < i; k++) {
					sum1 += a[k][l];
				}
				for (int k = i; k < j; k++) {
					sum2 += a[k][l];
				}
				for (int k = j; k < n; k++) {
					sum3 += a[k][l];
				}
			}
			ans = max(ans, sum1*sum2*sum3);
		 }
	}
	cout << ans << '\n';
	return 0;
}