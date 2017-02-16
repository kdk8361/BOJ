#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning (disable:4996)
using namespace std;
int n;
int init[10001], pw[10001];

// d[i][j] = i번째 디스크를 돌릴 것이고 j번 돌아가있다.
int d[10001][10];
// i번째 디스크 - 할 때 코스트
int turn1[10] = { 0,9,8,7,6,5,4,3,2,1 };
// i번째 디스크 + 할 때 코스트
int turn2[10] = { 0,1,2,3,4,5,6,7,8,9 };

// a번째 디스크를 돌릴거고 b번 돌아가있다.
int dp(int a, int b)
{
	if (a == n) return 0;
	if (d[a][b] != -1) return d[a][b];

	int cur_state = (init[a] + b) % 10;
	int to = pw[a];
	for (int all = 0; all < 10; all++)
	{
		int from = (cur_state + all) % 10;
		int one = (to - from + 10) % 10;
		int cost = turn1[one] + turn2[all];
		cost += dp(a + 1, (b + all) % 10);
		if (d[a][b] == -1 || d[a][b] > cost)
			d[a][b] = cost;
	}
	return d[a][b];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &init[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &pw[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			d[i][j] = -1;
		}
	}
	printf("%d\n", dp(0, 0));
	return 0;
}