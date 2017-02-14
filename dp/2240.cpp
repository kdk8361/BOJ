#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#pragma warning (disable:4996)
using namespace std;

int a[1001][2] = { 0, };
int d[1001][2][31] = { 0, };
int t, w;
/*
d[n][l][cnt] = n번째에 l번째 나무 밑에서 얻을 수 있는 최대 자두갯수. 이동횟수는 cnt회
*/
int dp(int n, bool l, int cnt)
{
	if (n > t) return 0;
	if (cnt < 0) return 0;
	if (d[n][l][cnt]) return d[n][l][cnt];
	d[n][l][cnt] = max(dp(n + 1, !l, cnt - 1) + a[n][l], dp(n + 1, l, cnt) + a[n][l]);
	//printf("d[%d][%d][%d] = %d\n", n, l, cnt, d[n][l][cnt]);
	return d[n][l][cnt];
}

int main()
{
	cin >> t >> w;

	for (int i = 1; i <= t; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 1)
			a[i][0] = 1;
		else
			a[i][1] = 1;
	}
	/*for (int i = 1; i <= t; i++)
	{
	printf("%d %d\n", a[i][0], a[i][1]);
	}
	printf("\n\n");
	*/cout << dp(0, false, w);


	return 0;
}