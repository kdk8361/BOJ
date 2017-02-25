#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
int main()
{
	int d = 0;		// 스택역할
	char ar[100001];
	scanf("%s", &ar);
	int len = strlen(ar);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (ar[i] == '(') {
			d += 1;
		}
		if (ar[i] == ')') {
			if (ar[i - 1] == '(') {
				d -= 1;
				ans += d;
			}
			else {
				d -= 1;
				ans += 1;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}